# Lab Index

This document lists all ReverseLogic-Lab exercises and summarizes the main concept, evidence, and learning outcome of each lab.

---

## Lab Summary Table

| Lab | Name | Main Concept | Evidence |
|---|---|---|---|
| 01 | Simple Password Check | direct string comparison | Ghidra main function, runtime tests |
| 02 | XOR Encoded String | runtime decoding | Ghidra analysis, x64dbg verification |
| 03 | Stack Strings | string built on stack | Ghidra helper function analysis |
| 04 | Anti-Debugging Check | `IsDebuggerPresent` | Ghidra API import and branch analysis |
| 05 | Windows API Behavior | system information APIs | Ghidra imports and runtime output |
| 06 | Command-Line Password | `argc` and `argv` | Ghidra argument analysis, runtime tests |
| 07 | License Key Pattern | multiple validation checks | `strlen`, `strncmp`, character checks |
| 08 | Switch Case Control Flow | numeric branch logic | `atoi`, branch reconstruction |
| 09 | Checksum Validation | ASCII sum validation | checksum loop, `0x149` comparison |
| 10 | Encoded API Message | XOR plus Windows API usage | decode loop, `MessageBoxA`, runtime output |

---

## Lab 01 - Simple Password Check

Folder:

```text
labs/01-simple-password/
```

Main idea:

```text
A direct password comparison can be recovered by finding visible strings and strcmp usage.
```

Concepts:

- user input
- hardcoded password
- `strcmp`
- visible strings
- basic if/else logic

Evidence:

- Ghidra main function screenshot
- runtime test screenshot
- analysis documentation

---

## Lab 02 - XOR Encoded String

Folder:

```text
labs/02-xor-encoded-string/
```

Main idea:

```text
A string can be hidden as encoded bytes and decoded at runtime.
```

Concepts:

- XOR encoding
- XOR key
- byte arrays
- decode loop
- decoded buffer
- runtime verification

Evidence:

- Ghidra main function
- Ghidra decode function
- runtime tests
- x64dbg verification

---

## Lab 03 - Stack Strings

Folder:

```text
labs/03-stack-strings/
```

Main idea:

```text
A string can be built character by character instead of being stored as a normal readable string.
```

Concepts:

- stack strings
- local buffers
- character writes
- ASCII values
- runtime string construction

Evidence:

- Ghidra main function
- Ghidra string builder function
- runtime tests
- analysis documentation

---

## Lab 04 - Anti-Debugging Check

Folder:

```text
labs/04-anti-debugging/
```

Main idea:

```text
A program can check whether it is running under a debugger.
```

Concepts:

- `IsDebuggerPresent`
- Windows API import
- debugger detection
- conditional program behavior
- anti-analysis basics

Evidence:

- Ghidra main function
- Ghidra API call
- normal runtime execution
- analysis documentation

---

## Lab 05 - Windows API Behavior

Folder:

```text
labs/05-windows-api-behavior/
```

Main idea:

```text
Imported Windows API calls reveal useful information about program behavior.
```

Concepts:

- `GetComputerNameA`
- `GetWindowsDirectoryA`
- `GetSystemDirectoryA`
- `GetCurrentProcessId`
- API import analysis
- system information behavior

Evidence:

- Ghidra main function
- Ghidra import view
- runtime output
- analysis documentation

---

## Lab 06 - Command-Line Password

Folder:

```text
labs/06-command-line-password/
```

Main idea:

```text
Command-line arguments can be analyzed through argc and argv in decompiled code.
```

Concepts:

- `argc`
- `argv`
- `argv[1]`
- usage message
- command-line password validation
- `strcmp`

Evidence:

- Ghidra main function
- Ghidra `argv[1]` and `strcmp` analysis
- runtime tests
- analysis documentation

---

## Lab 07 - License Key Pattern

Folder:

```text
labs/07-license-key-pattern/
```

Main idea:

```text
A license key can be validated through length, prefix, separator, and character checks.
```

Concepts:

- `strlen`
- `strncmp`
- fixed pattern validation
- direct character comparisons
- helper validation function

Evidence:

- Ghidra main function
- Ghidra validation function
- runtime tests
- analysis documentation

---

## Lab 08 - Switch Case Control Flow

Folder:

```text
labs/08-switch-case-control-flow/
```

Main idea:

```text
Switch-case style logic may appear as a chain of branches in decompiled output.
```

Concepts:

- `atoi`
- numeric input
- switch-case behavior
- default case
- branch reconstruction

Evidence:

- Ghidra main function
- runtime tests for valid and invalid options
- analysis documentation

---

## Lab 09 - Checksum Validation

Folder:

```text
labs/09-checksum-validation/
```

Main idea:

```text
A program can validate input by checking a calculated checksum instead of comparing strings directly.
```

Concepts:

- checksum loop
- ASCII values
- `sum += input[i]`
- constant comparison
- `0x149`
- `strlen` restriction

Evidence:

- Ghidra main function
- Ghidra checksum function
- runtime tests
- analysis documentation

---

## Lab 10 - Encoded API Message

Folder:

```text
labs/10-encoded-api-message/
```

Main idea:

```text
Encoded data can be decoded at runtime and passed to a Windows API function.
```

Concepts:

- XOR encoded message
- decode loop
- local decoded buffer
- `MessageBoxA`
- Windows API import analysis
- runtime output

Evidence:

- Ghidra main function
- Ghidra decode function
- Ghidra `MessageBoxA` import
- runtime output
- analysis documentation

---

## Overall Coverage

The 10 labs provide foundation-level practice in:

- string analysis
- encoded data recovery
- local buffer analysis
- command-line argument analysis
- branch analysis
- loop analysis
- Windows API analysis
- basic anti-debugging analysis
- technical documentation
- GitHub pull request workflow
