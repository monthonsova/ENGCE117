#include <stdio.h>
#include <stdlib.h>

int *GetSet(int *sizePtr) {
    int total;
    scanf("%d", &total);

    int *bucket = malloc(total * sizeof(int));
    for (int i = 0; i < total; i++) {
        scanf("%d", &bucket[i]);
    }

    *sizePtr = total;
    return bucket;
}

int main() {
    int *data, num;
    data = GetSet(&num);
    return 0;
}
