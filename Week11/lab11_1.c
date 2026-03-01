#include <stdio.h>

int BinSearch(int data[], int n, int find);

int main() {
    int data[6] = { 1, 2, 3, 4, 5, 7 };
    int n = 6;
    int find = 5;
    
    int pos = BinSearch(data, n, find);
    
    if (pos != -1) {
        printf("Found %d at %d\n", find, pos);
    } else {
        printf("Not found\n");
    }

    return 0;
}

int BinSearch(int data[], int n, int find) {
    int i = 0;
    int j = n - 1;
    int m;

    while (i <= j) {
        m = (i + j) / 2;
        if (data[m] == find) {
            return m;
        } else if (data[m] > find) {
            j = m - 1;
        } else {
            i = m + 1;
        }
    }
    return -1;
}