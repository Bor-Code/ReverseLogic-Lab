# ReverseLogic-Lab

ReverseLogic-Lab is an educational reverse engineering project focused on understanding how simple program logic appears inside compiled binaries.

The goal of this project is not to crack real software.  
The goal is to learn how compiled programs represent conditions, strings, function calls, user input, and decision logic.

This project uses small C programs, compiled Windows executables, Ghidra analysis, and step-by-step write-ups.

---

## Project Purpose

This repository demonstrates the basic reverse engineering workflow:

```text
Source Code → Compiled Binary → Strings → Functions → Decompiler Output → Program Logic
```

Each lab contains a small program and an analysis document explaining how the logic can be recovered from the binary.

---

## Tools Used

The project uses:

- C
- GCC / MinGW through MSYS2
- Ghidra
- Windows executables
- Markdown documentation
- Git and GitHub

---

## Current Labs

### Lab 01 - Simple Password Check

This lab demonstrates how a simple password check can be identified inside a compiled executable.

The program asks the user for a password and compares the entered value with a hardcoded password.

Important concepts:

- user input
- string comparison
- `strcmp`
- hardcoded strings
- Ghidra decompiler output
- basic if/else decision logic

Lab folder:

```text
labs/01-simple-password/
```

Files:

```text
source.c
simple_password.exe
analysis.md
```

---

## Lab 01 Summary

The original program contains this logic:

```c
if (strcmp(input, "bora123") == 0) {
    printf("Access granted\n");
} else {
    printf("Access denied\n");
}
```

After compiling and opening the executable in Ghidra, the same logic can be recovered from the decompiler output.

This shows that even when the source code is not available, strings and function calls can reveal important information about program behavior.

---

## Repository Structure

```text
ReverseLogic-Lab/
│
├── README.md
│
├── labs/
│   └── 01-simple-password/
│       ├── source.c
│       ├── simple_password.exe
│       ├── analysis.md
│       └── screenshots/
│
├── tools/
│
└── docs/
```

---

## How to Build Lab 01

Go to the lab folder:

```bash
cd labs/01-simple-password
```

Compile the source code:

```bash
gcc source.c -o simple_password.exe
```

Run the program:

```bash
./simple_password.exe
```

Example output:

```text
Enter password:
```

If the correct password is entered:

```text
Access granted
```

If the wrong password is entered:

```text
Access denied
```

---

## Reverse Engineering Workflow

The basic workflow used in this project is:

1. Write a small C program.
2. Compile it into a Windows executable.
3. Open the executable in Ghidra.
4. Run auto-analysis.
5. Search for useful strings.
6. Find the function that references those strings.
7. Read the decompiler output.
8. Identify the decision logic.
9. Document the analysis.

---

## Educational Scope

This project is for learning and portfolio purposes.

It focuses on:

- understanding binaries
- reading decompiled code
- identifying string references
- recognizing simple control flow
- explaining reverse engineering logic clearly

This project does not target real commercial software and does not include illegal cracking activity.

---

## Status

Current status:

```text
Lab 01 completed
More labs planned
```

Planned future labs:

- XOR encoded string
- switch-case logic
- simple license key check
- basic anti-debugging logic
- control flow graph notes