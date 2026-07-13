#include <stdio.h>
#include <windows.h>

int initialized_global = 42;
int uninitialized_global;

const char program_message[] = "PE structure analysis lab";

int calculate_value(int number)
{
    return number * 2;
}

int main(void)
{
    uninitialized_global = calculate_value(initialized_global);

    printf(
        "%s\nCalculated value: %d\n",
        program_message,
        uninitialized_global
    );

    MessageBoxA(
        NULL,
        program_message,
        "ReverseLogic-Lab",
        MB_OK | MB_ICONINFORMATION
    );

    return 0;
}