#include <stdio.h>
#include <stdlib.h>

int GetSet(int holder[]) {
    int amount;
    scanf("%d", &amount);

    int *slot = malloc(amount * sizeof(int));
    for (int i = 0; i < amount; i++) {
        scanf("%d", &slot[i]);
    }

    *((int **)holder) = slot;
    return amount;
}

int main() {
    int *data, num;
    num = GetSet(&data);
    return 0;
}
