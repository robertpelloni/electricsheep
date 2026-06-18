# Project Ideas & Brainstorming

## Re-Architecture & Pivoting
- **Vulkan/Modern OpenGL Port**: Given the deprecated nature of fixed-function pipelines, the entire `DisplayOutput/Renderer/` should be rewritten targeting OpenGL 4.5+ Core Profile or Vulkan to enable ultra-high resolutions (4k/8k) natively with lower CPU overhead.
- **Async Networking**: Migrate `ContentDownloader/` from synchronous `libcurl` calls to `Boost.Asio` or HTTP/2 async downloading to improve throughput and prevent application stutter during high-bandwidth fetches.

## Feature Expansion
- **HUD Overhaul**: Add comprehensive stats to `Client/Hud.cpp`:
  - Current sheep generation ID, hash, and author.
  - Active render duration / playback frame rate metrics.
  - Overall server status / connectivity ping logic.
  - Smooth animation transitions between the text visibility logic (`m_bVisible`).
- **Interactive UI Overlay**: Currently, settings require a separate wxWidgets binary. Consider embedding an immediate-mode GUI like `Dear ImGui` directly into the `electricsheep` rendering pipeline for real-time configuration without restarting.
