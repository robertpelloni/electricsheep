# Changelog

All notable changes to this project will be documented in this file.

## [0.9.0-alpha] - 2026-07-12
### Fixed
- [85e8dea] Implemented ImGui HUD integration, replacing the legacy wxWidgets / GL text rendering systems.
- [fe4a6cd] Added explicit asynchronous `CURLOPT_TIMEOUT` and `CURLOPT_CONNECTTIMEOUT` definitions to `CCurlTransfer` to prevent thread starvation during unreliable node downloads.
- [85e8dea] Cleaned up compiler warnings related to wxWidgets font structures.
- [85e8dea] Instrumented OpenGL context with `glCheckFramebufferStatusEXT` to log completion states during transitions.
- Modernized FFmpeg API usage across the ContentDecoder and Player components (`av_image_get_buffer_size`, `avcodec_send_packet`, etc.).
- Resolved critical OpenGL linkage issues by restoring and correctly integrating the `GLee` wrangler and isolating legacy extension macros.
- Fixed autotools and compilation issues enabling successful Linux builds.
- Replaced deprecated Boost filesystem calls (`branch_path`) with `parent_path` to improve compiler health.
