// Made by mnjx

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void encode(char message[]) {
    char origin[strlen(message)];
    for (int i = 0; i < strlen(message); i++) {
        origin[i] = message[i];
    }
    char alphabet[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int shifts[strlen(message)];
    for (int i = 0; i < strlen(message); i++) {
        shifts[i] = 0;
    }
    int k;

    for (int i = 0; i < strlen(message); i++) {
        for (int j = 0; j < 26; j++) {
            if (alphabet[j] == message[i]) {
                k = rand() % 27 + 1;
                shifts[i] = k;
                message[i] = alphabet[j+k];                
                break;
            }
        }
    }
    printf("Encoded: %s\n", message);
    // for (int i = 0; i < strlen(message); i++) {
    //     printf("%d %c; ", shifts[i], origin[i]);
    // }
    // printf("\n");
}

// void decode(char message[]); (uplne to nejde...)

int main() {
    srand(time(NULL));
    
    char ar[1000];

    printf("Enter the message\n");
    scanf("%[^\n]", &ar);
    
    encode(ar);
}
