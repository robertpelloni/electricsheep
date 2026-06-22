# Project Ideas & Brainstorming

## Re-Architecture & Pivoting
- **Vulkan/Modern OpenGL Port**: Given the deprecated nature of fixed-function pipelines, the entire `DisplayOutput/Renderer/` should be rewritten targeting OpenGL 4.5+ Core Profile or Vulkan to enable ultra-high resolutions (4k/8k) natively with lower CPU overhead.

## Feature Expansion
- **HUD Overhaul**: Add comprehensive stats to `Client/Hud.cpp`:
  - Current sheep generation ID, hash, and author.
  - Active render duration / playback frame rate metrics.
  - Overall server status / connectivity ping logic.
  - Smooth animation transitions between the text visibility logic (`m_bVisible`).
- **Interactive UI Overlay**: Currently, settings require a separate wxWidgets binary. Consider embedding an immediate-mode GUI like `Dear ImGui` directly into the `electricsheep` rendering pipeline for real-time configuration without restarting.

### Phase 3 Networking Modernization Scoping - COMPLETED
- **Path Forward**: The architecture was shifted from custom threaded wait states using `boost::thread::sleep` on the calling context to non-blocking condition variables that can wake instantly when requested.

## Phase 2: UI Overhaul Implementation Plan - COMPLETED
- **Framework Choice**: Dear ImGui
- **Rendering Approach**:
  - ImGui commands were injected directly into `RendererGL::EndFrame()` to overlay the screensaver visuals.
- **Migration Path**:
  1. **Submodule Integration**: Added Dear ImGui core explicitly.
  2. **Build System Hookup**: Updated `Client/CMakeLists.txt` to compile `imgui.cpp` and `imgui_impl_opengl2.cpp`.
  3. **Input Handling Hookup**: Plumb the GLUT input callbacks to ImGui.
  4. **Data Linkage Phase**: Connect the newly exposed `m_FrameIdx` and network stats to an ImGui window.
  5. **Legacy Replacement Phase**: Deprecate `Hud.cpp` and the older `FontGL`/`TrebuchetMS` rendering mechanisms.
  6. **Configuration UI Phase**: Begin porting settings from the separate wxWidgets `MSVC/SettingsGUI/` app directly into the ImGui overlay.
