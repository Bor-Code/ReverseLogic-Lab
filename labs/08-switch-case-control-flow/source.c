#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int option;

    if (argc != 2)
    {
        printf("Usage: switch_case.exe <option>\n");
        printf("Options:\n");
        printf("1 = scan\n");
        printf("2 = analyze\n");
        printf("3 = report\n");
        return 1;
    }

    option = atoi(argv[1]);

    switch (option)
    {
        case 1:
            printf("Selected action: scan\n");
            printf("Status: scanning target\n");
            break;

        case 2:
            printf("Selected action: analyze\n");
            printf("Status: analyzing data\n");
            break;

        case 3:
            printf("Selected action: report\n");
            printf("Status: generating report\n");
            break;

        default:
            printf("Invalid option\n");
            break;
    }

    return 0;
}