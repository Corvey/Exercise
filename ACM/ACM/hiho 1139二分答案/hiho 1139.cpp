#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
const int N = 1e4+50, M = 2e5+100;
int u[M], v[M], first[N], Next[M], n, m, k, boss;
struct node{
    int u, v, w;
}edge[100100];
bool cmp(const node a, const node b){
    return a.w < b.w;
}
void AddEdge(int from, int to, int t)
{
    u[t] = from, v[t] = to;
    Next[t] = first[from];
    first[from] = t;
}
bool judge(int x)
{
    memset(first, -1, sizeof(first));
    for(int i=0, t=0; i<m; ++i)
    {
        if(edge[i].w > x)
            break;
        AddEdge(edge[i].u, edge[i].v, t++);
        AddEdge(edge[i].v, edge[i].u, t++);
    }
    int Q[N], step[N] = {0}, f = 0, r = 0, t;
    bool vis[N] = {0};
    vis[1] = true;
    Q[0] = 1;
    do
    {
        t = Q[f];
        if(step[t] == k)
            return false;
        for(int i=first[t]; ~i; i=Next[i])
        {
            if(!vis[v[i]])
            {
                if(v[i] == boss && step[t] + 1 <= k)
                    return true;
                ++r;
                vis[v[i]] = true;
                Q[r] = v[i];
                step[v[i]] = step[t] + 1;
            }
        }
        ++f;

    } while (f <= r);
    return false;
}
int work(int l, int r)
{
    if(l+1 == r)
        return r;
    int mid = (l+r)/2;
    if(judge(mid))
        return work(l, mid);
    else
        return work(mid, r);
}
int main(void)
{
    int l, r;
    while(~scanf("%d %d %d %d", &n, &m, &k, &boss))
    {
        for(int i=0; i<m; ++i)
            scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
        sort(edge, edge+m, cmp);
        l = edge[0].w;
        r = edge[m-1].w;
        if(judge(l))
            printf("%d\n", l);
        else
            printf("%d\n", work(l, r));
    }
    return 0;
}
