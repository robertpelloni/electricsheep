project(electricsheep_preferences)

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
)

set(SOURCES
    config.cpp
    electricsheepguiMyDialog2.cpp
    main.cpp
    ../../tinyXml/tinyxmlparser.cpp
    ../../tinyXml/tinyxml.cpp
    ../../tinyXml/tinystr.cpp
    ../../tinyXml/tinyxmlerror.cpp
    ../../TupleStorage/diriterator.cpp
    ../../TupleStorage/luastorage.cpp
    ../../TupleStorage/storage.cpp
    ../../Common/AlignedBuffer.cpp
    ../../Common/Common.cpp
    ../../Common/Exception.cpp
    ../../Common/Log.cpp
    ../../Common/LuaState.cpp
    ../../Common/luaxml.cpp
    ../../Common/md5.c
    ../../Common/pool.cpp
)

add_executable(electricsheep-preferences ${SOURCES})

# Need to properly include wxWidgets headers
target_include_directories(electricsheep-preferences PRIVATE ${wxWidgets_INCLUDE_DIRS})
target_compile_definitions(electricsheep-preferences PRIVATE ${wxWidgets_DEFINITIONS})
separate_arguments(WX_CXX_FLAGS_LIST UNIX_COMMAND "${wxWidgets_CXX_FLAGS}")
target_compile_options(electricsheep-preferences PRIVATE ${WX_CXX_FLAGS_LIST})

target_link_libraries(electricsheep-preferences
    Boost::thread Boost::filesystem
    ${CURL_LIBRARIES}
    ${LUA_LIBRARIES}
    ${wxWidgets_LIBRARIES}
)

install(TARGETS electricsheep-preferences DESTINATION bin)
