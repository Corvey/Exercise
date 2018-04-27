#include <cstdio>
#include <string.h>
#include <algorithm>
#define MIN(a, b) (a < b ? a : b)
using namespace std;
const int N = 2e4+50, M = 2e5+100;
int u[M], v[M], Next[M], first[N], dad[N], low[N], dfn[N], counter;
int gb[M], ngb;
bool vis[N], gd[N];
void AddEdge(int from, int to, int t)
{
    u[t] = from, v[t] = to;
    Next[t] = first[from];
    first[from] = t;
}
bool cmp(const int a, const int b){
    return u[a] == u[b] ? v[a] < v[b] : u[a] < u[b];
}
void DFS(int from)
{
    int to, children = 0;
    low[from] = dfn[from] = ++counter;
    vis[from] = true;
    for(int x=first[from]; ~x; x=Next[x])
    {
        to = v[x];
        if(!vis[to])
        {
            ++children;
            dad[to] = from;
            DFS(to);
            low[from] = MIN(low[from], low[to]);
            if(!~dad[from] && children > 1)
                gd[from] = true;
            if(~dad[from] && low[to] >= dfn[from])
                gd[from] = true;
            if(low[to] > dfn[from])
                gb[ngb++] = x;
        }
        else if(to != dad[from])
            low[from] = MIN(low[from], dfn[to]);
    }
}
int main(void)
{
    int n, m, from, to, temp, t;
    bool tag;
    while(~scanf("%d %d", &n, &m))
    {
        memset(first, -1, sizeof(first));
        for(int i=0, t=0; i<m; ++i)
        {
            scanf("%d %d", &from, &to);
            AddEdge(from, to, t++);
            AddEdge(to, from, t++);
        }
        counter = ngb = 0;
        memset(dad, -1, sizeof(dad));
        memset(vis, 0, sizeof(vis));
        memset(gd, 0, sizeof(gd));
        memset(gb, 0, sizeof(gb));
        DFS(1);
        tag = true;
        for(int i=1; i<=n; ++i)
        {
            if(gd[i])
            {
                printf("%d ", i);
                tag = false;
            }
        }
        if(tag)
            printf("Null");
        printf("\n");
        for(int i=0; i<ngb; ++i)
        {
            t = gb[i];
            if(u[t] > v[t])
                temp = u[t], u[t] = v[t], v[t] = temp;
        }
        sort(gb, gb+ngb, cmp);
        for(int i=0; i<ngb; ++i)
        {
            t = gb[i];
            printf("%d %d\n", u[t], v[t]);
        }
    }
}
