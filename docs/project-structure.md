# 🗂️ Project structure

This guide documents the actual repository layout. Generated CMake build files and local IDE caches are excluded.

~~~text
Asim-Library/
├── .github/
│   ├── ISSUE_TEMPLATE/
│   ├── workflows/
│   │   ├── ci.yml
│   │   ├── documentation.yml
│   │   └── security.yml
│   └── PULL_REQUEST_TEMPLATE.md
├── assets/
│   └── asim-library-banner.svg
├── docs/
│   ├── ADRs/
│   ├── diagrams/
│   ├── accessibility.md
│   ├── algorithms.md
│   ├── api.md
│   ├── architecture.md
│   ├── backup-and-persistence.md
│   ├── complexity.md
│   ├── database.md
│   ├── deployment.md
│   ├── design-decisions.md
│   ├── development.md
│   ├── faq.md
│   ├── installation.md
│   ├── limitations.md
│   ├── project-structure.md
│   ├── testing.md
│   └── troubleshooting.md
├── tests/
│   └── test_asim_library.cpp
├── asim_library.h
├── asim_library.cpp
├── main.cpp
├── CMakeLists.txt
├── .editorconfig
├── .env.example
├── .gitattributes
├── .gitignore
├── CHANGELOG.md
├── CITATION.cff
├── CODEOWNERS
├── CODE_OF_CONDUCT.md
├── CONTRIBUTING.md
├── LICENSE
├── README.md
├── ROADMAP.md
├── SECURITY.md
└── SUPPORT.md
~~~

## Component responsibilities

| Area | Responsibility |
|---|---|
| Header | Public declarations and class contracts |
| Implementation | Data structure algorithms and node ownership |
| Demo | Readable examples of representative operations |
| Tests | Regression coverage and invariant assertions |
| CMake | Compiler standard, build targets and test registration |
| Docs | API, algorithm, complexity, build and maintenance guidance |
| GitHub workflows | Build/test, documentation validation and secret scanning |
| Assets | Original banner and editable algorithm diagrams |

## Future source organization

If the project grows, files could be split by data structure or organized under include/ and src/. Do this only when it improves maintainability and preserve a simple consumer include path.
