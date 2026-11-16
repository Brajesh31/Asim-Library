# 🗄️ Database and persistence

Asim-Library does not use a database. It is a local C++ data-structures library whose Stack, BST, and AVLTree instances hold data in process memory.

## Lifetime and ownership

- Stack storage is managed by its std::vector member.
- BST nodes are owned by the BST instance.
- AVL nodes are owned by the AVLTree instance.
- clear() releases current contents.
- Destructors release owned memory automatically.
- Copying a tree creates a separate deep copy.
- Moving transfers the tree root and empties the source.

## Persistence is intentionally outside scope

The current API does not serialize structures, read/write files, connect to databases, or restore a tree from a snapshot. Consumers requiring persistence must define a format and validate input before constructing nodes.

## Safe future serialization considerations

If persistence is added, version the serialized format, validate node counts and integer ranges, reject malformed/cyclic data, never deserialize raw memory layouts, rebuild AVL heights, and test round trips plus corrupt/truncated input.

No database schema, SQL migration, cloud storage, or connection configuration exists in this repository.
