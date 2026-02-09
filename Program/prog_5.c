#include <stdio.h>
#define SIZE 10

int g[SIZE][SIZE];
int v[SIZE];
int n;

void bfs(int s) {
    int q[SIZE];
    int f = 0, r = 0;
    int i, c;
    
    for (i = 0; i < n; i++)
        v[i] = 0;
    
    q[r++] = s;
    v[s] = 1;
    
    printf("BFS: ");
    while (f < r) {
        c = q[f++];
        printf("%d ", c);
        
        for (i = 0; i < n; i++) {
            if (g[c][i] == 1 && v[i] == 0) {
                q[r++] = i;
                v[i] = 1;
            }
        }
    }
    printf("\n");
}

void dfs(int x) {
    int i;
    printf("%d ", x);
    v[x] = 1;
    
    for (i = 0; i < n; i++) {
        if (g[x][i] == 1 && v[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int e, u, w, s, i, j;
    
    printf("Enter no. of vertices: ");
    scanf("%d", &n);
    
    printf("Enter no. ofedges: ");
    scanf("%d", &e);
    
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            g[i][j] = 0;
    
    printf("Enter edges (u w):\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d", &u, &w);
        g[u][w] = 1;
        g[w][u] = 1;
    }
    
    printf("Enter starting vertex: ");
    scanf("%d", &s);
    
    bfs(s);
    
    for (i = 0; i < n; i++)
        v[i] = 0;
    
    printf("DFS: ");
    dfs(s);
    printf("\n");
    
    return 0;
}