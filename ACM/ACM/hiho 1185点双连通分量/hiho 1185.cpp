#include <cstdio>
#include <string.h>
#define small(a, b) (a < b ? a : b)
#define mset(a, b) memset(a, b, sizeof(a))
const int N = 2e4+50, M = 2e5+50;
int u[M], v[M], first[N], Next[M];
int low[N], dfn[N], counter;
int heap[M], top, nid, MIN, id[M];
void AddEdge(int from, int to, int t)
{
    u[t] = from, v[t] = to;
    Next[t] = first[from];
    first[from] = t;
}
void markedge(int stop)
{
    MIN = stop;
    for(int i=top; heap[i] != stop; --i)
        MIN = small(MIN, heap[i]);
    MIN = MIN / 2 + 1;
    for(int t = heap[top]; t != stop; t = heap[--top])
    {
        if(u[t] > v[t])
            id[t] = id[t-1] = MIN;
        else
            id[t] = id[t+1] = MIN;
    }
    if(u[stop] > v[stop])
        id[stop] = id[stop-1] = MIN;
    else
        id[stop] = id[stop+1] = MIN;
    --top;
    ++nid;
}
void tarjan(int from, int dad = -1)
{
    int children = 0, to;
    dfn[from] = low[from] = ++counter;
    for(int x=first[from]; ~x; x=Next[x])
    {
        to = v[x];
        if(!dfn[to])
        {
            ++children;
            heap[++top] = x;
            tarjan(to, from);
            low[from] = small(low[from], low[to]);
            if(low[to] >= dfn[from])
                markedge(x);
        }
        else if(to != dad && dfn[to] < dfn[from])
        {
            heap[++top] = x;
            low[from] = small(low[from], dfn[to]);
        }
    }
}
int main(void)
{
    int n, m, from, to, temp;
    while(~scanf("%d %d", &n, &m))
    {
        mset(first, -1);
        for(int i=0, t=0; i<m; ++i)
        {
            scanf("%d %d", &from, &to);
            if(from > to)
                t = temp, temp = to, to = temp;
            AddEdge(from, to, t++);
            AddEdge(to, from, t++);
        }
        mset(dfn, 0);
        mset(id, 0);
        nid = counter = 0;
        top = -1;
        tarjan(1);
        printf("%d\n", nid);
        for(int i=0; i<2*m; i+=2)
            printf("%d ", id[i]);
        printf("\n");
    }
    return 0;
}
