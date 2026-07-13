# ReverseLogic-Lab

ReverseLogic-Lab is an educational reverse engineering project focused on analyzing small Windows executables and documenting how program logic appears after compilation.

The project follows a simple workflow:

```text
Source Code -> Compiled Binary -> Runtime Test -> Ghidra Analysis -> Documentation -> Pull Request
```

<div align="center">
  
**🔴 PLEASE USE GHIDRA AND X64DBG TOOLS FOR EDUCATIONAL PURPOSES ONLY. 🔴**

</div>

The goal is not to crack real software.

The goal is to learn how compiled programs represent strings, function calls, command-line arguments, control flow, encoded data, checksum logic, and Windows API behavior.

---

## Project Scope

This repository contains 10 focused reverse engineering labs.

Each lab includes:

- a small C source file
- a compiled Windows executable for local testing, not tracked in Git
- Ghidra static analysis
- runtime test evidence
- screenshots
- an `analysis.md` report

Compiled `.exe` files are intentionally ignored through `.gitignore`.

---

## Tools Used

- C
- GCC / MinGW through MSYS2
- Ghidra
- x64dbg
- Windows executables
- Windows API
- Markdown
- Git
- GitHub pull requests

---

## Labs

| Lab | Topic | Main Focus |
|---|---|---|
| Lab 01 | Simple Password Check | `strcmp`, visible strings, basic branching |
| Lab 02 | XOR Encoded String | XOR decoding, hidden strings, runtime verification |
| Lab 03 | Stack Strings | character-by-character string construction |
| Lab 04 | Anti-Debugging Check | `IsDebuggerPresent`, anti-debugging logic |
| Lab 05 | Windows API Behavior | imported APIs and behavior analysis |
| Lab 06 | Command-Line Password | `argc`, `argv`, command-line validation |
| Lab 07 | License Key Pattern | `strlen`, `strncmp`, direct character checks |
| Lab 08 | Switch Case Control Flow | `atoi`, numeric options, branch reconstruction |
| Lab 09 | Checksum Validation | ASCII sum, loop-based validation, hex constants |
| Lab 10 | Encoded API Message | XOR decoding combined with `MessageBoxA` |

---

## Repository Structure

```text
ReverseLogic-Lab/
│
├── README.md
│
├── docs/
│   ├── lab-index.md
│   ├── methodology.md
│   ├── tooling-notes.md
│   └── week-1-security-recap.md
│
└── labs/
    ├── 01-simple-password/
    ├── 02-xor-encoded-string/
    ├── 03-stack-strings/
    ├── 04-anti-debugging/
    ├── 05-windows-api-behavior/
    ├── 06-command-line-password/
    ├── 07-license-key-pattern/
    ├── 08-switch-case-control-flow/
    ├── 09-checksum-validation/
    └── 10-encoded-api-message/
```

---

## Documentation

Detailed project documentation is available in the `docs` folder.

| Document | Purpose |
|---|---|
| `docs/lab-index.md` | Lists all labs with topics, concepts, and evidence |
| `docs/methodology.md` | Explains the reverse engineering workflow used in the project |
| `docs/tooling-notes.md` | Documents the tools used during development and analysis |
| `docs/week-1-security-recap.md` | Summarizes the completed foundation phase |

---

## Reverse Engineering Concepts Covered

This project covers:

- hardcoded string comparison
- visible strings in binaries
- XOR encoded strings
- runtime decoding
- stack strings
- local character buffers
- command-line arguments
- `argc` and `argv`
- `strcmp`
- `strlen`
- `strncmp`
- `atoi`
- switch-case control flow
- branch reconstruction
- checksum validation
- ASCII values
- hexadecimal constants
- Windows API imports
- `IsDebuggerPresent`
- `MessageBoxA`
- `GetComputerNameA`
- `GetWindowsDirectoryA`
- `GetSystemDirectoryA`
- `GetCurrentProcessId`
- Ghidra decompiler analysis
- x64dbg runtime inspection
- Markdown-based technical reporting

---

## General Workflow

The project follows this workflow for each lab:

1. Write a small C program.
2. Compile it as a Windows executable.
3. Run the executable and capture runtime behavior.
4. Import the binary into Ghidra.
5. Run auto-analysis.
6. Inspect functions, strings, imports, branches, and constants.
7. Compare source behavior with decompiled output.
8. Capture screenshots.
9. Write an `analysis.md` report.
10. Submit the work through a GitHub pull request.

---

## Git Workflow

All changes are developed through branches and pull requests.

Expected workflow:

```text
main -> feature branch -> pull request -> squash and merge -> main
```

Example commit messages:

```text
feat: add xor encoded string lab
feat: add checksum validation lab
docs: finalize reverse logic lab documentation
```

---

## Status

Current status:

```text
Foundation phase completed
10 labs completed
Documentation completed
Analysis screenshots added
Pull request workflow used
```

Future work may continue with more advanced reverse engineering topics such as PE structure, import tables, unpacking basics, API monitoring, process behavior analysis, and malware analysis reports.

---

## Educational Notice

This project is for educational and portfolio purposes.

It does not target real commercial software and does not include illegal cracking activity.
