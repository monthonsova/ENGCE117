#include <stdio.h>
#include <stdlib.h>

void GetSet(int receiver[], int *countPtr) {
    int totalItems;
    scanf("%d", &totalItems);

    int *tempBox = malloc(totalItems * sizeof(int));
    for (int slot = 0; slot < totalItems; slot++) {
        scanf("%d", &tempBox[slot]);
    }

    *(int **)receiver = tempBox;
    *countPtr = totalItems;
}

int main() {
    int *data, num;
    GetSet((int *)&data, &num);
    return 0;
}
