#include <cstdio>
#include <string.h>
const int N = 1e3+10, M = 2e4+20, INF = 0x3f3f3f3f;
int u[M], v[M], w[M], Next[M], first[N];
inline void bulid(int from, int to, int weight, int t)
{
    u[t] = from, v[t] = to, w[t] = weight;
    Next[t] = first[from];
    first[from] = t;
}
int Dijkstra(int from, int to, int n)
{
    int D[N], mt;
    bool vis[N] = {0};
    memset(D, INF, sizeof(D));
    for(int x=first[from]; ~x; x=Next[x])
        D[v[x]] = w[x];
    D[from] = 0;
    while(1)
    {
        mt = to;
        for(int i=0; i<n; ++i)
            if(!vis[i] && D[i] < D[mt])
                mt = i;
        if(mt == to)
            break;
        vis[mt] = true;
        for(int x=first[mt]; ~x; x=Next[x])
            if(!vis[v[x]] && D[mt] + w[x] < D[v[x]])
                D[v[x]] = D[mt] + w[x];
    }
    return D[to];
}
int main(void)
{
    int from, to, weight, n, m, s, t;
    scanf("%d %d %d %d", &n, &m, &s, &t);
    memset(first, -1, sizeof(first));
    for(int i=0; m--; )
    {
        scanf("%d %d %d", &from, &to, &weight);
        --from, --to;
        bulid(from, to, weight, i++);
        bulid(to, from, weight, i++);
    }
    printf("%d\n", Dijkstra(--s, --t, n));
    return 0;
}
