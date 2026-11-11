cmake_minimum_required(VERSION 3.24)

project(MEGA-OSC-router
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

# CPM is downloaded into the build tree so the repository stays self-contained
# without committing a copy of the dependency manager.
set(CPM_DOWNLOAD_VERSION 0.40.2)
set(CPM_DOWNLOAD_LOCATION
    "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake"
)
if(NOT EXISTS "${CPM_DOWNLOAD_LOCATION}")
    file(DOWNLOAD
        "https://github.com/cpm-cmake/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake"
        "${CPM_DOWNLOAD_LOCATION}"
        TLS_VERIFY ON
        STATUS CPM_DOWNLOAD_STATUS
    )
    list(GET CPM_DOWNLOAD_STATUS 0 CPM_DOWNLOAD_RESULT)
    if(NOT CPM_DOWNLOAD_RESULT EQUAL 0)
        list(GET CPM_DOWNLOAD_STATUS 1 CPM_DOWNLOAD_ERROR)
        message(FATAL_ERROR "Could not download CPM.cmake: ${CPM_DOWNLOAD_ERROR}")
    endif()
endif()
include("${CPM_DOWNLOAD_LOCATION}")

CPMAddPackage(
    NAME Boost
    VERSION 1.86.0
    GITHUB_REPOSITORY boostorg/boost
    GIT_TAG boost-1.86.0
    GIT_SHALLOW YES
    GIT_SUBMODULES_RECURSE YES
    OPTIONS
        "BOOST_ENABLE_CMAKE ON"
        "BOOST_INCLUDE_LIBRARIES log"
)

find_package(Qt6 6.5 CONFIG REQUIRED COMPONENTS Core)

add_executable(mega-osc-router
    src/main.cpp
        src/plugins/IPlugin.cpp
        src/plugins/IPlugin.hpp
)

target_link_libraries(mega-osc-router PRIVATE Qt6::Core Boost::log)

set_target_properties(mega-osc-router PROPERTIES
    OUTPUT_NAME "mega-osc-router"
    WIN32_EXECUTABLE ON
)

include(GNUInstallDirs)
install(TARGETS mega-osc-router
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
    BUNDLE DESTINATION .
)

# Qt 6.5+ generates a deployment script that copies Qt and plugin libraries
# into the install tree. CPack then packages the complete runnable tree.
if(COMMAND qt_generate_deploy_app_script)
    qt_generate_deploy_app_script(
        TARGET mega-osc-router
        OUTPUT_SCRIPT QT_DEPLOY_SCRIPT
        NO_TRANSLATIONS
    )
    install(SCRIPT "${QT_DEPLOY_SCRIPT}")
endif()

set(CPACK_PACKAGE_NAME "mega-osc-router")
set(CPACK_PACKAGE_VENDOR "M4NIK0")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "MEGA OSC router")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_CONTACT "M4NIK0")
set(CPACK_GENERATOR "TGZ;ZIP")
include(CPack)