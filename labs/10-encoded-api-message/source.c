#include <stdio.h>
#include <windows.h>

void decode_message(char output[])
{
    unsigned char encoded_message[] = {
        0x14, 0x3b, 0x34, 0x39, 0x2c, 0x26,
        0x3c, 0x26, 0x75, 0x1a, 0x1e
    };

    unsigned char key = 0x55;
    int i;

    for (i = 0; i < 11; i++)
    {
        output[i] = encoded_message[i] ^ key;
    }

    output[11] = '\0';
}

int main()
{
    char decoded_message[12];

    decode_message(decoded_message);

    printf("Encoded API Message Lab\n");
    printf("Decoded message: %s\n", decoded_message);

    MessageBoxA(NULL, decoded_message, "ReverseLogic-Lab", MB_OK);

    return 0;
}