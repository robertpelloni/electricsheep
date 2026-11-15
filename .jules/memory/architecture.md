# Electric Sheep Fork - Architectural Summary

## Core Vision & Goal
This project is a modernizing fork of Scott Draves' classic Electric Sheep distributed computing project. The goal is to breathe new life into the application by updating legacy dependencies, ensuring cross-platform compatibility (starting with Linux), and preparing the foundation for enhanced visual fidelity and modern UX paradigms, all while preserving the original hypnotic, collaborative fractal flame screensaver experience.

## Architecture & Components
The codebase is written primarily in C++ (C++03/C++98 era, progressively modernized) and C. The main functional areas include:
*   **`Client/`**: The main application executable logic (`electricsheep`) orchestrating screensaver playback and rendering.
*   **`ContentDecoder/`**: Video decoding pipeline utilizing modern **FFmpeg** (`avcodec_send_packet` / `avcodec_receive_frame`).
*   **`DisplayOutput/`**: Rendering subsystem utilizing **OpenGL** (`GLee`) and an interactive **Dear ImGui** in-app telemetry & parameter overlay with cyclical F1 state management.
*   **`ContentDownloader/` / `Networking/`**: Handles fetching sheep payloads and communicating with servers using **libcurl** (`curl_multi_perform`) with non-blocking condition variable waits (`boost::condition_variable::timed_wait`).
*   **`MSVC/SettingsGUI/`**: A settings manager built with **wxWidgets** featuring desktop system tray integration (`ESTrayIcon` / `wxTaskBarIcon`) and consolidated configuration panels.
*   **`Common/`**: Shared utilities, threading logic (via Boost), Lua state management, cryptography (MD5), and custom random number generators (`isaac.cpp`).

## Key Dependencies & Ecosystem
*   **Build System**: CMake (`CMakeLists.txt`), migrated from legacy GNU Autotools.
*   **FFmpeg (`libavcodec`, `libavformat`, `libavutil`, `libswscale`)**: Used for modern video payload decoding.
*   **OpenGL (`GLee`)**: Handles extensions. A key architectural decision was made to revert to using bundled `GLee` instead of system `libGLEW` to resolve header conflicts on modern Linux.
*   **Dear ImGui**: Embedded in `DisplayOutput/OpenGL/RendererGL.cpp` for runtime telemetry, in-screensaver parameter adjustments, and HUD overlays.
*   **Boost (`system`, `thread`, `filesystem`)**: Used for cross-platform threading, non-blocking synchronization, and filesystem abstraction.
*   **wxWidgets**: Drives the external Settings GUI and system tray icon.
*   **Lua 5.1**: Embedded scripting engine.
*   **TinyXML**: For XML payload and configuration parsing.

## Patterns & Decisions
*   **Session Management & Resilience**: Automated session checkpoints are tracked in `.jules/sessions/` with comprehensive milestone history.
*   **Dependency Management**: External dependencies are managed carefully. Custom or bundled wrappers are used when system libraries conflict (e.g., `GLee`).
*   **FFmpeg Modernization**: Successfully transitioned to the modern packet/frame decoding APIs (`avcodec_send_packet` / `avcodec_receive_frame`) and buffer allocation (`av_image_get_buffer_size`).
*   **Documentation Governance**: Strict unified documentation rules across `VERSION.md`, `CHANGELOG.md`, `ROADMAP.md`, `TODO.md`, `VISION.md`, `DEPLOY.md`, `HANDOFF.md`, `MEMORY.md`, and `IDEAS.md`.
*   **Non-blocking Thread Concurrency**: Replaced blocking `boost::thread::sleep` calls with interruptible predicate waits (`boost::condition_variable::timed_wait`).
