#include <stdio.h>

int KnapsackBT(int *w, int *v, int n, int wx, int i, int *x);

int main() {
    int n = 5, wx = 11;
    
    int w[5] = { 1, 2, 5, 6, 7 };
    int v[5] = { 1, 6, 18, 22, 28 };
    
    int *x, vx;
    x = new int[n];
    
    vx = KnapsackBT(w, v, n, wx, 0, x);
    
    printf("Value = %d\n", vx);
    for(int i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }
    
    return 0;
}

int KnapsackBT(int *w, int *v, int n, int wx, int i, int *x) {
    if (i == n) {
        return 0;
    }

    int *x_exclude = new int[n];
    int *x_include = new int[n];

    for (int j = 0; j < n; j++) {
        x_exclude[j] = 0;
        x_include[j] = 0;
    }

    int val_exclude = KnapsackBT(w, v, n, wx, i + 1, x_exclude);

    int val_include = 0;
    if (wx >= w[i]) {
        val_include = v[i] + KnapsackBT(w, v, n, wx - w[i], i + 1, x_include);
    }

    int max_val = 0;

    if (val_include > val_exclude) {
        max_val = val_include;
        for (int j = i + 1; j < n; j++) {
            x[j] = x_include[j];
        }
        x[i] = 1;
    } else {
        max_val = val_exclude;
        for (int j = i + 1; j < n; j++) {
            x[j] = x_exclude[j];
        }
        x[i] = 0;
    }

    delete[] x_exclude;
    delete[] x_include;

    return max_val;
}