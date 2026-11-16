# ⚠️ Limitations and supported scope

## Implemented scope

The repository implements a fixed-capacity integer Stack, an integer Binary Search Tree (BST), and an integer AVLTree. Public operations include insertion, lookup, deletion where appropriate, in-order traversal, size/height queries, and cleanup. The tree classes define explicit ownership, deep-copy, and move behavior.

## Current limitations

1. **Integer-only values:** the classes are not templates and do not accept arbitrary types or comparators.
2. **Fixed stack capacity:** capacity is selected at construction and cannot be resized.
3. **Unbalanced BST:** sorted insertion can produce O(n) height.
4. **Console convenience output:** no-argument traversal/display writes to stdout, although stream overloads are also available.
5. **No iterators:** the tree classes do not expose standard iterator interfaces.
6. **No range queries:** lower_bound, upper_bound, and range traversal are not implemented.
7. **No duplicate counts:** repeated tree keys are ignored.
8. **No thread safety:** simultaneous access requires external synchronization.
9. **No persistence:** serialization, file storage, and databases are outside current scope.
10. **No CMake install/export package:** CMake currently builds local targets only.
11. **No formal ABI guarantee:** compiler/toolchain binary compatibility is not promised.
12. **Educational status:** the library has not been independently audited as a production container implementation.

## Ownership boundary

Tree node types are public for educational inspection, but the owning tree controls allocation and deletion. Consumers must not manually free nodes reachable from the tree. Copies own independent node graphs; moves transfer ownership.

## Roadmap

Potential improvements are tracked in [ROADMAP.md](../ROADMAP.md). Each new capability should include a clear contract, tests, complexity analysis, and documentation.
