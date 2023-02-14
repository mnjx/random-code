#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encode(char message[], int shift) {
    char alphabet[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    for (int i = 0; i < strlen(message); i++) {
        for (int j = 0; j < 26; j++) {
            if (alphabet[j] == message[i]) {
                message[i] = alphabet[j+shift];
                break;
            }
        }
    }
}

void decode(char message[], int shift) {
    char alphabet[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    for (int i = 0; i < strlen(message); i++) {
        for (int j = 26; j < 52; j++) {
            if (alphabet[j] == message[i]) {
                message[i] = alphabet[j-shift];
                break;
            }
        }
    }
}

int main() {
    char ar[1000];
    scanf("%[^\n]", &ar);
    encode(ar, 25);
    printf("Encoded: %s\n", ar);

    decode(ar, 25);
    printf("\nDecoded: %s\n", ar);
}