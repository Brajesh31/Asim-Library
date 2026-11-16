# 🗺️ Roadmap

This roadmap separates implemented functionality from possible future improvements. Proposed items are not current features.

## Current foundation

- [x] Integer Stack, BST, and AVLTree implementations.
- [x] Explicit stack overflow/underflow behavior.
- [x] Tree destruction and ownership.
- [x] Deep-copy and move semantics for trees.
- [x] Stream-based traversal overloads.
- [x] CMake build and CTest suite.
- [x] GCC/Clang CI and sanitizer job.
- [x] API, algorithm, complexity, and testing documentation.

## Near-term improvements

- [ ] Add generic template variants with comparator support.
- [ ] Add iterative traversal options.
- [ ] Add BST minimum/maximum and successor/predecessor APIs.
- [ ] Add AVL tests for deletion-triggered LL/RR/LR/RL repairs with isolated targeted cases.
- [ ] Add fuzz/property-based operation sequences.
- [ ] Add benchmark targets for BST versus AVL under sorted, reverse, and random insertion.

## Distribution improvements

- [ ] Add CMake install/export rules and package configuration.
- [ ] Add platform build matrix for Linux, Windows, and macOS.
- [ ] Publish versioned source archives and reproducible release artifacts.
- [ ] Define semantic versioning and compatibility policy.

## Longer-term ideas

- [ ] Iterators and range queries.
- [ ] Duplicate-count or multiset policy.
- [ ] Serialization helpers with versioned formats.
- [ ] Optional visualization examples.

## Prioritization

Memory correctness, invariant tests, and clear API semantics take priority over feature count. Any proposed change should include a use case, ownership analysis, complexity impact, tests, and documentation.
