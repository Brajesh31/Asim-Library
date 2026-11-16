# 📝 Changelog

All notable project changes are recorded here. Dates reflect repository changes.

## [Unreleased]

### Added
- CMake project with library, demo, and test targets.
- Automated tests for Stack, BST, and AVLTree behavior.
- GCC/Clang CI, sanitizer, documentation, and secret-scanning workflows.
- Original SVG banner and editable Mermaid algorithm diagrams.
- Expanded API, architecture, algorithm, complexity, installation, development, testing, troubleshooting, limitations, and project overview documentation.
- ADR directory and initial ownership/API decision record.

### Changed
- Replaced stack error sentinel behavior with standard exceptions.
- Removed public-header global namespace pollution.
- Added const-correct query methods and stream-based traversal overloads.
- Expanded the demonstration to cover the main operations.

### Fixed
- Tree memory cleanup on object destruction.
- Unsafe implicit shallow copying of owning tree nodes through deep-copy semantics.
- Explicit move ownership transfer for tree classes.
- Stack negative-capacity handling.
- Tree size/height tracking and AVL balance verification.

### Compatibility notes
- Empty Stack pop/peek now throw std::underflow_error instead of printing and returning -1.
- Negative stack capacity throws std::invalid_argument.
- Duplicate keys in BST and AVLTree remain ignored.

## Releases

No tagged release history is listed here yet.
