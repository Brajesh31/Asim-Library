# 🔧 Troubleshooting

## CMake cannot find a compiler

Install a C++17 compiler and ensure it is available on PATH. Run:

```bash
g++ --version
clang++ --version
cmake --version
```

On Windows, configure from a Visual Studio Developer Command Prompt for MSVC or install a supported MinGW-w64 toolchain.

## CMake reports a cached compiler mismatch

CMake caches the chosen compiler in the build directory. Configure a fresh build directory or remove the old generated build directory before switching compiler.

## Header file not found

Run CMake from the repository root, or include the project root in the compiler include path. The examples include `asim_library.h`.

## Undefined references at link time

Compile/link `asim_library.cpp` with the consumer source. Including the header alone declares the interface but does not provide the implementation.

## Tests are not discovered

Reconfigure and rebuild:

```bash
cmake -S . -B build
cmake --build build --parallel
ctest --test-dir build -N
```

The CMake option `ASIM_LIBRARY_BUILD_TESTS` must remain ON.

## Stack underflow/overflow exception

The stack deliberately throws standard exceptions for invalid operations. Check `isEmpty()` or `isFull()` before calling if your application prefers precondition checks, or catch the relevant exception.

## Unexpected BST height

A normal BST does not self-balance. Sorted or nearly sorted insertion may create a tall tree. Use AVLTree when balancing is required.

## AVL balance test fails

Reduce the operation sequence and check height updates and the four rotation cases. The automated suite checks balance after each insertion in its main rotation and stress sequences.

## Sanitizer reports a memory issue

Build with AddressSanitizer and UndefinedBehaviorSanitizer using the instructions in [testing.md](./testing.md). Re-run with the smallest input sequence that reproduces the issue. Do not suppress a sanitizer report without understanding the cause.

## Different output spacing

Traversal emits a trailing space after each value and then a newline. Use stream output in tests and compare to the documented behavior, or normalize whitespace in a consuming application.
