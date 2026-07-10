#include <stdio.h>
#include <string.h>

int is_valid_key(char key[])
{
    if (strlen(key) != 11)
    {
        return 0;
    }

    if (strncmp(key, "BOR", 3) != 0)
    {
        return 0;
    }

    if (key[3] != '-')
    {
        return 0;
    }

    if (key[4] != '2' || key[5] != '0' || key[6] != '2' || key[7] != '6')
    {
        return 0;
    }

    if (key[8] != '-')
    {
        return 0;
    }

    if (key[9] != 'O' || key[10] != 'K')
    {
        return 0;
    }

    return 1;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: license_key.exe <key>\n");
        return 1;
    }

    if (is_valid_key(argv[1]))
    {
        printf("License valid\n");
    }
    else
    {
        printf("License invalid\n");
    }

    return 0;
}