# Asim-Library

Asim-Library is a small educational C++ data-structures library. The current source implements a fixed-capacity integer stack, a binary search tree, and an AVL tree, with a console demonstration in `main.cpp`.

## Components

- `asim_library.h` — public class declarations and node types.
- `asim_library.cpp` — stack, BST, and AVL implementations.
- `main.cpp` — sample program that pushes, rotates, pops, traverses, searches, and deletes.

The current API uses raw pointers, `using namespace std`, console output, and integer-only values. It is suitable for learning and experimentation, not a production generic container library.

## Build and run

No build system is checked in. With a C++17 compiler:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic asim_library.cpp main.cpp -o asim-library
./asim-library
```

On Windows with MinGW:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic asim_library.cpp main.cpp -o asim-library.exe
.\asim-library.exe
```

See [docs/installation.md](./docs/installation.md) and [docs/development.md](./docs/development.md).

## License

MIT License. See [LICENSE](./LICENSE).

## Maintainer

Brajesh Kumar — [@brajesh31](https://github.com/brajesh31)

Last updated: 2026-10-14 19:51 UTC
