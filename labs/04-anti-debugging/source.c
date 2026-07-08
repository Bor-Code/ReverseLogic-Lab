#include <stdio.h>
#include <windows.h>

void wait_before_exit()
{
    printf("Press Enter to exit...");
    getchar();
}

int main()
{
    printf("Anti-Debugging Lab\n");

    if (IsDebuggerPresent())
    {
        printf("Debugger detected\n");
        printf("Access denied\n");
        wait_before_exit();
        return 1;
    }

    printf("No debugger detected\n");
    printf("Access granted\n");
    wait_before_exit();

    return 0;
}