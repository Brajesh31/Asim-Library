# 🔌 API reference

This page documents the public interface declared in [asim_library.h](../asim_library.h). The library currently stores integer values. Unless stated otherwise, operations do not print output except the no-argument traversal/display convenience methods.

## Stack

### Constructor

```cpp
explicit Stack(int size);
```

Creates a fixed-capacity stack. The capacity must be non-negative. A negative value throws `std::invalid_argument`. A capacity of zero is valid, but the stack is permanently full and cannot accept an element.

### Methods

| Signature | Return | Behavior |
|---|---|---|
| `void push(int element)` | void | Adds to top; throws `std::overflow_error` when full |
| `int pop()` | int | Removes and returns top; throws `std::underflow_error` when empty |
| `int peek() const` | int | Returns top without removing; throws on empty |
| `bool isEmpty() const noexcept` | bool | True when size is zero |
| `bool isFull() const noexcept` | bool | True when size equals capacity |
| `void rotateRight()` | void | Moves last occupied value to first occupied position |
| `void rotateLeft()` | void | Moves first occupied value to last occupied position |
| `void display() const` | void | Writes values bottom-to-top to standard output |
| `void display(std::ostream&) const` | void | Writes values to supplied stream |
| `bool search(int) const` | bool | Linear search |
| `int size() const noexcept` | int | Number of occupied values |
| `int capacity() const noexcept` | int | Configured capacity |
| `void clear() noexcept` | void | Removes all occupied values |

### Stack behavior example

```cpp
Stack stack(3);
stack.push(4);
stack.push(8);
stack.push(12);
// display: 4 8 12
stack.rotateRight();
// display: 12 4 8
int top = stack.pop(); // 8
```

The rotation applies to the occupied portion only. It does not rotate unused capacity slots.

## BST

The BST stores unique integer keys. Duplicate insertions are ignored.

| Signature | Return | Behavior |
|---|---|---|
| `BST()` | constructor | Creates an empty tree |
| `~BST()` | destructor | Releases every owned node |
| `void insert(int)` | void | Inserts a key unless already present |
| `bool search(int) const` | bool | Searches for a key |
| `void deleteNode(int)` | void | Deletes a matching key; missing key is a no-op |
| `void inOrderTraversal() const` | void | Writes sorted keys to stdout |
| `void inOrderTraversal(std::ostream&) const` | void | Writes traversal to supplied stream |
| `bool empty() const noexcept` | bool | Tests for empty tree |
| `std::size_t size() const noexcept` | size | Number of unique keys |
| `int height() const noexcept` | int | Height in nodes; empty tree is zero |
| `void clear() noexcept` | void | Releases all nodes |

Copy construction and copy assignment perform a deep copy. Move construction and move assignment transfer ownership and leave the source empty.

## AVLTree

The AVLTree stores unique integer keys and restores the AVL invariant after every successful insertion/deletion.

| Signature | Return | Behavior |
|---|---|---|
| `AVLTree()` | constructor | Creates an empty AVL tree |
| `~AVLTree()` | destructor | Releases every owned node |
| `void insert(int)` | void | Inserts unique key and rebalances |
| `void deleteNode(int)` | void | Deletes a key and rebalances |
| `bool search(int) const noexcept` | bool | Searches for a key |
| `void inOrderTraversal() const` | void | Writes sorted keys to stdout |
| `void inOrderTraversal(std::ostream&) const` | void | Writes sorted keys to stream |
| `bool empty() const noexcept` | bool | Tests for empty tree |
| `std::size_t size() const noexcept` | size | Number of unique keys |
| `int height() const noexcept` | int | Height in nodes; empty tree is zero |
| `bool isBalanced() const noexcept` | bool | Checks all AVL balance factors |
| `void clear() noexcept` | void | Releases all nodes |

Copy/move behavior follows the same deep-copy/ownership-transfer rules as BST.

## Exceptions and output

Stack boundary violations use standard exceptions. Tree operations do not use sentinel return values. Traversal outputs each key followed by a space and ends with a newline. Prefer the stream overload in tests and applications to avoid coupling to global stdout.

## Compatibility note

The older API used non-const query methods and returned `-1` after printing on empty pop/peek. The hardened API now throws on those invalid operations. Callers should catch standard exceptions if they need to recover from capacity/empty-state errors.
