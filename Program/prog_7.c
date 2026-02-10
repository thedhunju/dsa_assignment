#include <stdio.h>
#define N 6
#define INF 9999

int getMin(int d[], int v[], int s) {
  int m = INF, idx = -1;
  int i;
  for (i = 0; i < s; i++) {
    if (v[i] == 0 && d[i] < m) {
      m = d[i];
      idx = i;
    }
  }
  return idx;
}

void path(int p[], int j) {
  if (p[j] == -1) {
    printf("%d ", j);
    return;
  }
  path(p, p[j]);
  printf("%d ", j);
}

void solve(int g[N][N], int src) {
  int d[N], v[N], p[N];
  int i, c, u, w;
  
  for (i = 0; i < N; i++) {
    d[i] = INF;
    v[i] = 0;
    p[i] = -1;
  }
  
  d[src] = 0;
  
  for (c = 0; c < N - 1; c++) {
    u = getMin(d, v, N);
    v[u] = 1;
    
    for (w = 0; w < N; w++) {
      if (v[w] == 0 && g[u][w] && d[u] + g[u][w] < d[w]) {
        p[w] = u;
        d[w] = d[u] + g[u][w];
      }
    }
  }
  
  printf("Vertex\tDist\tPath\n");
  for (i = 0; i < N; i++) {
    printf("%d\t%d\t", i, d[i]);
    path(p, i);
    printf("\n");
  }
}

int main() {
  int g[N][N] = {
    {0, 4, 0, 0, 0, 0},
    {4, 0, 8, 0, 0, 0},
    {0, 8, 0, 7, 0, 4},
    {0, 0, 7, 0, 9, 14},
    {0, 0, 0, 9, 0, 10},
    {0, 0, 4, 14, 10, 0}
  };
  
  solve(g, 0);
  
  return 0;
}
