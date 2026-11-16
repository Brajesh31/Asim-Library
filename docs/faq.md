# ❓ Frequently asked questions

## Is this a production-ready STL replacement?

No. It is an educational integer data-structures library. Prefer the C++ standard library's containers for production application code unless there is a specific requirement to use these implementations.

## Which C++ version is required?

C++17 or later, as declared in the CMake target.

## Do I need CMake?

CMake 3.16 or later is the supported project build path. GCC/Clang direct compilation commands are also documented.

## Does the library have external dependencies?

No third-party runtime dependencies are required.

## Does it store data permanently?

No. All values are in memory and are released when objects are cleared or destroyed.

## Are duplicate tree keys stored?

No. Duplicate insertions into BST and AVLTree are ignored.

## What happens when the stack is full?

push throws std::overflow_error.

## What happens when pop or peek is called on an empty stack?

They throw std::underflow_error. The old -1 sentinel behavior has been removed because -1 can be a valid stack value.

## Are trees copyable?

Yes. Copying performs a deep copy, so the new tree owns independent nodes.

## Are trees movable?

Yes. Moving transfers ownership and leaves the source empty.

## Does the BST self-balance?

No. Sorted input can produce a height-n tree. Use AVLTree when worst-case logarithmic height is required.

## How can I check the AVL invariant?

Call isBalanced(). It checks every node and takes O(n) time.

## Does the library support strings or custom objects?

Not currently. All structures store integers.

## Is there a database or networking layer?

No. This is a local in-memory C++ library.

## Where are automated tests?

In tests/test_asim_library.cpp. Build and run them using CMake and CTest.
