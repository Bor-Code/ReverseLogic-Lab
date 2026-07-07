#include <stdio.h>
#include <string.h>

void decode_password(char output[]) {
    unsigned char encoded_password[] = {0x37, 0x3a, 0x27, 0x34, 0x64, 0x67, 0x66};
    unsigned char key = 0x55;
    int i;

    for (i = 0; i < 7; i++) {
        output[i] = encoded_password[i] ^ key;
    }

    output[7] = '\0';
}

int main() {
    char input[32];
    char decoded_password[8];

    decode_password(decoded_password);

    printf("Enter password: ");
    scanf("%31s", input);

    if (strcmp(input, decoded_password) == 0) {
        printf("Access granted\n");
    } else {
        printf("Access denied\n");
    }

    return 0;
}