# Major Long-term Plans

## Phase 1: Modernization and Stabilization (Current)
- Update core dependencies (FFmpeg, Boost, OpenGL).
- Fix build pipelines across platforms (Linux primarily, followed by Mac/Windows wrappers).
- Clean up legacy code constructs generating warnings on modern compilers.

## Phase 2: Feature Parity & UI Overhaul
- Hook up all backend features to the frontend `wxWidgets` GUI.
- Improve the on-screen display (HUD) for sheep information.
- Enable smooth, seamless transitions between high-resolution sheep animations using modernized shader pipelines.

## Phase 3: Network & API Modernization
- Refactor the networking stack to utilize modern asynchronous paradigms.
- Improve error handling and fallback routines when downloading sheep payload files.

## Phase 4: Expansion
- Support for modern screen resolutions (4K/8K) and multi-monitor setups.
- Potential migration from legacy OpenGL (fixed function pipeline / early ARB shaders) to modern OpenGL (Core Profile) or Vulkan.
