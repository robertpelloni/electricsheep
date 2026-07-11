# Electric Sheep Fork - Architectural Summary

## Core Vision & Goal
This project is a modernizing fork of Scott Draves' classic Electric Sheep distributed computing project. The goal is to breathe new life into the application by updating legacy dependencies, ensuring cross-platform compatibility (starting with Linux), and preparing the foundation for enhanced visual fidelity and modern UX paradigms, all while preserving the original hypnotic, collaborative fractal flame screensaver experience.

## Architecture & Components
The codebase is written primarily in C++ (C++03/C++98 era, being progressively modernized) and C. The main functional areas include:
*   **`Client/`**: The main application executable logic (`electricsheep`) orchestrating the screensaver, playback, and rendering.
*   **`ContentDecoder/`**: Video decoding pipeline utilizing **FFmpeg**. It handles parsing the downloaded sheep payloads (fractal flame animations).
*   **`DisplayOutput/`**: Rendering subsystem utilizing **OpenGL**. It handles taking decoded frames and presenting them on screen. It currently relies heavily on legacy fixed-function pipeline mechanics and early ARB shaders.
*   **`ContentDownloader/` / `Networking/`**: Handles fetching sheep payloads and communicating with the centralized/distributed servers using **libcurl**.
*   **`MSVC/SettingsGUI/`**: A settings graphical interface built with **wxWidgets** allowing users (and power users) to configure the application cleanly.
*   **`Common/`**: Shared utilities, threading logic (via Boost), Lua state management, cryptography (MD5), and custom random number generators (`isaac.cpp`).

## Key Dependencies & Ecosystem
*   **Build System**: GNU Autotools (`autogen.sh`, `configure.ac`, `Makefile.am`).
*   **FFmpeg (`libavcodec`, `libavformat`, `libavutil`, `libswscale`)**: Used for decoding video payloads.
*   **OpenGL (`GLee`)**: Handles extensions. A key architectural decision was made to revert to using bundled `GLee` instead of system `libGLEW` to resolve severe header conflicts on modern Linux.
*   **Boost (`system`, `thread`, `filesystem`)**: Used for cross-platform threading and filesystem abstraction.
*   **wxWidgets**: Drives the external Settings GUI.
*   **Lua 5.1**: Embedded scripting engine.
*   **TinyXML**: For XML payload and configuration parsing.

## Patterns & Decisions
*   **Dependency Management**: External dependencies are managed carefully. Custom or bundled wrappers are used when system libraries conflict (e.g., `GLee`). The directive is to prefer existing libraries over adding new ones without justification.
*   **FFmpeg Modernization**: The project has undergone a significant shift from old FFmpeg APIs (e.g. `avcodec_decode_video2`) to the modern `avcodec_send_packet` / `avcodec_receive_frame` paradigms, including modernizing buffer allocation (`av_image_get_buffer_size`).
*   **Documentation Governance**: The repository enforces strict and unified documentation rules. Global state and versioning are managed through dedicated Markdown files (`VERSION.md`, `CHANGELOG.md`, `ROADMAP.md`, `TODO.md`, `VISION.md`, `DEPLOY.md`, `HANDOFF.md`, `MEMORY.md`, `IDEAS.md`).
*   **Compiler Health**: Legacy C/C++ patterns (like the `register` keyword) are being actively purged to ensure clean compilation on modern GCC/Clang toolchains.

## Current Roadmap Phase
The project is currently transitioning into **Phase 2: Feature Parity & UI Overhaul**, which involves hooking up the wxWidgets GUI to backend features and improving the on-screen display (HUD). Future phases include networking modernization and migrating to Core Profile OpenGL or Vulkan.