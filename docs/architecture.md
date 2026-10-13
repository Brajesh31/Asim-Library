# Architecture

The library is organized as a simple C++ interface/implementation pair. `asim_library.h` declares `Stack`, `BST`, `BSTNode`, `AVLTree`, and `AVLNode`; `asim_library.cpp` implements their operations. `main.cpp` is a demonstration consumer rather than a library test harness.

The stack owns a dynamic integer array. The tree types own dynamically allocated nodes and perform recursive traversal/search operations. There is no external service, persistence layer, or runtime configuration.
