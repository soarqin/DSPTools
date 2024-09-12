add_subdirectory(json)
add_subdirectory(rapidyaml)
set(MESSAGE_QUIET ON)
add_subdirectory(fmt)
set(MESSAGE_QUIET OFF)

include(ExternalProject)

ExternalProject_Add(zlib-external
    GIT_REPOSITORY "https://github.com/madler/zlib"
    GIT_TAG "v1.3.1"
    GIT_CONFIG advice.detachedHead=false
    UPDATE_DISCONNECTED ON
    PREFIX "${CMAKE_BINARY_DIR}/zlib"
    CMAKE_CACHE_ARGS
    "-DCMAKE_POSITION_INDEPENDENT_CODE:BOOL=ON"
    "-DBUILD_SHARED_LIBS:BOOL=OFF"
    "-DZLIB_BUILD_EXAMPLES:BOOL=OFF"
    "-DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}"
    "-DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_BINARY_DIR}/external"
)

add_library(zlib INTERFACE)
target_include_directories(zlib INTERFACE "${CMAKE_BINARY_DIR}/external/include")
target_link_directories(zlib INTERFACE "${CMAKE_BINARY_DIR}/external/lib")
target_link_libraries(zlib INTERFACE "zlibstatic")
add_dependencies(zlib zlib-external)

ExternalProject_Add(curl-external
    GIT_REPOSITORY "https://github.com/curl/curl"
    GIT_TAG "curl-8_10_0"
    GIT_CONFIG advice.detachedHead=false
    UPDATE_DISCONNECTED ON
    PREFIX "${CMAKE_BINARY_DIR}/curl"
    DEPENDS zlib
    CMAKE_CACHE_ARGS
    "-DCMAKE_POSITION_INDEPENDENT_CODE:BOOL=ON"
    "-DBUILD_TESTING:BOOL=OFF"
    "-DBUILD_CURL_EXE:BOOL=OFF"
    "-DBUILD_SHARED_LIBS:BOOL=OFF"
    "-DBUILD_STATIC_LIBS:BOOL=ON"
    "-DENABLE_UNICODE:BOOL=ON"
    "-DHTTP_ONLY:BOOL=ON"
    "-DCURL_ENABLE_SSL:BOOL=ON"
    "-DCURL_USE_SCHANNEL:BOOL=ON"
    "-DCURL_USE_LIBPSL:BOOL=OFF"
    "-DCMAKE_BUILD_TYPE:STRING=${CMAKE_BUILD_TYPE}"
    "-DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_BINARY_DIR}/external"
)

add_library(curl INTERFACE)
target_include_directories(curl INTERFACE "${CMAKE_BINARY_DIR}/external/include")
target_compile_definitions(curl INTERFACE "CURL_STATICLIB")
target_link_directories(curl INTERFACE "${CMAKE_BINARY_DIR}/external/lib")
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_link_libraries(curl INTERFACE curl-d)
else ()
    target_link_libraries(curl INTERFACE curl)
endif ()
target_link_libraries(curl INTERFACE zlib Crypt32 Bcrypt Ws2_32)
add_dependencies(curl curl-external)
