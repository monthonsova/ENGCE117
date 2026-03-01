#include <stdio.h>

int *KnapsackDP(int *w, int *v, int n, int wx);

int main() {
    int n = 5 , wx = 11 ;
    int w[ 5 ] = { 1, 2, 5, 6, 7 } ;
    int v[ 5 ] = { 1, 6, 18, 22, 28 } ;
    int *x ;
    x = KnapsackDP( w, v, n, wx ) ;
    for( int i = 0 ; i < n ; i++ ) printf( "%d ", x[ i ] ) ;
    return 0 ;
}

int *KnapsackDP(int *w, int *v, int n, int wx) {
    int **K = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
        K[i] = new int[wx + 1];
    }
    
    for (int i = 0; i <= n; i++) {
        for (int wt = 0; wt <= wx; wt++) {
            if (i == 0 || wt == 0) {
                K[i][wt] = 0; 
            } else if (w[i - 1] <= wt) {
                int val1 = v[i - 1] + K[i - 1][wt - w[i - 1]];
                int val2 = K[i - 1][wt];
                K[i][wt] = (val1 > val2) ? val1 : val2;
            } else {
                K[i][wt] = K[i - 1][wt];
            }
        }
    }
    
    int *x = new int[n];
    for (int i = 0; i < n; i++) {
        x[i] = 0;
    }
    
    int res = K[n][wx];
    int wt = wx;
    
    for (int i = n; i > 0 && res > 0; i--) {
        if (res != K[i - 1][wt]) {
            x[i - 1] = 1;
            res -= v[i - 1];
            wt -= w[i - 1];
        }
    }
    
    return x;
}