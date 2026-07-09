# ReverseLogic-Lab

ReverseLogic-Lab is an educational reverse engineering project focused on understanding how simple program logic appears inside compiled Windows binaries.

The goal of this project is not to crack real software.

The goal is to learn how compiled programs represent conditions, strings, function calls, user input, Windows API calls, and basic anti-analysis behavior.

This repository uses small C programs, compiled Windows executables, Ghidra analysis, runtime testing, screenshots, and step-by-step write-ups.

---

## Project Purpose

This repository demonstrates a basic reverse engineering workflow:

```text
Source Code -> Compiled Binary -> Runtime Test -> Static Analysis -> Documentation
```

Each lab contains a small C program and an analysis document explaining how the logic can be recovered from the binary.

The project is designed for learning and portfolio purposes.

---

## Tools Used

The project uses:

- C
- GCC / MinGW through MSYS2
- Ghidra
- x64dbg
- Windows executables
- Markdown documentation
- Git and GitHub

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
- `strcmp` with a decoded buffer
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

## Repository Structure

```text
ReverseLogic-Lab/
│
├── README.md
│
├── labs/
│   │
│   ├── 01-simple-password/
│   │   ├── source.c
│   │   ├── analysis.md
│   │   └── screenshots/
│   │
│   ├── 02-xor-encoded-string/
│   │   ├── source.c
│   │   ├── analysis.md
│   │   └── screenshots/
│   │
│   ├── 03-stack-strings/
│   │   ├── source.c
│   │   ├── analysis.md
│   │   └── screenshots/
│   │
│   ├── 04-anti-debugging/
│   │   ├── source.c
│   │   ├── analysis.md
│   │   └── screenshots/
│   │
│   └── 05-windows-api-behavior/
│       ├── source.c
│       ├── analysis.md
│       └── screenshots/
│
├── tools/
│
└── docs/
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
6. Inspect strings, functions, imports, and control flow.
7. Compare source logic with decompiled logic.
8. Capture screenshots.
9. Write an analysis document.
10. Open a pull request and merge through the normal GitHub flow.

---

## Build Example

Each lab can be built with GCC through MSYS2 MinGW64.

Example:

```bash
gcc -Wall -Wextra -O0 -g labs/05-windows-api-behavior/source.c -o labs/05-windows-api-behavior/windows_api_behavior.exe
```

Run example:

```bash
./labs/05-windows-api-behavior/windows_api_behavior.exe
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
- Windows API imports
- `IsDebuggerPresent`
- basic anti-debugging behavior
- behavior analysis through imported APIs
- Ghidra decompiler analysis
- x64dbg runtime inspection

---

## Educational Scope

This project is for learning and portfolio purposes.

It focuses on:

- understanding compiled binaries
- reading decompiled code
- identifying string references
- recognizing simple control flow
- analyzing imported APIs
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
```

More labs will be added as the reverse engineering roadmap progresses.

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
docs: update reverse logic lab readme
```
