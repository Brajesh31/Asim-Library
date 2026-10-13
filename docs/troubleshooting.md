# Troubleshooting

## Compiler cannot find a header

Compile from the repository root or add the source directory to the include path. The demo expects `asim_library.h` beside the source files.

## Linker reports undefined references

Compile and link both `asim_library.cpp` and `main.cpp`; compiling only the demo does not provide implementation symbols.

## Unexpected tree output

Check insertion order, duplicate-key behavior, and whether the operation is in-order traversal. Add a minimal sequence to `main.cpp` to reproduce the case.

## Crash or sanitizer report

Rebuild with AddressSanitizer and UndefinedBehaviorSanitizer, then reduce the input sequence to the first failing operation. Check empty pop/peek, capacity boundaries, and node ownership.
