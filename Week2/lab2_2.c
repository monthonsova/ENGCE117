#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverse(char str1[]);

int main() {
    char text[50] = "I Love You";
    char *out;

    out = reverse(text);
    printf("%s\n", out);

    free(out);
    return 0;
}

char* reverse(char str1[]) {
    int n = strlen(str1);
    char *flipped = malloc(n + 1);

    int p = 0;
    for (int i = n - 1; i >= 0; i--) {
        flipped[p++] = str1[i];
    }
    flipped[p] = '\0';

    return flipped;
}
