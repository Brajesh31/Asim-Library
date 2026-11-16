# 🌍 Project overview

## Purpose

Asim-Library is a compact educational C++ project for understanding a fixed-capacity integer stack, an integer binary search tree, and an integer AVL tree. It aims to make algorithms and invariants visible rather than hiding them behind standard-library abstractions.

## Problem addressed

Students learning data structures often know the abstract operations but have less experience with concrete memory ownership, tree deletion, balancing, and edge-case behavior. This library gives readers a codebase they can compile, inspect, extend, and test.

## Current components

| Component | Core concept | Primary operations |
|---|---|---|
| Stack | LIFO linear structure | push, pop, peek, rotate, search |
| BST | Ordered binary tree | insert, search, delete, in-order traversal |
| AVLTree | Self-balancing ordered tree | insert, search, delete, rotations, balance verification |

## Intended audience

- Students learning data structures and algorithms.
- Developers practicing C++ class design and ownership.
- Contributors exploring tree balancing and deletion.
- Instructors who want a small code example that can be compiled locally.

## Learning objectives

After exploring the repository, a reader should be able to:
1. Explain LIFO semantics and fixed-capacity boundaries.
2. Trace BST search, insertion, and deletion.
3. Explain why in-order traversal returns sorted unique keys.
4. Identify LL, RR, LR, and RL AVL imbalance cases.
5. Understand why owning raw-pointer types need explicit copy/move behavior.
6. Build and run a small C++ project with CMake and CTest.
7. Write regression tests for algorithmic edge cases.

## Project boundaries

This is an in-memory, integer-only, single-threaded library. It does not offer network APIs, databases, serialization, persistence, generic templates, or a graphical interface. Those are separate features and should not be implied by project visuals or documentation.

## Success criteria

A change is considered complete when its behavior is documented, its invariant is clear, relevant boundary cases are tested, memory ownership is correct, and the build remains warning-conscious on supported compilers.
