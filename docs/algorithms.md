# 🧮 Algorithms and data-structure invariants

## Stack operations

The stack stores a sequence of occupied values and a configured capacity. The top is the final occupied element.

### Push

1. Compare the number of occupied values with capacity.
2. If equal, throw `std::overflow_error`.
3. Otherwise append the new value.

### Pop and peek

Both operations first check emptiness. Empty access throws `std::underflow_error`. Pop then removes the final occupied value; peek returns it without mutation.

### Rotation

A right rotation moves the final occupied value to the first occupied position. A left rotation moves the first occupied value to the end. Neither operation touches unused capacity.

## Binary Search Tree invariant

For each node:
- Every key in the left subtree is smaller than the node key.
- Every key in the right subtree is larger than the node key.
- Duplicate keys are not inserted.

### Search

Compare the target with the current node. Equal means found. Smaller continues left; larger continues right. If the search reaches null, the value is absent.

### Insert

Follow the search path until a null child is found, then allocate the new node there. A duplicate terminates without allocation.

### Delete

Three structural cases:
1. **Leaf:** delete the node and return null to its parent.
2. **One child:** delete the node and return its only child.
3. **Two children:** find the in-order successor, copy its key into the target node, and remove the successor from the right subtree.

### In-order traversal

Traverse left subtree, visit the current node, then traverse right subtree. Under the BST invariant this emits values in ascending order.

## AVL invariant

An AVL tree is a BST where each node's balance factor is:

`height(left) - height(right)`

A valid node has a balance factor in {-1, 0, +1}. The stored node height is one plus the maximum of child heights. The empty subtree has height zero.

## AVL rotations

### LL imbalance

The left child is left-heavy or balanced. A single right rotation promotes the left child.

### RR imbalance

The right child is right-heavy or balanced. A single left rotation promotes the right child.

### LR imbalance

The left child is right-heavy. Rotate the left child left, then rotate the unbalanced node right.

### RL imbalance

The right child is left-heavy. Rotate the right child right, then rotate the unbalanced node left.

## AVL insertion

Insertion first follows the BST search path. On recursion return, each ancestor's height is updated and its balance factor checked. If unbalanced, the appropriate rotation is applied. Only newly inserted keys change the tree size.

## AVL deletion

Deletion uses the same leaf, one-child, and two-child structural cases as a BST. On the path back toward the root, heights and balance factors are recalculated. Deletion may require rebalancing at multiple ancestors, so the algorithm continues checking the entire return path.

## Verification

The AVL public `isBalanced()` method recursively checks every node. Tests call it after insertion/deletion sequences and exercise all four rotation cases.
