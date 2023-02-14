#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encode(char message[], char code_char[]) {
    char alphabet[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int code[strlen(code_char)];

    for (int i = 0; i < strlen(code_char); i++) {
        for (int j = 0; j < 26; j++) {
            if (alphabet[j] == code_char[i] && code_char[i] != ' ' && code_char[i] != ',' && code_char[i] != '.') code[i] = j+1;
        }
    }

    // for (int i = 0; i < strlen(code_char); i++) printf("%d ", code[i]); printf("\n");

    for (int i = 0, k = 0; i < strlen(message); i++) {
        for (int j = 0; j < 26; j++) {
            if (alphabet[j] == message[i]) {
                if (k >= strlen(code_char)) k = 0;
                if (1 <= code[k] && code[k] <= 26) {
                    // printf("%c = ", message[i]);
                    message[i] = alphabet[j+code[k]];
                    // printf("%c\n", message[i]);  
                    k++;
                } else {
                    k++;
                    if (1 <= code[k] && code[k] <= 26) {
                        // printf("%c = ", message[i]);
                        message[i] = alphabet[j+code[k]];
                        // printf("%c\n", message[i]);  
                        k++;
                    } else {
                        k++;
                        if (1 <= code[k] && code[k] <= 26) {
                            // printf("%c = ", message[i]);
                            message[i] = alphabet[j+code[k]];
                            // printf("%c\n", message[i]);  
                            k++;
                        }
                    }
                }
                break;
            }
        }
    }

    printf("Encoded with repeating shifts ");
    for (int i = 0; i < strlen(code_char); i++) {
        if (1 <= code[i] && code[i] <= 26) printf("%d ", code[i]);
    }
    printf(": %s\n", message);
}

void decode(char message[], char code_char[]) {
    char alphabet[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int code[strlen(code_char)];

    for (int i = 0; i < strlen(code_char); i++) {
        for (int j = 0; j < 26; j++) {
            if (alphabet[j] == code_char[i] && code_char[i] != ' ' && code_char[i] != ',' && code_char[i] != '.') code[i] = j+1;
        }
    }

    // for (int i = 0; i < strlen(code_char); i++) printf("%d ", code[i]); printf("\n");

    for (int i = 0, k = 0; i < strlen(message); i++) {
        for (int j = 26; j < 52; j++) {
            if (alphabet[j] == message[i]) {
                if (k >= strlen(code_char)) k = 0;
                if (1 <= code[k] && code[k] <= 26) {
                    // printf("%c = ", message[i]);
                    message[i] = alphabet[j-code[k]];
                    // printf("%c\n", message[i]);  
                    k++;
                } else {
                    k++;
                    if (1 <= code[k] && code[k] <= 26) {
                        // printf("%c = ", message[i]);
                        message[i] = alphabet[j-code[k]];
                        // printf("%c\n", message[i]);  
                        k++;
                    } else {
                        k++;
                        if (1 <= code[k] && code[k] <= 26) {
                            // printf("%c = ", message[i]);
                            message[i] = alphabet[j-code[k]];
                            // printf("%c\n", message[i]);  
                            k++;
                        }
                    }
                }
                break;
            }
        }
    }

    printf("Encoded with repeating shifts ");
    for (int i = 0; i < strlen(code_char); i++) {
        if (1 <= code[i] && code[i] <= 26) printf("%d ", code[i]);
    }
    printf(": %s\n", message);
}

int main() {
    char ar[1000];
    char code[1000];
    char option_char;
    printf("Enter the message\n");
    scanf("%[^\n]", &ar);
    
    int option = -1;
    printf("Encode or decode? 0 or 1 and the code word/sentence\n");

    scanf("%d %[^\n]", &option, &code);

    switch (option) {
        case 0:
            encode(ar, code);
            option = -1;
            break;
        case 1:
            decode(ar, code);
            option = -1;
            break;
    }
}