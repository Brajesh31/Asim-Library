# 🧭 Design decisions and trade-offs

## Integer-only interface

The library currently uses integers to keep the algorithms focused and easy to inspect. Templates would make the structures generic but introduce comparator/type requirements and more complex header-only implementation.

## Fixed-capacity stack

The stack retains its original fixed-capacity concept. A vector provides standard-library-managed storage while a capacity field enforces the fixed limit. A dynamically growing stack would change the educational contract.

## Exceptions for stack boundary failures

The old implementation printed a message and returned -1 for underflow, which is indistinguishable from a valid integer value. Standard exceptions make failure observable to the caller without reserving a data value as an error code.

## Duplicate tree keys are ignored

Both BST and AVLTree represent a set of unique integer keys. Counting duplicate occurrences or storing a multiplicity would be a different contract and is not implemented.

## Public node types

BSTNode and AVLNode remain public to preserve the educational nature and original exposed types. The owning tree, however, controls allocation and deletion. Consumers must not manually free nodes.

## Raw pointers in tree internals

Raw child pointers make rotations and ownership structure visible for learning. Correctness therefore depends on explicit destructors, deep-copy operations, move semantics, and careful subtree return values. A production-oriented generic container might prefer smart-pointer-based internals or a different node abstraction.

## Stream-based traversal overloads

No-argument traversal functions preserve the original console demonstration. Stream overloads make the output testable and allow consumers to write to files or string streams without global redirection.

## AVL rebalance helper

The AVL implementation centralizes node-height recalculation and rotation selection in one rebalance helper. This reduces duplication between insertion and deletion and helps keep the invariant logic consistent.
