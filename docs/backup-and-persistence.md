# 💾 Backup and persistence strategy

## Current state

Asim-Library holds its values in process memory. It has no database, file persistence, snapshot format, or backup automation. Stack and tree contents are released when cleared or when their owning objects are destroyed.

## If a consumer requires persistence

Serialize logical values, not raw pointers, object memory, or compiler-dependent layouts. A future format should define:
- Format version and structure type.
- Item count and integer encoding.
- Deterministic ordering.
- Validation limits for input sizes.
- Behavior for duplicates and malformed values.
- Error reporting for truncated/corrupt input.

For tree recovery, rebuild nodes through validated operations or a dedicated builder. Do not trust serialized pointers or stored node heights. Recalculate AVL heights and validate the balance invariant after loading.

## Recovery tests

- Empty and single-element structures.
- Negative and large integer values.
- Duplicate values and documented duplicate policy.
- Malformed and truncated input.
- Unsupported format version.
- Round-trip in-order equality.
- AVL balance verification after restore.

Persistence is a potential extension, not a current library feature.
