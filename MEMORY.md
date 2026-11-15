# Memory & Architectural Observations

## UI & Dashboard Architecture
* The settings dashboard has been modernized into a consolidated, intuitive multi-section design.
* Tab 1 is dedicated to high-value features: Account authentication and local standard/Gold flock storage cache limits.
* Tab 2 consolidates animation playback rates, loop counts, seamless filtering, and hardware multi-monitor / frame interpolation settings.
* Tab 3 unifies distributed generation settings, content directory picking, and network proxy credentials.
* The system tray is handled via `ESTrayIcon` subclassing `wxTaskBarIcon`, enabling quick screensaver launch and process termination (`KillSheepServers`).
* In-app telemetry and runtime controls are rendered using Dear ImGui over OpenGL/GLUT in `DisplayOutput/OpenGL/RendererGL.cpp`.
