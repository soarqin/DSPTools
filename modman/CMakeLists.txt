# wxWidget options
option(wxWidgets_STATIC "wxWidgets link static libaries" OFF)

# find wxWidget
set(wxWidgets_USE_UNICODE ON)
set(wxWidgets_USE_STATIC ${wxWidgets_STATIC})
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

project(modman CXX)

add_executable(${PROJECT_NAME} WIN32
    res/modman.rc

    main.cpp
    mainwnd.cpp mainwnd.h
    modlist.cpp modlist.h
    modinfo.cpp modinfo.h
    toppanel.cpp toppanel.h
    imagecache.cpp imagecache.h
    version.h

    mods/dirs.cpp mods/dirs.h
    mods/listcfg.cpp mods/listcfg.h
    mods/modentry.cpp mods/modentry.h
    mods/profiles.cpp mods/profiles.h

    util/httpreq.cpp util/httpreq.h
)
set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME DSPModMan
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    FOLDER app)
target_include_directories(${PROJECT_NAME} PRIVATE .)
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES} ryaml nlohmann_json::headers fmt::fmt curl psapi)
