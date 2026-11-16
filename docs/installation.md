# 📦 Installation and build guide

## Requirements

- C++17 compiler: GCC 8+, Clang 7+, or a modern MSVC toolset with C++17 support.
- CMake 3.16 or later.
- Git.
- No third-party libraries are required.

Exact minimum compiler versions can vary by platform and standard-library implementation. Use a current compiler where possible.

## Clone

```bash
git clone https://github.com/Brajesh31/Asim-Library.git
cd Asim-Library
```

## CMake build

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
```

The build creates the library target, demo executable, and test executable by default.

## Execute the demo

Linux/macOS:

```bash
./build/asim_library_demo
```

Windows (multi-configuration generators such as Visual Studio):

```powershell
.\build\Release\asim_library_demo.exe
```

For a single-configuration Windows generator, the executable may be at `build/asim_library_demo.exe`.

## Run tests

```bash
ctest --test-dir build --output-on-failure
```

## Direct compilation

GCC/Clang:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic asim_library.cpp main.cpp -o asim-library
./asim-library
```

Compile tests independently:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic -I. asim_library.cpp tests/test_asim_library.cpp -o asim-library-tests
./asim-library-tests
```

## Optional build configuration

Disable the demo:

```bash
cmake -S . -B build -DASIM_LIBRARY_BUILD_DEMO=OFF
```

Disable tests:

```bash
cmake -S . -B build -DASIM_LIBRARY_BUILD_TESTS=OFF
```

## Verify compiler version

```bash
g++ --version
clang++ --version
cmake --version
```

Use the compiler selected by CMake consistently between configuration and build. If you switch compiler, remove the old build directory or configure a fresh one because CMake caches toolchain settings.

## Common platform notes

### Linux

Install your distribution's C++ compiler and CMake packages. Run CMake from the repository root.

### macOS

Install Xcode Command Line Tools and CMake. Apple Clang supports C++17 in current toolchains.

### Windows

Use MSVC from a Visual Studio Developer Command Prompt, or MinGW-w64 GCC. When using Visual Studio generators, include the configuration name when running the executable.

## Build artifacts

The `build/` directory is ignored by Git. Do not commit local object files, executables, compiler caches, or CMake-generated directories.
