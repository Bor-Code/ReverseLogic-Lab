#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: command_password.exe <password>\n");
        return 1;
    }

    if (strcmp(argv[1], "bora123") == 0)
    {
        printf("Access granted\n");
    }
    else
    {
        printf("Access denied\n");
    }

    return 0;
}