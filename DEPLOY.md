# Deployment & Setup Instructions

## Prerequisites
The project requires the following libraries to build:
- GCC / G++ (C++03 / C++98 support)
- Autotools (`autoconf`, `automake`, `libtool`)
- Boost (`system`, `thread`, `filesystem`)
- FFmpeg (`libavcodec`, `libavformat`, `libswscale`, `libavutil`)
- OpenGL (`libgl1-mesa-dev`, `freeglut3-dev`)
- Lua 5.1 (`liblua5.1-0-dev`)
- TinyXML (`libtinyxml-dev`)
- cURL (`libcurl4-openssl-dev`)
- wxWidgets (for the settings GUI)
- libgtop2 (`libgtop2-dev`)
- libpng (`libpng-dev`)

### Ubuntu/Debian Install
```bash
sudo apt-get update
sudo apt-get install build-essential autoconf automake libtool pkg-config \
    libwxgtk3.2-dev libavcodec-dev libavformat-dev libswscale-dev \
    libcurl4-openssl-dev libavutil-dev liblua5.1-0-dev flam3-utils \
    libflam3-dev libgtop2-dev libboost-dev libboost-thread-dev \
    libboost-system-dev libboost-filesystem-dev libtinyxml-dev \
    freeglut3-dev libglew-dev libpng-dev
```

## Build Instructions
1. Generate the configure script:
   `./autogen.sh`
2. Configure the build environment:
   `./configure`
3. Compile the project:
   `make`

## Running
After a successful build, the binary will be located in the `Client/` directory:
`./Client/electricsheep`

*Note: Environment variables for API keys/secrets should be defined in a `.env` file (if applicable) and are not to be committed.*
