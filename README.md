# MEGA OSC router

This project aims to give a fully supported OSC router including modules to include and manage internally OSC integrations (for VRChat or others) through plugins loaded and started at any point during runtime.

## Configure and build

Qt 6.5 or newer is required. Qt can be installed system-wide, or supplied by
vcpkg using the included manifest:

```sh
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE="$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake"
cmake --build build
```

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
