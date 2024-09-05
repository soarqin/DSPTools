project(modman CXX)

# wxWidget options
set(wxWidgets_PREFIX "" CACHE STRING "wxWidgets ROOT dir")
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(wxWidgets_STATIC_DEFAULT OFF)
else()
    set(wxWidgets_STATIC_DEFAULT ON)
endif()
option(wxWidgets_STATIC "wxWidgets link static libaries" ${wxWidgets_STATIC_DEFAULT})

# find wxWidget
if(wxWidgets_PREFIX)
    set(wxWidgets_CONFIG_OPTIONS --prefix=${wxWidgets_PREFIX})
endif()
set(wxWidgets_USE_UNICODE ON)
set(wxWidgets_USE_STATIC ${wxWidgets_STATIC})
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

add_executable(${PROJECT_NAME} WIN32
    main.cpp
    mainwnd.cpp mainwnd.h
    version.h

    mods/dirs.cpp mods/dirs.h
    mods/listcfg.cpp mods/listcfg.h
    mods/modentry.cpp mods/modentry.h
)
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME DSPModMan
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    FOLDER app)
target_include_directories(${PROJECT_NAME} PRIVATE .)
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES} psapi ryaml nlohmann_json::headers fmt::fmt)
