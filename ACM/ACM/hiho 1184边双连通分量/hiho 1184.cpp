#include <cstdio>
#include <string.h>
#include <algorithm>
#define small(a, b) (a < b ? a : b)
using namespace std;
const int N = 2e4+50, M = 2e5+100;
int u[M], v[M], Next[M], first[N], dad[N], low[N], dfn[N], counter, ans[N], MIN, ngb;
struct node
{
    int heap[N];
    int top;
}zhan;
bool vis[N];
void AddEdge(int from, int to, int t)
{
    u[t] = from, v[t] = to;
    Next[t] = first[from];
    first[from] = t;
}
void DFS(int from)
{
    int to;
    low[from] = dfn[from] = ++counter;
    vis[from] = true;
    zhan.heap[++zhan.top] = from;
    for(int x=first[from]; ~x; x=Next[x])
    {
        to = v[x];
        if(!vis[to])
        {
            dad[to] = from;
            DFS(to);
            low[from] = small(low[from], low[to]);
            if(low[to] > dfn[from])
                ++ngb;
        }
        else if(to != dad[from])
            low[from] = small(low[from], dfn[to]);
    }
    if(low[from] == dfn[from])
    {
        MIN = from;
        for(int i=zhan.top; zhan.heap[i] != from; --i)
            MIN = small(MIN, zhan.heap[i]);
        while(zhan.heap[zhan.top] != from)
            ans[zhan.heap[zhan.top--]] = MIN;
        ans[from] = MIN;
        --zhan.top;
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
        ngb = counter = 0;
        memset(vis, 0, sizeof(vis));
        memset(dad, 0, sizeof(dad));
        zhan.top = -1;
        DFS(1);
        printf("%d\n%d", ngb+1, ans[1]);
        for(int i=2; i<=n; ++i)
            printf(" %d", ans[i]);
        printf("\n");
    }
}
