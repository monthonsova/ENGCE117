#include <stdio.h>

int main() {
    int repeatTotal;
    scanf("%d", &repeatTotal);

    for (int index = 1; index <= repeatTotal; index++) {
        printf("[%d] Hello world\n", index);
    }

    return 0;
}
