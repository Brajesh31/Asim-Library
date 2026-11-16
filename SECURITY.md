# 🔐 Security policy

## Project scope

Asim-Library is a local C++ data-structures library. It does not operate a server, process network requests, store credentials, or access a database. Its primary security concerns are memory safety, undefined behavior, input validation, and safe ownership.

## Reporting a vulnerability

Report a security issue privately through https://github.com/Brajesh31/Asim-Library/security/advisories/new. Avoid posting a working exploit or sensitive information in a public issue before a fix is available.

Include:
- Affected commit or version.
- Compiler and platform.
- Relevant input sequence.
- Expected and observed behavior.
- Sanitizer output or minimal reproduction, with unrelated data removed.

## Current defensive measures

- Stack rejects negative capacity.
- Stack overflow and underflow are explicit exceptions.
- Tree owners release allocated nodes.
- Tree copies are deep copies.
- Tree moves transfer ownership and empty the source.
- Automated CI runs AddressSanitizer and UndefinedBehaviorSanitizer on supported runners.
- Build uses compiler warning flags.

These measures reduce known risks but do not constitute a formal security audit.

## Safe use

- Treat values read from files or external input as untrusted.
- Bound input sizes in consuming applications.
- Do not expose internal node pointers as long-lived handles.
- Synchronize access when sharing objects across threads.
- Use a maintained compiler and standard library.
- Run sanitizers when adding pointer-manipulation logic.

## Supported versions

The default branch is maintained. Formal release/support windows will be defined when tagged releases are published.
