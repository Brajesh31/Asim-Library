# 🤝 Contributing to Asim-Library

Thank you for considering a contribution. Asim-Library is an educational C++17 data-structures project. The goal is to keep its algorithms understandable while maintaining correctness, clear ownership, and reproducible tests.

## Before changing code

1. Read the README and documentation index.
2. Check existing issues and the current roadmap.
3. Confirm the behavior and invariant affected by the change.
4. Identify public API, memory ownership, and complexity implications.
5. Create a focused issue for substantial changes.

## Local setup

~~~bash
git clone https://github.com/Brajesh31/Asim-Library.git
cd Asim-Library
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --parallel
ctest --test-dir build --output-on-failure
~~~

## Coding expectations

- Use C++17.
- Keep public declarations in the header and implementation in the source file.
- Do not put `using namespace std` in public headers.
- Prefer const correctness and explicit contracts.
- Make ownership and copy/move behavior explicit for owning types.
- Do not use a valid data value as an error sentinel.
- Keep warnings enabled.
- Avoid unnecessary dependencies.

## Test expectations

Behavior changes require automated tests. Include normal cases, boundaries, adversarial orderings, and failure conditions. For tree changes, test invariants, node deletion cases, copy independence, and move state. For AVL changes, verify balance after each mutation in relevant sequences.

## Documentation expectations

Update API reference, algorithms, complexity, architecture, and README when public behavior changes. Update diagrams when the flow/invariant changes. Update CHANGELOG for meaningful user-facing changes.

## Pull requests

Use the pull request template. Include the problem, design, edge cases, ownership impact, complexity, exact build/test commands, and actual results.

## Do not commit

Build directories, object files, executables, IDE caches, local environment files, private data, or unlicensed assets.

## Security reports

Report vulnerabilities privately using the process in SECURITY.md.
