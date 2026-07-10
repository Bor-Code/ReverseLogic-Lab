# Methodology

## Purpose

This document explains the methodology used in ReverseLogic-Lab.

The project follows a repeatable analysis workflow for small Windows executables. Each lab starts with a controlled C program and ends with a documented reverse engineering report.

The goal is to build technical understanding through source code, compiled binaries, runtime behavior, static analysis, screenshots, and written documentation.

---

## Workflow Summary

The general workflow is:

```text
Source Code -> Build -> Runtime Test -> Static Analysis -> Documentation -> Pull Request
```

This workflow was used to keep every lab consistent and reviewable.

---

## Step 1 - Write a Small C Program

Each lab begins with a focused C program.

The program is intentionally small so that one concept can be studied clearly.

Examples of focused concepts:

- direct password comparison
- XOR string decoding
- stack string construction
- command-line validation
- license key pattern checking
- checksum validation
- Windows API behavior

Keeping the program small makes the compiled output easier to understand.

---

## Step 2 - Compile the Program

The source code is compiled into a Windows executable using GCC through MSYS2 MinGW64.

Example build command:

```bash
gcc -Wall -Wextra -O0 -g labs/10-encoded-api-message/source.c -o labs/10-encoded-api-message/encoded_api_message.exe -luser32
```

The `-O0` flag is used to reduce compiler optimization.

This makes the decompiled output easier to read during early reverse engineering practice.

Compiled `.exe` files are not committed to Git.

---

## Step 3 - Run Runtime Tests

After compilation, the executable is tested from the terminal.

Runtime testing confirms the expected behavior before opening the binary in Ghidra.

Example runtime checks:

```text
missing argument
wrong input
correct input
API popup behavior
```

Runtime screenshots are captured and stored in the lab's `screenshots` folder.

---

## Step 4 - Import the Binary into Ghidra

The compiled executable is imported into Ghidra.

After import, auto-analysis is run.

The analysis focuses on:

- `main` function
- helper functions
- visible strings
- imported functions
- condition checks
- loop structures
- constants
- API calls

---

## Step 5 - Analyze Decompiled Logic

The decompiled output is compared with the original source behavior.

Important details include:

- how `strcmp` appears in decompiled code
- how `argv[1]` appears in Ghidra
- how `strlen` checks are represented
- how XOR loops are reconstructed
- how switch-case logic may appear as branch chains
- how hexadecimal constants map to decimal values
- how API imports reveal behavior

The goal is not only to find the answer, but to explain how the answer can be recovered from the binary.

---

## Step 6 - Capture Screenshots

Screenshots are used as evidence.

Common screenshot types:

- Ghidra main function
- helper function analysis
- imported API view
- runtime terminal output
- debugger verification when needed

Screenshot names follow a clear pattern:

```text
01-ghidra-main-function.png
02-ghidra-helper-function.png
03-runtime-tests.png
```

Some labs use different names depending on the evidence required.

---

## Step 7 - Write analysis.md

Each lab includes an `analysis.md` file.

The analysis file explains:

- goal of the lab
- source code logic
- runtime behavior
- Ghidra findings
- important reverse engineering observations
- screenshots
- final conclusion

The documentation is written so the lab can be understood later without reopening the entire project.

---

## Step 8 - Use Git Branches and Pull Requests

Each meaningful change is developed in a branch.

The expected flow is:

```text
main -> feature branch -> pull request -> squash and merge -> main
```

Examples:

```text
feat/xor-encoded-string-lab
feat/checksum-validation-lab
docs/finalize-reverse-logic-lab
```

This prevents direct commits to `main` and keeps the project history reviewable.

---

## Step 9 - Review and Merge

After the branch is pushed, a pull request is opened.

The pull request includes:

- summary of changes
- evidence added
- notes about workflow
- reviewer assignment

After review, the branch is merged into `main`.

---

## Why This Methodology Matters

This methodology shows more than code writing.

It shows the full analysis process:

- building a test binary
- observing behavior
- analyzing the compiled result
- documenting findings
- preserving evidence
- using a professional Git workflow

This makes the project useful as both a learning record and a portfolio artifact.
