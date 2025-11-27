#include <stdio.h>
#include <stdlib.h>

int *GetMatrix(int *rPtr, int *cPtr) {
    int r, c;
    scanf("%d %d", &r, &c);

    int total = r * c;
    int *box = malloc(total * sizeof(int));

    for (int i = 0; i < total; i++) {
        scanf("%d", &box[i]);
    }

    *rPtr = r;
    *cPtr = c;

    return box;
}

int main() {
    int *data, m, n;
    data = GetMatrix(&m, &n);
    return 0;
}
