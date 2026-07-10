# ReverseLogic-Lab

ReverseLogic-Lab is an educational reverse engineering project focused on understanding how simple program logic appears inside compiled Windows binaries.

The goal of this project is not to crack real software.

The goal is to learn how compiled programs represent conditions, strings, function calls, command-line arguments, user input, Windows API calls, control flow, encoded data, and basic anti-analysis behavior.

This repository uses small C programs, compiled Windows executables, Ghidra analysis, runtime testing, screenshots, Markdown documentation, Git, and GitHub pull requests.

---

## Project Purpose

This repository demonstrates a basic reverse engineering workflow:

```text
Source Code -> Compiled Binary -> Runtime Test -> Static Analysis -> Documentation
```

Each lab contains a small C program and an analysis document explaining how the logic can be recovered from the binary.

The project is designed for learning, documentation practice, and portfolio development.

---

## Tools Used

The project uses:

- C
- GCC / MinGW through MSYS2
- Ghidra
- x64dbg
- Windows executables
- Windows API
- Markdown documentation
- Git and GitHub
- Pull request based workflow

---

## Current Labs

### Lab 01 - Simple Password Check

This lab demonstrates how a simple password check can be identified inside a compiled executable.

Main concepts:

- user input
- hardcoded password
- `strcmp`
- visible strings
- basic if/else logic
- Ghidra decompiler output

Lab folder:

```text
labs/01-simple-password/
```

---

### Lab 02 - XOR Encoded String

This lab demonstrates how a password can be hidden using a simple XOR encoding technique.

Main concepts:

- encoded byte arrays
- XOR key
- runtime decoding
- decoded buffers
- `strcmp` with a decoded string
- Ghidra static analysis
- x64dbg runtime verification

Lab folder:

```text
labs/02-xor-encoded-string/
```

---

### Lab 03 - Stack Strings

This lab demonstrates how a password can be built character by character at runtime instead of being stored as a normal string.

Main concepts:

- stack strings
- local character buffers
- character-by-character writes
- ASCII hex values
- hidden runtime string creation
- Ghidra function analysis

Lab folder:

```text
labs/03-stack-strings/
```

---

### Lab 04 - Anti-Debugging Check

This lab demonstrates a simple Windows anti-debugging check using `IsDebuggerPresent`.

Main concepts:

- Windows API usage
- `IsDebuggerPresent`
- imported API analysis
- conditional behavior based on debugger detection
- Ghidra import and control flow analysis

Lab folder:

```text
labs/04-anti-debugging/
```

---

### Lab 05 - Windows API Behavior

This lab demonstrates basic Windows API behavior analysis.

Main concepts:

- imported Windows APIs
- `GetComputerNameA`
- `GetWindowsDirectoryA`
- `GetSystemDirectoryA`
- `GetCurrentProcessId`
- system information collection
- behavior analysis through API usage

Lab folder:

```text
labs/05-windows-api-behavior/
```

---

### Lab 06 - Command-Line Password

This lab demonstrates how a password can be validated through command-line arguments.

Main concepts:

- `argc`
- `argv`
- command-line input
- `argv[1]`
- `strcmp`
- usage messages
- Ghidra argument analysis

Lab folder:

```text
labs/06-command-line-password/
```

---

### Lab 07 - License Key Pattern

This lab demonstrates how a fixed license key pattern can be validated through multiple smaller checks.

Main concepts:

- command-line key input
- `strlen`
- `strncmp`
- prefix checks
- separator checks
- direct character comparisons
- validation function analysis

Lab folder:

```text
labs/07-license-key-pattern/
```

---

### Lab 08 - Switch Case Control Flow

This lab demonstrates how switch-case style control flow appears inside a compiled binary.

Main concepts:

- menu-based options
- `atoi`
- numeric input conversion
- switch-case logic
- branch reconstruction
- default case behavior
- Ghidra control flow analysis

Lab folder:

```text
labs/08-switch-case-control-flow/
```

---

### Lab 09 - Checksum Validation

This lab demonstrates how input validation can be performed with a checksum calculation instead of a direct string comparison.

Main concepts:

- loop-based validation
- ASCII values
- checksum calculation
- `sum += input[i]`
- comparison against a constant
- hexadecimal constants in Ghidra
- `strlen` restriction

Lab folder:

```text
labs/09-checksum-validation/
```

---

### Lab 10 - Encoded API Message

This lab combines encoded string recovery with Windows API behavior analysis.

Main concepts:

- XOR encoded message
- runtime decoding
- decode loop
- local decoded buffer
- `MessageBoxA`
- Windows API import analysis
- runtime output verification

Lab folder:

```text
labs/10-encoded-api-message/
```

---

## Repository Structure

```text
ReverseLogic-Lab/
│
├── README.md
│
├── docs/
│
├── tools/
│
└── labs/
    │
    ├── 01-simple-password/
    │   ├── source.c
    │   ├── analysis.md
    │   └── screenshots/
    │
    ├── 02-xor-encoded-string/
    │   ├── source.c
    │   ├── analysis.md
    │   └── screenshots/
    │
    ├── 03-stack-strings/
    │   ├── source.c
    │   ├── analysis.md
    │   └── screenshots/
    │
    ├── 04-anti-debugging/
    │   ├── source.c
    │   ├── analysis.md
    │   └── screenshots/
    │
    ├── 05-windows-api-behavior/
    │   ├── source.c
    │   ├── analysis.md
    │   └── screenshots/
    │
    ├── 06-command-line-password/
    │   ├── source.c
    │   ├── analysis.md
    │   └── screenshots/
    │
    ├── 07-license-key-pattern/
    │   ├── source.c
    │   ├── analysis.md
    │   └── screenshots/
    │
    ├── 08-switch-case-control-flow/
    │   ├── source.c
    │   ├── analysis.md
    │   └── screenshots/
    │
    ├── 09-checksum-validation/
    │   ├── source.c
    │   ├── analysis.md
    │   └── screenshots/
    │
    └── 10-encoded-api-message/
        ├── source.c
        ├── analysis.md
        └── screenshots/
```

Compiled `.exe` files are not tracked in Git. They are ignored through `.gitignore`.

---

## General Lab Workflow

The workflow used in this repository is:

1. Write a small C program.
2. Compile it into a Windows executable.
3. Run the program and capture runtime behavior.
4. Open the executable in Ghidra.
5. Run auto-analysis.
6. Inspect strings, functions, imports, arguments, and control flow.
7. Compare source logic with decompiled logic.
8. Capture screenshots.
9. Write an analysis document.
10. Open a pull request and merge through the normal GitHub flow.

---

## Build Example

Each lab can be built with GCC through MSYS2 MinGW64.

Example:

```bash
gcc -Wall -Wextra -O0 -g labs/10-encoded-api-message/source.c -o labs/10-encoded-api-message/encoded_api_message.exe -luser32
```

Run example:

```bash
./labs/10-encoded-api-message/encoded_api_message.exe
```

The exact executable name changes depending on the lab.

---

## Reverse Engineering Concepts Covered

This repository currently covers:

- hardcoded string comparison
- password checking logic
- `strcmp`
- XOR encoded strings
- runtime decoding
- stack strings
- local buffers
- ASCII and hex character values
- command-line arguments
- `argc` and `argv`
- usage messages
- fixed license key validation
- `strlen`
- `strncmp`
- direct character comparisons
- switch-case control flow
- `atoi`
- branch reconstruction
- checksum validation
- loop-based arithmetic validation
- Windows API imports
- `IsDebuggerPresent`
- `MessageBoxA`
- `GetComputerNameA`
- `GetWindowsDirectoryA`
- `GetSystemDirectoryA`
- `GetCurrentProcessId`
- basic anti-debugging behavior
- behavior analysis through imported APIs
- Ghidra decompiler analysis
- x64dbg runtime inspection

---

## Completed Pull Requests

The project was developed through pull requests instead of direct commits to `main`.

Completed work includes:

```text
PR #1  - feat: add xor encoded string lab
PR #2  - docs: add xor dynamic analysis
PR #3  - feat: add stack strings lab
PR #4  - feat: add anti-debugging lab
PR #5  - feat: add windows api behavior lab
PR #6  - docs: update reverse logic lab readme
PR #7  - feat: add command line password lab
PR #8  - feat: add license key pattern lab
PR #9  - feat: add switch case control flow lab
PR #10 - feat: add checksum validation lab
PR #11 - feat: add encoded api message lab
```

Pull request numbers may change if additional documentation updates are merged.

---

## Educational Scope

This project is for learning and portfolio purposes.

It focuses on:

- understanding compiled binaries
- reading decompiled code
- identifying string references
- recognizing simple control flow
- analyzing imported APIs
- understanding basic anti-analysis logic
- documenting reverse engineering findings clearly

This project does not target real commercial software and does not include illegal cracking activity.

---

## Status

Current status:

```text
Lab 01 completed
Lab 02 completed
Lab 03 completed
Lab 04 completed
Lab 05 completed
Lab 06 completed
Lab 07 completed
Lab 08 completed
Lab 09 completed
Lab 10 completed
```

ReverseLogic-Lab foundation phase is completed.

Future work may continue with more advanced malware analysis topics such as PE structure, API hooking, process injection, unpacking basics, persistence techniques, and dynamic analysis reports.

---

## Git Workflow

All changes are developed through feature or documentation branches.

The expected workflow is:

```text
main -> feature branch -> pull request -> squash and merge -> main
```

Commit messages follow the conventional commit format.

Examples:

```text
feat: add stack strings lab
docs: add xor dynamic analysis
fix: improve documentation wording
docs: finalize reverse logic lab documentation
```