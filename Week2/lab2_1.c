#include <stdio.h>
#include <string.h>

void reverse(char str1[], char str2[]);

int main() {
    char text[50] = "I Love You";
    char out[50];

    reverse(text, out);
    printf("%s\n", out);

    return 0;
}

void reverse(char str1[], char str2[]) {
    int left = 0;
    int right = strlen(str1) - 1;
    int idx = 0;

    while (right >= left) {
        str2[idx++] = str1[right--];
    }
    str2[idx] = '\0';
}
