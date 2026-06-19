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
