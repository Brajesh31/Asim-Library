# Development

Keep public declarations in `asim_library.h` and definitions in `asim_library.cpp`. Update `main.cpp` only for demonstrations. Preserve or document ownership, duplicate-key, empty-operation, and capacity semantics.

Compile with warnings and, when possible, sanitizers. New behavior should include a small reproducible demonstration until an automated test suite is added. Avoid broad refactors in a data-structure change.
