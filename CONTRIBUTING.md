# Contributing

Create a focused branch and explain the data-structure behavior changed. Preserve the existing public API unless a breaking change is intentional and documented. Keep ownership clear for every allocated node and test empty, full, duplicate, and deletion cases.

Compile with warnings enabled before opening a pull request:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic asim_library.cpp main.cpp -o asim-library
```

Do not commit compiled binaries, IDE state, or generated files. Report security issues privately through [SECURITY.md](./SECURITY.md).
