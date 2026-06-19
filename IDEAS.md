# Project Ideas & Brainstorming

## Re-Architecture & Pivoting
- **Vulkan/Modern OpenGL Port**: Given the deprecated nature of fixed-function pipelines, the entire `DisplayOutput/Renderer/` should be rewritten targeting OpenGL 4.5+ Core Profile or Vulkan to enable ultra-high resolutions (4k/8k) natively with lower CPU overhead.
- **Async Networking**: Migrate `ContentDownloader/` from synchronous `libcurl` calls to `Boost.Asio` or HTTP/2 async downloading to improve throughput and prevent application stutter during high-bandwidth fetches.

## Feature Expansion
- **HUD Overhaul**: Add comprehensive stats to `Client/Hud.cpp`:
  - Current sheep generation ID, hash, and author.
  - Active render duration / playback frame rate metrics.
  - Overall server status / connectivity ping logic.
  - Smooth animation transitions between the text visibility logic (`m_bVisible`).
- **Interactive UI Overlay**: Currently, settings require a separate wxWidgets binary. Consider embedding an immediate-mode GUI like `Dear ImGui` directly into the `electricsheep` rendering pipeline for real-time configuration without restarting.

### Dear ImGui Integration Research (RendererGL)
- The legacy `DisplayOutput/OpenGL/RendererGL.cpp` initializes OpenGL contexts via `glXCreateNewContext` / `wglCreateContext`.
- `Dear ImGui` provides standard backends (`imgui_impl_opengl2.cpp` for legacy fixed-pipeline or `imgui_impl_opengl3.cpp` for modern). Since the current application relies on GLee and older ARB paradigms, `imgui_impl_opengl2.cpp` is the most direct path forward.
- **Steps to integrate natively**:
  1. Add ImGui core files (`imgui.cpp`, `imgui_draw.cpp`, `imgui_widgets.cpp`, `imgui_tables.cpp`) into `DisplayOutput/`.
  2. In `RendererGL::Initialize()`, append `ImGui::CreateContext()` and `ImGui_ImplOpenGL2_Init()`.
  3. Inside the `RendererGL::EndFrame()` or the main loop's render sequence (before buffer swapping), inject `ImGui_ImplOpenGL2_NewFrame()`, `ImGui::NewFrame()`, and the ImGui render data generation.
  4. Ensure input events (mouse/keyboard) collected in `DisplayGL::GetEvent()` are forwarded to `ImGui_ImplX11` or `ImGui_ImplWin32` input handlers.

### Phase 3 Networking Modernization Scoping
- **Clarification**: I researched `Networking/Networking.cpp` and determined that `CCurlTransfer::Perform` already utilizes `curl_multi_perform` inside an `InterruptiblePerform()` loop wrapper.
- **Path Forward**: Given that curl operations are already wrapped in `curl_multi_fdset` selects, the networking stack's core bottleneck may actually be inside `ContentDownloader/SheepDownloader.cpp` and `SheepGenerator.cpp` where massive multi-megabyte XML/AVI payloads block via threading sleeps (`boost::thread::sleep`) when `curl_multi` fails. The architecture should be shifted from custom threaded wait states to native `Boost.Asio` or purely event-driven libcurl multi-handles globally.
- Wait blocks inside `ContentDownloader/SheepDownloader.cpp::findSheepToDownload()` and `ContentDownloader/SheepGenerator.cpp::ThreadFunction()` actively stall the client thread. We need to decouple the network polling loops into an independent thread pool or event-driven model using `boost::thread` or `boost::asio::deadline_timer` instead of `boost::thread::sleep` on the calling context.
- `ContentDownloader::SheepDownloader::findSheepToDownload()` acts as the entry point thread executing continuous network checks inside a massive `while(1)` block. It's invoked via `m_gDownloadThread = new boost::thread( boost::bind( &SheepDownloader::shepherdCallback, m_gDownloader ) );` in `ContentDownloader.cpp`.

## Phase 2: UI Overhaul Implementation Plan
- **Framework Choice**: Dear ImGui
  - **Why**: Immediate-mode GUI fits perfectly within a 60fps render loop like a screensaver. It has zero external dependencies, compiles fast, and integrates seamlessly into raw OpenGL contexts without needing a massive toolkit like Qt or rewriting the app for wxWidgets.
- **Rendering Approach**:
  - Start with `imgui_impl_opengl2.cpp` for the initial migration, given the project currently relies heavily on legacy fixed-function pipeline mechanics (`glBegin`, `glEnd`, `GLee.c`).
  - ImGui commands will be injected directly into `RendererGL::EndFrame()` or right before `glXSwapBuffers` in the main loop to overlay the screensaver visuals.
- **Migration Path**:
  1. **Submodule Integration**: Add Dear ImGui as a git submodule to `Dependencies/imgui` (or just check the source files in directly to avoid submodule complexity for a C++03 project).
  2. **Build System Hookup**: Update `Client/CMakeLists.txt` to compile `imgui.cpp`, `imgui_draw.cpp`, `imgui_tables.cpp`, `imgui_widgets.cpp`, and the backend implementations `imgui_impl_opengl2.cpp` and `imgui_impl_glut.cpp` (since GLUT is used for windowing).
  3. **Input Handling Hookup**: Plumb the GLUT input callbacks (`KeyboardFunc`, `MouseFunc`, `MotionFunc`) to ImGui so the overlay can be interactive.
  4. **Data Linkage Phase**: Connect the newly exposed `m_FrameIdx`, `m_MaxFrameIdx`, network stats, and current sheep metadata to an ImGui window.
  5. **Legacy Replacement Phase**: Once the ImGui overlay achieves feature parity with the existing custom `Hud.cpp` text rendering, deprecate `Hud.cpp` and the older `FontGL`/`TrebuchetMS` rendering mechanisms.
  6. **Configuration UI Phase**: Begin porting settings from the separate wxWidgets `MSVC/SettingsGUI/` app directly into the ImGui overlay, eventually allowing the deprecation of the wxWidgets binary entirely for a unified experience.
