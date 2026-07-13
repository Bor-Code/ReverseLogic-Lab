# PE Structure Analysis

## Objective

The objective of this lab is to analyze how a simple C program is represented inside a Windows Portable Executable file.

The analysis focuses on:

- Runtime behavior
- Generated assembly instructions
- Windows x64 calling convention
- Imported Windows API functions
- MinGW runtime initialization
- The relationship between the PE entry point and the user-defined `main` function

## Sample Information

- Source language: C
- Compiler: GCC 16.1.0 with MinGW-w64
- Architecture: x86-64
- File format: PE32+
- Subsystem: Windows Console
- Analysis tools: Detect It Easy and Ghidra

## Program Behavior

The program contains:

- An initialized global variable with the value `42`
- An uninitialized global variable
- A constant string
- A function that multiplies an integer by two
- A console output operation using `printf`
- A Windows API call using `MessageBoxA`

The initialized global value is passed to `calculate_value`. The returned result is stored in the uninitialized global variable.

## Runtime Verification

The executable produced the following console output:

```text
PE structure analysis lab
Calculated value: 84
```

The result confirms that the initialized global value `42` was passed to `calculate_value` and multiplied by two.

The program also displayed a Windows message box with the following information:

- Title: `ReverseLogic-Lab`
- Message: `PE structure analysis lab`
- Button: OK
- Icon: Information

The message box was created through the `MessageBoxA` Windows API function.

## Ghidra Analysis

### calculate_value Function

The original C function is:

```c
int calculate_value(int number)
{
    return number * 2;
}
```

Ghidra displayed the following important assembly instructions:

```asm
MOV dword ptr [RBP + number], ECX
MOV EAX, dword ptr [RBP + number]
ADD EAX, EAX
RET
```

According to the Windows x64 calling convention, the first integer argument is passed through the `ECX` register.

The instruction:

```asm
ADD EAX, EAX
```

adds the value in `EAX` to itself. This produces the same result as multiplying the value by two.

The integer return value is passed back to the caller through the `EAX` register.

### main Function

The `main` function performs the following operations:

1. Reads the value of `initialized_global`.
2. Passes the value to `calculate_value`.
3. Stores the returned result in `uninitialized_global`.
4. Prints the message and calculated value using `printf`.
5. Calls `MessageBoxA`.
6. Returns `0`.

The relevant assembly flow includes:

```asm
MOV EAX, dword ptr [initialized_global]
MOV ECX, EAX
CALL calculate_value
```

The value of `initialized_global` is first loaded into `EAX`.

It is then moved into `ECX` because `ECX` is used for the first integer argument in the Windows x64 calling convention.

After the function call, the calculated result is returned through `EAX`.

Ghidra displayed `__mingw_printf` instead of the original `printf` function because the program was compiled with the MinGW runtime.

### MessageBoxA Call

The program calls:

```c
MessageBoxA(
    NULL,
    program_message,
    "ReverseLogic-Lab",
    MB_OK | MB_ICONINFORMATION
);
```

`MessageBoxA` is a Windows API function provided by `USER32.dll`.

The final flag value was displayed by Ghidra as:

```text
0x40
```

`MB_ICONINFORMATION` has the value `0x40`.

`MB_OK` has the value `0x0`, so combining the flags produces:

```text
0x0 | 0x40 = 0x40
```

The `A` suffix in `MessageBoxA` indicates that the function uses the ANSI character version of the Windows API.

The Unicode equivalent is `MessageBoxW`.

## Entry Point and CRT Startup

The executable does not start directly from the user-defined `main` function.

Ghidra identified `mainCRTStartup` as part of the executable startup process.

The observed execution flow was:

```text
Windows Loader
-> PE Entry Point
-> mainCRTStartup
-> __tmainCRTStartup
-> main
-> exit
```

### mainCRTStartup

The decompiled function contained the following logic:

```c
int mainCRTStartup(void)
{
    int result;

    __mingw_app_type = 0;
    result = __tmainCRTStartup();

    return result;
}
```

The assignment:

```c
__mingw_app_type = 0;
```

indicates that the executable is configured as a console application.

`mainCRTStartup` then transfers control to `__tmainCRTStartup`.

### __tmainCRTStartup

`__tmainCRTStartup` prepares the C runtime environment before the user-defined `main` function is called.

The function performs several initialization operations, including:

- Runtime startup synchronization
- Standard input and output configuration
- Runtime relocation handling
- Floating-point environment initialization
- Command-line argument preparation
- Environment variable preparation
- Global initializer execution
- Thread-local storage initialization
- Exception handler configuration

The call to the user-defined function was visible in the decompiler output:

```c
iVar4 = main();
```

After `main` returns, its result is passed to:

```c
exit(iVar4);
```

This confirms that the PE entry point and the user-defined `main` function are not the same location.

The runtime startup code executes before the application code.

## Compiler-Generated Runtime Code

The executable contains several functions that were not written directly in the source code.

Examples include:

- `mainCRTStartup`
- `__tmainCRTStartup`
- `__main`
- `__mingw_printf`
- `_pei386_runtime_relocator`
- `__dyn_tls_init`

These functions were added by the MinGW toolchain and C runtime.

The presence of these functions demonstrates that a compiled executable contains more than only the instructions written by the programmer.

## Decompiler Limitations

Ghidra displayed the following warning:

```text
WARNING: Unknown calling convention
```

The decompiler also produced an incorrect temporary parameter representation for the `calculate_value` call.

The assembly listing showed that `initialized_global` was loaded and passed through `ECX`, while the decompiler displayed an unidentified stack variable.

This demonstrates that decompiler output is an interpretation and may not always reproduce the original source code accurately.

Assembly instructions should be checked when the decompiler output appears incorrect or unclear.

## Key Findings

- The program was compiled as a 64-bit Windows PE executable.
- The executable uses the Windows Console subsystem.
- The PE entry point does not directly execute the user-defined `main` function.
- MinGW runtime code executes before `main`.
- The first integer argument is passed through `ECX`.
- Integer return values are passed through `EAX`.
- Multiplication by two was implemented using `ADD EAX, EAX`.
- `MessageBoxA` is imported from `USER32.dll`.
- `__mingw_printf` is the MinGW runtime implementation used for the original `printf` call.
- Compiler-generated runtime functions are included in the executable.
- Ghidra decompiler output should be verified against the assembly listing.

## Screenshots

- `screenshots/01-die-file-overview.png`
- `screenshots/02-runtime-output.png`
- `screenshots/03-ghidra-main-function.png`
- `screenshots/04-ghidra-entry-point.png`

## Conclusion

This lab demonstrated how a simple C program is transformed into a Windows Portable Executable file.

Runtime testing confirmed the expected calculation result and Windows API behavior.

Ghidra analysis showed how function parameters and return values are handled by the Windows x64 calling convention. It also revealed that the executable begins with MinGW runtime initialization code instead of directly executing the user-defined `main` function.

The analysis also demonstrated that decompiler output may contain incorrect assumptions and should be validated using the assembly listing.