# 🧑‍💻 Development guide

## Development principles

Asim-Library is an educational C++ project. Keep algorithms readable, invariants explicit, ownership correct, and public behavior testable. A shorter implementation is not automatically better if it hides edge cases or memory responsibilities.

## Source responsibilities

- Public signatures and class contracts belong in `asim_library.h`.
- Implementations belong in `asim_library.cpp`.
- `main.cpp` should remain an illustrative demo, not the only source of behavioral verification.
- Automated tests belong in `tests/`.
- Build target and test registration belong in `CMakeLists.txt`.
- User-facing behavior changes require corresponding API documentation and changelog entries.

## Build before editing

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

## Coding conventions

- Target C++17.
- Avoid global `using namespace std` in headers.
- Prefer const correctness for read-only operations.
- Mark non-throwing queries and cleanup functions `noexcept` when justified.
- Initialize all members in constructors.
- Make ownership and copy/move behavior explicit for owning raw-pointer types.
- Keep helpers private unless consumers need the functionality.
- Use descriptive names for rotations and tree operations.
- Avoid unexplained sentinel values for error conditions.
- Keep compiler warnings enabled.

## Adding a data structure

1. Define its invariant in documentation.
2. Define public operations and edge-case semantics.
3. Decide how memory is owned and released.
4. Decide duplicate-value behavior.
5. Specify empty/invalid operation behavior.
6. Implement the data structure independently from the demo.
7. Add tests for normal, boundary, and adversarial sequences.
8. Add complexity analysis.
9. Add or update architecture diagrams.
10. Update README, API reference, and changelog.

## Testing expected

Every change should have tests that can run without reading console output unless output itself is the contract. Use stream overloads or pure query methods for deterministic assertions.

Tree tests should include sorted insertion, reverse insertion, duplicate values, missing values, deletion of leaf/one-child/two-child nodes, copy independence, move state, and destruction. AVL tests must check balance after each mutation, not only at the end.

## Memory diagnostics

Where available, use AddressSanitizer and UndefinedBehaviorSanitizer:

```bash
cmake -S . -B build-sanitized -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS="-fsanitize=address,undefined -fno-omit-frame-pointer" -DCMAKE_EXE_LINKER_FLAGS="-fsanitize=address,undefined"
cmake --build build-sanitized --parallel
ctest --test-dir build-sanitized --output-on-failure
```

For leak checks, use the sanitizer options supported by the current platform. Sanitizers are verification tools, not proof that all possible defects are absent.

## Pull request expectations

Describe the algorithm/invariant impact, public API changes, memory/ownership effects, complexity change, test commands, and documentation changes. Include actual test results rather than intended results.
