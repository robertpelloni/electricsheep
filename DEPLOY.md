# Deployment & Setup Instructions

## Prerequisites
The project requires the following libraries to build:
- GCC / G++ (C++03 / C++11 / C++17 support)
- CMake (`cmake`, `make`)
- Boost (`system`, `thread`, `filesystem`)
- FFmpeg (`libavcodec`, `libavformat`, `libswscale`, `libavutil`)
- OpenGL (`libgl1-mesa-dev`, `freeglut3-dev`)
- Lua 5.1 (`liblua5.1-0-dev`)
- TinyXML (`libtinyxml-dev`)
- cURL (`libcurl4-openssl-dev`)
- wxWidgets (`libwxgtk3.2-dev` for the settings GUI and system tray)
- libgtop2 (`libgtop2-dev`)
- libpng (`libpng-dev`)

### Ubuntu/Debian Install
```bash
sudo apt-get update
sudo apt-get install -y build-essential autoconf automake libtool pkg-config \
    libwxgtk3.2-dev libavcodec-dev libavformat-dev libswscale-dev \
    libcurl4-openssl-dev libavutil-dev liblua5.1-0-dev flam3-utils \
    libflam3-dev libgtop2-dev libboost-dev libboost-thread-dev \
    libboost-system-dev libboost-filesystem-dev libtinyxml-dev \
    freeglut3-dev libpng-dev
```

## Build Instructions
1. Configure the build environment:
   `cmake -B build -DCMAKE_BUILD_TYPE=Release`
2. Compile the project:
   `cmake --build build -j4`

## Running
After a successful build:
- Main screensaver client:
  `./build/Client/electricsheep`
- Control Dashboard & Preferences:
  `./build/MSVC/SettingsGUI/electricsheep-preferences`
