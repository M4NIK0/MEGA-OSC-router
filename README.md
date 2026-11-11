# MEGA OSC router

This project aims to give a fully supported OSC router including modules to include and manage internally OSC integrations (for VRChat or others) through plugins loaded and started at any point during runtime.

## Configure and build

Boost.Log is downloaded and built automatically by CPM. Qt 6.5 or newer must
be installed separately because Qt does not support being embedded as a normal
CPM subdirectory:

```sh
cmake -S . -B build
cmake --build build
```

The application uses Boost.Log's `BOOST_LOG_TRIVIAL` logger. The `boost-log`
CPM dependency supplies Boost.Log and its required Boost libraries. The first
configure/build downloads and compiles the dependencies, so it can take
significantly longer than subsequent builds.

CPM.cmake is downloaded automatically into the build directory during the
first configure. It is kept separate from Qt because compiling Qt from source
through CPM is unnecessarily expensive; Qt is consumed through CMake's
standard `find_package(Qt6 ...)` integration.

## Create a distributable package

The install tree includes Qt runtime libraries and plugins when the Qt
deployment API is available. CPack then creates archives containing the
executable and its required libraries:

```sh
cmake --install build --prefix build/install
cd build
cpack
```

The default generators produce `.tar.gz` and `.zip` packages. Select a
specific generator with `cpack -G TGZ` or `cpack -G ZIP`.

The `vcpkg.json` manifest is retained for environments that already standardize
on vcpkg, but the normal CMake workflow does not use it.
