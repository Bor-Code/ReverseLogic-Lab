# Tooling Notes

This document summarizes the tools used in ReverseLogic-Lab and explains how each tool contributed to the project.

---

## MSYS2 MinGW64

MSYS2 MinGW64 was used as the Windows build environment.

Purpose:

- provide GCC on Windows
- compile C source files into Windows executables
- run command-line tests
- build small lab binaries consistently

Example command:

```bash
gcc -Wall -Wextra -O0 -g labs/09-checksum-validation/source.c -o labs/09-checksum-validation/checksum_check.exe
```

For labs using Windows UI APIs, the `user32` library was linked.

Example:

```bash
gcc -Wall -Wextra -O0 -g labs/10-encoded-api-message/source.c -o labs/10-encoded-api-message/encoded_api_message.exe -luser32
```

---

## GCC

GCC was used to compile the lab programs.

Flags used:

| Flag | Purpose |
|---|---|
| `-Wall` | enable common warnings |
| `-Wextra` | enable additional warnings |
| `-O0` | disable optimization for easier analysis |
| `-g` | include debug information for local analysis |

The `-O0` flag was useful because optimized binaries can make decompiled output harder to read during beginner reverse engineering practice.

---

## Ghidra

Ghidra was the main static analysis tool.

Used for:

- importing Windows executables
- running auto-analysis
- viewing decompiled C-like output
- inspecting functions
- inspecting strings
- inspecting imported APIs
- analyzing control flow
- analyzing constants
- capturing evidence screenshots

Common Ghidra targets:

```text
main function
helper functions
decode functions
validation functions
Windows API imports
string references
branch conditions
```

Ghidra was especially useful for identifying:

- `strcmp`
- `strlen`
- `strncmp`
- `atoi`
- XOR decode loops
- checksum loops
- `IsDebuggerPresent`
- `MessageBoxA`
- other Windows API imports

---

## x64dbg

x64dbg was used for selected runtime verification.

It was especially useful in the XOR encoded string lab, where runtime inspection helped confirm that the decoded password existed in memory before comparison.

Used for:

- setting breakpoints
- observing runtime behavior
- verifying decoded data
- comparing static and dynamic analysis findings

x64dbg was not required for every lab. The project mainly used Ghidra static analysis and terminal runtime tests.

---

## Windows Terminal and PowerShell

Windows terminal tools were used for:

- navigating the repository
- running Git commands
- creating files
- checking project state
- executing compiled programs
- capturing runtime behavior

Common commands:

```powershell
git status
git branch
git add
git commit
git push
```

---

## Git

Git was used for version control.

The project avoided direct commits to `main`.

Main workflow:

```text
main -> feature branch -> pull request -> squash and merge -> main
```

Common branch types:

```text
feat/xor-encoded-string-lab
feat/checksum-validation-lab
docs/finalize-reverse-logic-lab
```

Common commit types:

```text
feat: add stack strings lab
feat: add checksum validation lab
docs: finalize reverse logic lab documentation
```

---

## GitHub

GitHub was used to manage the project through pull requests.

Used for:

- pushing branches
- opening pull requests
- adding reviewers
- reviewing changes
- merging branches into `main`
- keeping the project history organized

This workflow made the project more professional and easier to audit.

---

## Markdown

Markdown was used for all documentation.

Used for:

- `README.md`
- lab `analysis.md` files
- methodology documentation
- weekly recap
- tooling notes
- lab index

Markdown made the project easier to read directly on GitHub.

---

## Screenshots

Screenshots were used as analysis evidence.

Types of screenshots:

- Ghidra decompiler output
- Ghidra import view
- runtime terminal output
- Windows API popup output
- x64dbg runtime verification

Screenshot naming was kept simple and descriptive.

Examples:

```text
01-ghidra-main-function.png
02-ghidra-decode-message-function.png
03-runtime-tests.png
04-runtime-output.png
```

---

## Tooling Summary

| Tool | Role |
|---|---|
| MSYS2 MinGW64 | Windows C build environment |
| GCC | C compiler |
| Ghidra | static reverse engineering |
| x64dbg | selected runtime verification |
| PowerShell | file and Git operations |
| Git | version control |
| GitHub | pull requests and review workflow |
| Markdown | project documentation |

---

## Lessons Learned from Tooling

The main tooling lessons were:

- small binaries are easier to analyze while learning
- `-O0` makes decompiled logic easier to follow
- Ghidra is strong for static analysis and API inspection
- x64dbg is useful when runtime verification is needed
- screenshots make analysis easier to review later
- consistent file naming improves project readability
- pull requests make technical progress easier to track
