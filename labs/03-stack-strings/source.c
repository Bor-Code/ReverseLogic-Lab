#include <stdio.h>
#include <string.h>

void build_password(char output[])
{
    output[0] = 'b';
    output[1] = 'o';
    output[2] = 'r';
    output[3] = 'a';
    output[4] = '1';
    output[5] = '2';
    output[6] = '3';
    output[7] = '\0';
}

int main()
{
    char input[32];
    char password[8];

    build_password(password);

    printf("Enter Password: ");
    scanf("%31s", input);

    if (strcmp(input, password) == 0)
    {
        printf("Access granted\n");
    }
    else
    {
        printf("Access denied\n");
    }

    return 0;
}