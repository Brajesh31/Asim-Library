# 📚 Documentation index

This folder is the detailed technical reference for Asim-Library. The guides describe the current C++17 implementation and distinguish implemented behavior from possible future work.

## Start here

| Goal | Guide |
|---|---|
| Understand the project | [Project overview](./project-overview.md) |
| Compile and run it | [Installation](./installation.md) |
| Use Stack, BST, and AVLTree | [API reference](./api.md) |
| Understand implementation structure | [Architecture](./architecture.md) |
| Learn each algorithm | [Algorithm guide](./algorithms.md) |
| Compare operation costs | [Complexity analysis](./complexity.md) |
| Run automated tests | [Testing guide](./testing.md) |
| Contribute safely | [Development guide](./development.md) |
| Diagnose an issue | [Troubleshooting](./troubleshooting.md) |

## 📦 Project and build

- [Project overview](./project-overview.md)
- [Installation and build](./installation.md)
- [Development workflow](./development.md)
- [Project structure](./project-structure.md)
- [Deployment and packaging](./deployment.md)

## 🧮 Data structure and API

- [API reference](./api.md)
- [Algorithms and invariants](./algorithms.md)
- [Complexity analysis](./complexity.md)
- [Architecture](./architecture.md)
- [Design decisions](./design-decisions.md)

## 🧪 Quality and maintenance

- [Testing strategy](./testing.md)
- [Troubleshooting](./troubleshooting.md)
- [Limitations](./limitations.md)
- [FAQ](./faq.md)
- [Accessibility](./accessibility.md)
- [Database and persistence scope](./database.md)
- [Backup and persistence considerations](./backup-and-persistence.md)

## 🧾 Architecture Decision Records

- [ADR index](./ADRs/README.md)
- [ADR 0001: Integer containers and ownership](./ADRs/0001-educational-integer-containers.md)
- [ADR template](./ADRs/template.md)

## 📊 Diagrams

- [Diagram catalogue](./diagrams/README.md)
- [Project architecture](./diagrams/project-architecture.mmd)
- [Stack operation flow](./diagrams/stack-operations.mmd)
- [BST insertion flow](./diagrams/bst-insertion.mmd)
- [BST deletion flow](./diagrams/bst-deletion.mmd)
- [AVL rotation selection](./diagrams/avl-rotations.mmd)
- [AVL mutation flow](./diagrams/avl-mutation.mmd)
- [Test pipeline](./diagrams/test-pipeline.mmd)

## Documentation maintenance rules

1. Update the API reference when a public signature or behavior changes.
2. Update algorithm and complexity guides when an algorithm changes.
3. Add regression tests for every fixed defect.
4. Keep diagrams synchronized with the actual implementation.
5. Label planned capabilities clearly.
6. Do not claim persistence, generic templates, iterators, concurrency, or package installation until implemented.
