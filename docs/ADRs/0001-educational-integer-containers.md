# ADR 0001: Educational integer containers and ownership policy

- **Status:** Accepted
- **Date:** 2026-11-16
- **Decision owner:** Project maintainer

## Context

The library demonstrates an integer stack, BST, and AVL tree. The original tree classes allocated nodes dynamically without defining safe copy ownership. The stack printed messages and returned -1 for empty pop/peek, even though -1 is a valid integer. The public header also exposed a global using-directive.

## Decision

Keep the familiar integer-based class names and define explicit behavior:
- Stack capacity must be non-negative.
- Stack overflow and underflow throw standard exceptions.
- Tree keys are unique; duplicate insertions are ignored.
- Tree owners release every allocated node.
- Tree copies are deep copies.
- Tree moves transfer ownership and empty the source.
- Traversal may target a supplied output stream.
- Query methods are const-correct.
- The project targets C++17 and uses CMake/CTest.

## Alternatives considered

### Replace the structures with STL containers

This would reduce custom code but remove the educational algorithm implementations, which are the central purpose of this repository.

### Make every structure a template immediately

Templates would broaden reuse but increase interface complexity. That can be considered as a separately reviewed future change.

### Keep owning raw-pointer trees with implicit shallow copying

Rejected because copying owning raw pointers can cause double deletion and use-after-free.

## Consequences

The public API is safer and testable. Empty stack operations now throw instead of returning -1. Tree copies own independent nodes. The library remains integer-only and educational.
