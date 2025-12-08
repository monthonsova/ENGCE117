#include <stdio.h>

void explode(char str1[], char splitter, char str2[][10], int *count);

int main() {
    char out[20][10];
    int num;

    explode("I/Love/You", '/', out, &num);

    for (int i = 0; i < num; i++) {
        printf("%s\n", out[i]);
    }

    return 0;
}

void explode(char str1[], char splitter, char str2[][10], int *count) {
    int piece = 0;
    int letter = 0;

    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] == splitter) {
            str2[piece][letter] = '\0';
            piece++;
            letter = 0;
        } else {
            str2[piece][letter++] = str1[i];
        }
    }

    str2[piece][letter] = '\0';
    *count = piece + 1;
}
