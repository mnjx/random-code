#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encode(char message[]) {
    char alphabet[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    for (int k = 1; k < 26; k++) {
        for (int i = 0; i < strlen(message); i++) {
            for (int j = 0; j < 26; j++) {
                if (alphabet[j] == message[i]) {
                    message[i] = alphabet[j+k];
                    break;
                }
            }
        }
        printf("\nEncoded with shift %d: %s\n", k, message);
    }
}

void decode(char message[]) {
    char alphabet[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    for (int k = 1; k < 26; k++) {
        for (int i = 0; i < strlen(message); i++) {
            for (int j = 26; j < 52; j++) {
                if (alphabet[j] == message[i]) {
                    message[i] = alphabet[j-k];
                    break;
                }
            }
        }
        printf("\nDecoded with shift %d: %s\n", k, message);
    }
}

int main() {
    char ar[1000];
    printf("Enter the message\n");
    scanf("%[^\n]", &ar);
    
    int option = -1;
    printf("Encode or decode? 0 or 1\n");
    scanf("%d", &option);

    while (option == 0 || option == 1) {
        switch (option) {
            case 0:
                encode(ar);
                option = -1;
                break;
            case 1:
                decode(ar);
                option = -1;
                break;
            default:
                printf("Please enter a valid number.\n");
        }
    }
}