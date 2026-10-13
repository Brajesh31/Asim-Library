# Security Policy

This is an educational, local C++ library with no network service or credential handling. Report memory-safety, undefined-behavior, or build issues privately to Brajesh Kumar through the [GitHub profile](https://github.com/brajesh31), including compiler, platform, reproduction steps, and impact.

Use compiler warnings and sanitizers when evaluating changes:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic -fsanitize=address,undefined asim_library.cpp main.cpp -o asim-library
```
