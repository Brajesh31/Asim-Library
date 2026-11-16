# 🧪 Testing and verification strategy

## Current automated suite

Tests are implemented in `tests/test_asim_library.cpp` and registered through CTest. The suite uses standard C++ assertions and does not require third-party test frameworks.

## Coverage catalogue

### Stack
- Empty state and initial size/capacity.
- Underflow from pop.
- Push to capacity and overflow.
- Peek and search.
- Left/right occupied-sequence rotation.
- Pop and clear.
- Negative capacity rejection.

### BST
- Unique key insertion and duplicate suppression.
- Search hit/miss.
- Sorted in-order traversal.
- Deletion of leaf, one-child, and two-child nodes.
- Missing-key deletion.
- Size, empty, and clear behavior.
- Deep copy independence, copy assignment, move construction, and moved-from state.

### AVL
- LL, RR, LR, and RL insertion cases.
- In-order ordering.
- Height after simple rotations.
- Larger multi-level insertion sequence.
- Balance invariant after every insertion.
- Deletion and balance invariant after multiple removals.
- Missing-key deletion.
- Deep-copy, assignment, move, and clear behavior.

## Local test commands

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

## Compiler matrix

The CI workflow configures a GCC and Clang build. It compiles the library, demo, and test executable, then runs CTest and the demo program.

## Sanitizers

A separate CI job uses AddressSanitizer and UndefinedBehaviorSanitizer on supported Linux runners. The goal is to detect memory misuse, use-after-free, invalid access, undefined behavior, and leaks in the automated scenarios.

## Manual verification

Before release, also inspect:
- Stack capacity zero.
- Large stack capacities.
- Empty and single-node trees.
- Sorted and reverse-sorted BST insertion.
- Repeated delete of the root.
- Delete absent keys from empty/non-empty trees.
- AVL deletion cases requiring each rotation pattern.
- Self-assignment and move assignment.
- Large-but-reasonable tree sizes.

## Test quality rules

A test should assert behavior, not merely execute a method. AVL tests should verify sorted traversal and balance invariants. Ownership tests should verify that modifying copies does not affect the original. Add regressions for every bug found.
