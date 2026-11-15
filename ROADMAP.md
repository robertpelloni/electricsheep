# Major Long-term Plans

## Phase 1: Modernization and Stabilization (Completed)
- Update core dependencies (FFmpeg, Boost, OpenGL).
- Fix build pipelines across platforms (Linux primarily, CMake unified build).
- Clean up legacy code constructs generating warnings on modern compilers.

## Phase 2: Feature Parity & UI Overhaul (Completed)
- Hook up all backend features to the frontend `wxWidgets` GUI.
- Consolidate dashboard layout into high-value unified panels with tooltips.
- Add system tray icon (`wxTaskBarIcon`) with process management and quick launching.
- Integrate Dear ImGui overlay for live in-app telemetry and configuration.

## Phase 3: Network & API Modernization (Completed)
- Modernize asynchronous paradigms and non-blocking download/generator threads.
- Robust error handling and fallback routines when downloading sheep payload files.

## Phase 4: Expansion & Next Gen Features
- Support for modern screen resolutions (4K/8K/HDR) and multi-monitor setups.
- Potential migration from legacy OpenGL (fixed function pipeline / early ARB shaders) to modern OpenGL (Core Profile) or Vulkan.
- REST API / Web-based remote dashboard control.
