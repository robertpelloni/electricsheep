# Changelog

All notable changes to this project will be documented in this file.

## [2.7b33-fork-v1.0.0] - 2024-05-20
### Fixed
- Modernized FFmpeg API usage across the ContentDecoder and Player components (`av_image_get_buffer_size`, `avcodec_send_packet`, etc.).
- Resolved critical OpenGL linkage issues by restoring and correctly integrating the `GLee` wrangler and isolating legacy extension macros.
- Fixed autotools and compilation issues enabling successful Linux builds.
- Replaced deprecated Boost filesystem calls (`branch_path`) with `parent_path` to improve compiler health.

## [2.7b33-fork-v1.0.1] - 2024-06-18
### Documentation & Governance
- Removed unused `libglew-dev` dependency instruction from `DEPLOY.md`.
- Added inline documentation comments to FFmpeg decoding logic.
- Initialized `MEMORY.md` and `IDEAS.md` for architectural tracking and next phase UI/HUD planning.

## [2.7b33-fork-v1.0.2] - 2024-06-18
### Added
- Implemented HUD metric data linkage, indexing current frame and total frame metrics directly to `Client/client.h` for Phase 2 OSD.

## [2.7b33-fork-v1.0.3] - 2024-06-18
### Documentation
- Researched and appended Dear ImGui integration roadmap inside `IDEAS.md` for native renderer settings replacement.

## [2.7b33-fork-v1.0.4] - 2024-06-18
### Documentation
- Concluded Phase 2 and initiated Phase 3 (Network Modernization) by documenting the synchronous `libcurl` bottlenecks (`curl_easy`) in `IDEAS.md` and outlining the asynchronous `curl_multi` integration path.

## [2.7b33-fork-v1.0.5] - 2024-06-18
### Documentation
- Researched Networking modernization logic mapping the synchronous `CCurlTransfer::Perform()` routine in `Networking/Networking.cpp`. Staged `TODO.md` for migrating to asynchronous multi-handlers.
