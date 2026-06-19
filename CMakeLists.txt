cmake_minimum_required(VERSION 3.10)
project(electricsheep VERSION 2.7.33)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# add -Wall
add_compile_options(-Wall -Wno-write-strings)
add_definitions("-DLINUX_GNU=1")
add_definitions("-DSHAREDIR=\"${CMAKE_INSTALL_PREFIX}/share/electricsheep/\"")
add_definitions("-DPACKAGE_DATA_DIR=\"${CMAKE_INSTALL_PREFIX}/share\"")
add_definitions("-DPACKAGE_LOCALE_DIR=\"${CMAKE_INSTALL_PREFIX}/share/locale\"")
add_definitions("-DUSE_NEW_FFMPEG_API=1")

# Find dependencies
find_package(PkgConfig REQUIRED)

pkg_check_modules(AVCODEC REQUIRED libavcodec)
pkg_check_modules(AVFORMAT REQUIRED libavformat)
pkg_check_modules(AVUTIL REQUIRED libavutil)
pkg_check_modules(SWSCALE REQUIRED libswscale)

pkg_check_modules(LUA REQUIRED lua5.1)
pkg_check_modules(CURL REQUIRED libcurl)
pkg_check_modules(PNG REQUIRED libpng)
pkg_check_modules(XRENDER REQUIRED xrender)
pkg_check_modules(LIBGTOP REQUIRED libgtop-2.0)

# GL and GLU
find_package(OpenGL REQUIRED)

# Boost
find_package(Boost REQUIRED COMPONENTS system thread filesystem)

# wxWidgets
find_package(wxWidgets REQUIRED COMPONENTS core base richtext)

# TinyXML - might need to find it manually or use pkg-config if available
pkg_check_modules(TINYXML tinyxml)
if(NOT TINYXML_FOUND)
  find_library(TINYXML_LIBRARIES NAMES tinyxml)
  if(NOT TINYXML_LIBRARIES)
    message(FATAL_ERROR "tinyxml not found")
  endif()
endif()

# GLee (might be bundled or system)
pkg_check_modules(GLEE glee)
if(NOT GLEE_FOUND)
  pkg_check_modules(GLEE GLee)
endif()
if(NOT GLEE_FOUND)
  find_library(GLEE_LIBRARIES NAMES glee GLee)
  if(NOT GLEE_LIBRARIES)
    message(WARNING "GLee not found in pkg-config, assuming bundled or manually installed")
    set(GLEE_LIBRARIES -lGLee)
  endif()
endif()

# We need to compile boost system thread issues without warnings
add_definitions(-DBOOST_BIND_GLOBAL_PLACEHOLDERS)


add_subdirectory(Client)
add_subdirectory(MSVC/SettingsGUI)

# Install rules for data
install(FILES README.md LICENSE DESTINATION share/doc/${PROJECT_NAME}-${PROJECT_VERSION})
install(DIRECTORY Runtime/Scripts DESTINATION share/electricsheep)
install(FILES menu-entries/ElectricSheep.desktop.kde DESTINATION share/applications RENAME ElectricSheep.desktop)
install(FILES menu-entries/electricsheep.xpm DESTINATION share/pixmaps)
install(FILES Runtime/electricsheep-attr.png Runtime/electricsheep-frown.png Runtime/electricsheep-smile.png DESTINATION share/electricsheep)
install(FILES Runtime/TrebuchetMS-20.glf Runtime/TrebuchetMS-24.glf DESTINATION share/electricsheep)
install(PROGRAMS electricsheep-saver DESTINATION bin)
install(FILES menu-entries/electricsheep-saver.desktop DESTINATION share/applications/screensavers RENAME electricsheep.desktop)
install(PROGRAMS electricsheep-saver-gnome DESTINATION lib/gnome-screensaver RENAME electricsheep-saver)
