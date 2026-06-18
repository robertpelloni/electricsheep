# Project Memory & Observations

## Architecture Notes
- The `electricsheep` client relies heavily on C++03/C++98 style coding. Modernization should be done iteratively.
- OpenGL rendering currently targets legacy APIs (GLee extension loading, fixed-function pipelines, early ARB shaders).
- FFmpeg is used for the decoding layer (`ContentDecoder/`) using the modern `avcodec_send_packet` / `avcodec_receive_frame` pipeline.
- Settings UI is externalized into a separate executable built via `wxWidgets` (version 2.9+ requirement).

## Design Preferences
- Strict documentation governance must be adhered to (update `VERSION.md`, `TODO.md`, `ROADMAP.md`, `CHANGELOG.md`, `HANDOFF.md`, etc., before handoffs).
- Avoid pulling in new major libraries unless the standard library or currently linked ones (Boost, libcurl, FFmpeg) cannot suffice.
- Remove `register` storage class, unused dependencies (`glew`), and old deprecated paths (Boost v2 filesystem).
