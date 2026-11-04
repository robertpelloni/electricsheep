# Ideas & Exploration

## Brainstorming & Architecture Modernization
1. **Web Dashboard & Remote Telemetry**:
   - Embed a lightweight HTTP/WebSocket daemon (e.g., civetweb or Boost.Beast) into the screensaver client to serve an HTML5/React dashboard accessible over local network/mobile device.
2. **Modern Render Backends (Vulkan / Modern OpenGL 4.5+)**:
   - Modernize the rendering engine to use modern shader storage buffer objects (SSBO), compute shaders for fractal Flame evaluation on the GPU rather than relying on external CPU flame generation (`flam3-animate`).
3. **Pure Modern C++ Refactor**:
   - Migrate legacy raw pointers and custom smart pointer templates (`MakeSmartPointers`) to `std::shared_ptr` / `std::unique_ptr` (C++17/20).
4. **Wayland Native Client**:
   - Support native Wayland protocols alongside X11 using GLFW or SDL3 backend.
