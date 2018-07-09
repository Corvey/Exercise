#include <cstdio>
#include <string.h>
const int N = 1e3+10, INF = 0x3f3f3f3f;
int g[N][N], D[N];
int prim(int n)
{
    int MIN, t, ans = 0;
    bool vis[N] = {0};
    memcpy(D, g[0], sizeof(D));
    vis[0] = true;
    for(int i=1; i<n; ++i)
    {
        MIN = INF;
        for(int j=1; j<n; ++j)
            if(!vis[j] && D[j] < MIN)
                MIN = D[j], t = j;
        vis[t] = true;
        ans += MIN;
        for(int j=1; j<n; ++j)
            if(!vis[j] && g[t][j] < D[j])
                D[j] = g[t][j];
    }
    return ans;
}
int main(void)
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            scanf("%d", g[i]+j);
    printf("%d\n", prim(n));
}
