# Short-term Actionable Tasks

## High Priority
~~1. **Modernize Boost Filesystem Usage**: Update deprecated Boost Filesystem v2 calls (e.g., `branch_path()`) to modern v3 equivalents (e.g., `parent_path()`) to eliminate compilation warnings and prepare for newer Boost versions.~~ (Completed)
~~2. **Settings GUI Linkage**: Ensure the `wxWidgets` settings GUI compiles and integrates cleanly alongside the main executable without configuration errors.~~ (Completed)
~~3. **Verify Rendering Pipeline**: Test the OpenGL rendering path on a machine with a display context to ensure textures are correctly uploaded via the modernized FFmpeg decoding pipeline.~~ (Completed)

## HUD & GUI Phase 2 Tasks
~~4. **HUD Data Linkage**: Update `Client/client.h` to pull frame data values from the core decoder struct to render metrics visually via the OSD logic.~~ (Completed)
~~5. **ImGui Integration**: Add Dear ImGui to the project, update CMake, and replace the legacy rendering mechanisms. Stripped all bloat and isolated contexts into RendererGL.~~ (Completed)
6. **ImGui Window Configuration**: Build the actual UI windows overlay using the ImGui contexts injected into `RendererGL.cpp` to expose frame metrics and replace the wxWidgets preferences app.

## Network Modernization Phase 3 Tasks
~~7. **Async Networking (Boost.Asio)**: Refactor `ContentDownloader/SheepDownloader.cpp` and `SheepGenerator.cpp` to remove aggressive thread halting (`boost::thread::sleep`) when `curl_multi_perform` encounters failure states. Transition to an event-driven `Boost.Asio` architecture to prevent global render stutter.~~ (Completed)
