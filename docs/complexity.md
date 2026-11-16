# ⏱️ Time and space complexity

Let n denote the number of stored keys/items. Let h denote the height of a binary search tree.

## Summary

| Operation | Stack | BST | AVL Tree |
|---|---:|---:|---:|
| Insert/push | O(1) amortized | O(h) | O(log n) |
| Search | O(n) | O(h) | O(log n) |
| Remove/pop/delete | O(1) | O(h) | O(log n) |
| Peek/top | O(1) | N/A | N/A |
| In-order traversal | N/A | O(n) | O(n) |
| Height query | N/A | O(n) current implementation | O(1) |
| Clear/destruction | O(n) | O(n) | O(n) |

## Stack

- Push/pop/peek are O(1).
- Search is O(n).
- Left/right rotation is O(n), because the occupied sequence is shifted.
- Storage is O(c), where c is the configured capacity reserved for the vector. The number of active values is at most c.

## Binary Search Tree

Search/insert/delete take O(h). When the tree is balanced, h is O(log n). When values arrive in sorted order, the tree can degenerate into a linked list, making h O(n). Traversal and destruction are O(n). The height query currently recursively inspects the tree and is O(n).

## AVL Tree

The AVL invariant bounds height to O(log n), so search, insert, and delete are O(log n). In-order traversal and full invariant verification are O(n). The stored root height makes the height query O(1).

## Space usage

- Stack: O(c) capacity storage.
- BST: O(n) nodes; recursive search/insert/delete/traversal may use O(h) call stack.
- AVL: O(n) nodes; recursion depth is O(log n) for valid AVL trees.
- Deep copying a tree requires O(n) allocations and O(n) time.
- Moving a tree transfers root ownership in O(1).

These are asymptotic bounds. They do not include allocator overhead, cache behavior, or constant factors. For performance comparisons, use a controlled benchmark and record compiler, optimization flags, machine, input distribution, and repetitions.
