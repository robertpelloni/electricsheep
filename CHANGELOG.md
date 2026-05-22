# Changelog

All notable changes to this project will be documented in this file.

## [2.7b33-fork-v1.0.0] - 2024-05-20
### Fixed
- Modernized FFmpeg API usage across the ContentDecoder and Player components (`av_image_get_buffer_size`, `avcodec_send_packet`, etc.).
- Resolved critical OpenGL linkage issues by restoring and correctly integrating the `GLee` wrangler and isolating legacy extension macros.
- Fixed autotools and compilation issues enabling successful Linux builds.
- Replaced deprecated Boost filesystem calls (`branch_path`) with `parent_path` to improve compiler health.
