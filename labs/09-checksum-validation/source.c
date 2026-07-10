#include <stdio.h>
#include <string.h>

int calculate_checksum(char input[])
{
    int sum = 0;
    int i;

    for (i = 0; input[i] != '\0'; i++)
    {
        sum += input[i];
    }

    return sum;
}

int main(int argc, char *argv[])
{
    int checksum;

    if (argc != 2)
    {
        printf("Usage: checksum_check.exe <input>\n");
        return 1;
    }

    checksum = calculate_checksum(argv[1]);

    if (checksum == 329 && strlen(argv[1]) == 3)
    {
        printf("Access granted\n");
    }
    else
    {
        printf("Access denied\n");
    }

    return 0;
}