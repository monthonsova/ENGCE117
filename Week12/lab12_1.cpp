#include <stdio.h>

int *Dijkstra(int *L, int n);

int main() {
	int n = 5, i = 0, j = 0, *d, *g;
	g = new int[n * n];
	for(i = 0; i < n; i++) 
		for(j = 0; j < n; j++)
			g[i * n + j] = -1;

	g[0 * n + 1] = 100;	g[0 * n + 2] = 80;
	g[0 * n + 3] = 30;	g[0 * n + 4] = 10;
	g[1 * n + 2] = 20;	g[3 * n + 1] = 20;
	g[3 * n + 2] = 20;	g[4 * n + 3] = 10;

	d = Dijkstra(g, n);
	for(i = 0; i < n - 1; i++)
		printf("%d ", d[i]);
	return 0;
}

int *Dijkstra(int *L, int n) {
    int *dist = new int[n - 1];
    int *visited = new int[n];
    
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    
    for (int i = 1; i < n; i++) {
        if (L[i] != -1) {
            dist[i - 1] = L[i];
        } else {
            dist[i - 1] = 999999;
        }
    }
    
    visited[0] = 1;
    
    for (int count = 0; count < n - 1; count++) {
        int min_dist = 999999;
        int u = -1;
        
        for (int i = 1; i < n; i++) {
            if (!visited[i] && dist[i - 1] < min_dist) {
                min_dist = dist[i - 1];
                u = i;
            }
        }
        
        if (u == -1) break;
        
        visited[u] = 1;
        
        for (int v = 1; v < n; v++) {
            if (!visited[v] && L[u * n + v] != -1) {
                if (dist[u - 1] + L[u * n + v] < dist[v - 1]) {
                    dist[v - 1] = dist[u - 1] + L[u * n + v];
                }
            }
        }
    }
    
    return dist;
}