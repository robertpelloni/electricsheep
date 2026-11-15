# Changelog

All notable changes to this project will be documented in this file.

## [2.7b33-fork-v1.1.0] - 2024-11-04
### Added
- **System Tray Integration**: Added `ESTrayIcon` (`wxTaskBarIcon`) to the Electric Sheep management application with quick-access context actions: Open Control Dashboard, Launch Screensaver, Stop/Terminate Sheep Processes, and Exit.
- **In-App Dear ImGui Overlay Dashboard**: Overhauled the OpenGL rendering loop in `RendererGL.cpp` with a comprehensive in-app ImGui control dashboard providing live telemetry (FPS, frame time delta), quick toggles, flock cache limits, compute rendering toggles, and direct links to native preferences.
- **Consolidated Dashboard UI**: Completely restructured `electricsheep-preferences` into a clean, intuitive, high-value dashboard layout:
  - **★ Dashboard & Flock**: Front-and-center account authentication, membership status, and unified disk cache quotas for standard and Gold sheep flocks.
  - **⚙ Playback & Display**: Cohesive control of decode FPS, loop repetitions, seamless filtering, multi-monitor topology, and GPU shader frame interpolation.
  - **🔧 Advanced & Network**: Unified distributed generator settings, content directory management, folder browsing, and proxy configuration.
  - Added descriptive labels, guidance tips, and comprehensive tooltips across every interactive element.
- **Modernized Desktop Entries & Non-destructive Archiving**: Added Desktop Actions for quick launch and preferences to `ElectricSheep.desktop` and backed up legacy wrapper scripts to `scripts/archive/`.

## [2.7b33-fork-v1.0.6] - 2024-06-18
### Documentation
- Modified Phase 3 scoping in `IDEAS.md` and `TODO.md` based on an investigation into `Networking.cpp`, which proved that `curl_multi_perform` is already in use. Adjusted target for async network modernization to `SheepDownloader.cpp` wait-state threading blocks instead.

## [2.7b33-fork-v1.0.5] - 2024-06-18
### Documentation
- Researched Networking modernization logic mapping the synchronous `CCurlTransfer::Perform()` routine in `Networking/Networking.cpp`. Staged `TODO.md` for migrating to asynchronous multi-handlers.

## [2.7b33-fork-v1.0.4] - 2024-06-18
### Documentation
- Concluded Phase 2 and initiated Phase 3 (Network Modernization) by documenting the synchronous `libcurl` bottlenecks (`curl_easy`) in `IDEAS.md` and outlining the asynchronous `curl_multi` integration path.

## [2.7b33-fork-v1.0.3] - 2024-06-18
### Documentation
- Researched and appended Dear ImGui integration roadmap inside `IDEAS.md` for native renderer settings replacement.

## [2.7b33-fork-v1.0.2] - 2024-06-18
### Added
- Implemented HUD metric data linkage, indexing current frame and total frame metrics directly to `Client/client.h` for Phase 2 OSD.

## [2.7b33-fork-v1.0.1] - 2024-06-18
### Documentation & Governance
- Removed unused `libglew-dev` dependency instruction from `DEPLOY.md`.
- Added inline documentation comments to FFmpeg decoding logic.
- Initialized `MEMORY.md` and `IDEAS.md` for architectural tracking and next phase UI/HUD planning.

## [2.7b33-fork-v1.0.0] - 2024-05-20
### Fixed
- Modernized FFmpeg API usage across the ContentDecoder and Player components (`av_image_get_buffer_size`, `avcodec_send_packet`, etc.).
- Resolved critical OpenGL linkage issues by restoring and correctly integrating the `GLee` wrangler and isolating legacy extension macros.
- Fixed autotools and compilation issues enabling successful Linux builds.
- Replaced deprecated Boost filesystem calls (`branch_path`) with `parent_path` to improve compiler health.
