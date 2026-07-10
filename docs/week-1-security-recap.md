# Week 1 Security Recap

## Overview

This document summarizes the completed foundation phase of the ReverseLogic-Lab project.

During this phase, 10 educational reverse engineering labs were created, analyzed, documented, and merged through a pull request based GitHub workflow.

The main objective was to understand how simple C program logic appears inside compiled Windows executables and how that logic can be recovered through static and runtime analysis.

---

## Completed Work

The completed labs are:

| Lab | Topic |
|---|---|
| Lab 01 | Simple Password Check |
| Lab 02 | XOR Encoded String |
| Lab 03 | Stack Strings |
| Lab 04 | Anti-Debugging Check |
| Lab 05 | Windows API Behavior |
| Lab 06 | Command-Line Password |
| Lab 07 | License Key Pattern |
| Lab 08 | Switch Case Control Flow |
| Lab 09 | Checksum Validation |
| Lab 10 | Encoded API Message |

Each lab includes:

- source code
- runtime testing
- Ghidra analysis
- screenshots
- analysis documentation

---

## Main Topics Covered

The foundation phase covered the following reverse engineering topics:

- hardcoded password checks
- `strcmp` based validation
- XOR encoded strings
- runtime string decoding
- stack string construction
- anti-debugging checks
- Windows API imports
- command-line argument parsing
- license key pattern validation
- switch-case control flow
- checksum validation
- ASCII and hexadecimal values
- API behavior analysis
- static analysis with Ghidra
- runtime verification with terminal tests
- focused dynamic verification with x64dbg

---

## Tools Used

The work used the following tools:

| Tool | Purpose |
|---|---|
| C | Writing small test programs |
| GCC / MinGW | Compiling Windows executables |
| MSYS2 | Windows development environment |
| Ghidra | Static reverse engineering and decompiler analysis |
| x64dbg | Runtime verification for selected behavior |
| Git | Version control |
| GitHub | Pull request workflow |
| Markdown | Technical documentation |

---

## Workflow Used

The workflow was repeated across the labs:

```text
Write source code
Compile executable
Run runtime tests
Import binary into Ghidra
Analyze functions and control flow
Capture screenshots
Write analysis.md
Commit changes
Open pull request
Merge through GitHub
```

This created a consistent and reviewable structure for the project.

---

## Evidence Produced

The project includes several types of evidence:

- terminal runtime screenshots
- Ghidra decompiler screenshots
- Ghidra import analysis screenshots
- x64dbg runtime verification screenshot for XOR analysis
- written analysis files
- Git commits
- GitHub pull requests

This makes the work easier to review and explain during internship reporting or portfolio review.

---

## Key Learning Outcomes

The completed work improved understanding of:

- how C logic appears after compilation
- how strings are stored or hidden in binaries
- how encoded strings can be recovered
- how command-line input is handled in compiled programs
- how Ghidra represents function calls and branches
- how Windows API imports reveal program behavior
- how basic anti-debugging checks appear in static analysis
- how to document technical findings clearly
- how to use pull requests for controlled project development

---

## Final Result

The ReverseLogic-Lab foundation phase was completed with 10 labs.

The project now demonstrates a complete beginner-to-foundation reverse engineering workflow using small Windows executables, Ghidra analysis, runtime tests, screenshots, documentation, and GitHub pull requests.

This phase is complete and ready to be used as a security learning portfolio milestone.
