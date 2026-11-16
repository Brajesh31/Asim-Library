# 📦 Packaging and distribution

## Project form

Asim-Library is a native C++ library, not a network service. There is no server process, cloud deployment, environment-variable configuration, or database.

## Current consumption model

Consumers compile asim_library.cpp into their own application and include asim_library.h. The included CMake project creates a local library target, demo executable, and test executable.

## Build for a consumer

~~~bash
cmake -S . -B build -DASIM_LIBRARY_BUILD_DEMO=OFF -DASIM_LIBRARY_BUILD_TESTS=OFF -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
~~~

The current CMake file does not define install/export/package-config rules. Consumers can use the source tree directly. A future release can add CMake install/export targets and versioned package metadata.

## Distribution checklist

- Include the public header and library implementation or built library artifact.
- Include the MIT license.
- Declare compiler and C++ standard requirements.
- Publish checksums for release artifacts if binaries are distributed.
- Build from a tagged commit and record compiler/toolchain information.
- Run tests on every supported platform before publishing.
- Do not distribute IDE caches, object files, local build directories, or unreviewed executables.

## Versioning

The project has no formal binary ABI compatibility guarantee. If prebuilt libraries are published later, define platform/toolchain matrix, semantic versioning policy, ABI expectations, artifact naming, and release checks before promising compatibility.

There are no third-party runtime dependencies and no persistence layer.
