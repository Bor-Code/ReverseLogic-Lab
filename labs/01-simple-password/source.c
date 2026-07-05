#include <stdio.h>
#include <string.h>

int main() {
    char input[32];

    printf("Enter password: ");
    scanf("%31s", input);

    if (strcmp(input, "bora123") == 0) {
        printf("Access granted\n");
    } else {
        printf("Access denied\n");
    }

    return 0;
}
