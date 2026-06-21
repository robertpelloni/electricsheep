project(electricsheep_client)

include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/DisplayOutput/OpenGL
    ${CMAKE_SOURCE_DIR}/Common
    ${CMAKE_SOURCE_DIR}/DisplayOutput
    ${CMAKE_SOURCE_DIR}/DisplayOutput/Renderer
    ${CMAKE_SOURCE_DIR}/Common/Math
    ${CMAKE_SOURCE_DIR}/ContentDecoder
    ${CMAKE_SOURCE_DIR}/TupleStorage
    ${CMAKE_SOURCE_DIR}/ContentDownloader
    ${CMAKE_SOURCE_DIR}/lua5.1/src
    ${CMAKE_SOURCE_DIR}/Client
    ${CMAKE_SOURCE_DIR}/Networking
    ${CMAKE_SOURCE_DIR}/tinyXml
    ${CMAKE_SOURCE_DIR}/Dependencies/imgui
    ${CMAKE_SOURCE_DIR}/Dependencies/imgui/backends
)

set(SOURCES
    Player.cpp
    main.cpp
    Voting.cpp
    Hud.cpp
    ../Networking/Upload.cpp
    ../Networking/Download.cpp
    ../Networking/Networking.cpp
    ../DisplayOutput/LoadDDS.cpp
    ../DisplayOutput/Image.cpp
    ../DisplayOutput/OpenGL/GLee.c
    ../DisplayOutput/OpenGL/RendererGL.cpp
    ../DisplayOutput/OpenGL/glx.cpp
    ../DisplayOutput/OpenGL/ShaderGL.cpp
    ../DisplayOutput/OpenGL/TextureFlatGL.cpp
    ../DisplayOutput/OpenGL/wgl.cpp
    ../DisplayOutput/OpenGL/FontGL.cpp
    ../DisplayOutput/OpenGL/mgl.cpp
    ../DisplayOutput/Renderer/Shader.cpp
    ../DisplayOutput/Renderer/Texture.cpp
    ../DisplayOutput/Renderer/Font.cpp
    ../DisplayOutput/Renderer/TextureFlat.cpp
    ../DisplayOutput/Renderer/Renderer.cpp
    ../DisplayOutput/LoadPNG.cpp
    ../DisplayOutput/DisplayOutput.cpp
    ../tinyXml/tinyxmlparser.cpp
    ../tinyXml/tinyxml.cpp
    ../tinyXml/tinystr.cpp
    ../tinyXml/tinyxmlerror.cpp
    ../TupleStorage/diriterator.cpp
    ../TupleStorage/storage.cpp
    ../TupleStorage/luastorage.cpp
    ../ContentDecoder/ContentDecoder.cpp
    ../ContentDownloader/SheepUploader.cpp
    ../ContentDownloader/ContentDownloader.cpp
    ../ContentDownloader/SheepGenerator.cpp
    ../ContentDownloader/SheepDownloader.cpp
    ../ContentDownloader/Sheep.cpp
    ../ContentDownloader/Shepherd.cpp
    ../Common/LuaState.cpp
    ../Common/Common.cpp
    ../Common/AlignedBuffer.cpp
    ../Common/isaac.cpp
    ../Common/pool.cpp
    ../Common/Log.cpp
    ../Common/Math/Rect.cpp
    ../Common/luaxml.cpp
    ../Common/Exception.cpp
    ../Common/md5.c
)

add_executable(electricsheep ${SOURCES})

# Need GLUT
find_package(GLUT REQUIRED)

target_compile_options(electricsheep PRIVATE
    ${AVCODEC_CFLAGS}
    ${AVFORMAT_CFLAGS}
    ${SWSCALE_CFLAGS}
    ${AVUTIL_CFLAGS}
    ${LIBGTOP_CFLAGS}
    ${LUA_CFLAGS}
    ${CURL_CFLAGS}
    ${PNG_CFLAGS}
    ${XRENDER_CFLAGS}
)

# Need to handle GLee
target_link_libraries(electricsheep imgui
    Boost::system Boost::thread Boost::filesystem
    ${GLUT_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${AVCODEC_LIBRARIES}
    ${AVFORMAT_LIBRARIES}
    ${SWSCALE_LIBRARIES}
    ${AVUTIL_LIBRARIES}
    ${LUA_LIBRARIES}
    ${CURL_LIBRARIES}
    ${PNG_LIBRARIES}
    ${XRENDER_LIBRARIES}
    ${LIBGTOP_LIBRARIES}
    rt
    z
)

install(TARGETS electricsheep DESTINATION bin)
