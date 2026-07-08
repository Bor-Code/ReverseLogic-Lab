#include <stdio.h>
#include <windows.h>

int main()
{
    char computer_name[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD computer_name_size = sizeof(computer_name);

    char windows_directory[MAX_PATH];
    char system_directory[MAX_PATH];

    DWORD process_id;

    printf("Windows API Behavior Lab\n");

    if (GetComputerNameA(computer_name, &computer_name_size))
    {
        printf("Computer Name: %s\n", computer_name);
    }
    else
    {
        printf("Computer Name: unavailable\n");
    }

    if (GetWindowsDirectoryA(windows_directory, MAX_PATH) > 0)
    {
        printf("Windows Directory: %s\n", windows_directory);
    }
    else
    {
        printf("Windows Directory: unavailable\n");
    }

    if (GetSystemDirectoryA(system_directory, MAX_PATH) > 0)
    {
        printf("System Directory: %s\n", system_directory);
    }
    else
    {
        printf("System Directory: unavailable\n");
    }

    process_id = GetCurrentProcessId();
    printf("Current Process ID: %lu\n", process_id);

    printf("Press Enter to exit...");
    getchar();

    return 0;
}