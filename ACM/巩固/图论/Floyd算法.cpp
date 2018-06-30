#include <cstdio>
#include <string.h>
const int N = 1e2+10, INF = 0x3f3f3f3f;
int g[N][N];
int main(void)
{
    int n, m, u, v, w;
    scanf("%d %d", &n, &m);
    memset(g, INF, sizeof(g));
    while(m--)
    {
        scanf("%d %d %d", &u, &v, &w);
        --u, --v;
        if(w < g[u][v])
            g[u][v] = g[v][u] = w;
    }
    for(int k=0; k<n; ++k)
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                if(g[i][j] > g[i][k] + g[k][j])
                    g[i][j] = g[i][k] + g[k][j];
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
            printf("%d ", i == j ? 0 : g[i][j]);
        printf("\n");
    }
}
