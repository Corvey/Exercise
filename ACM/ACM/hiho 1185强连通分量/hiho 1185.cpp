#include <cstdio>
#include <string.h>
#define small(a, b) (a < b ? a : b)
#define big(a, b) (a > b ? a : b)
#define mset(a, b) memset(a, b, sizeof(a))
const int N = 2e4+50, M = 2e5+50, INF = 0x3f3f3f3f;
int ou[M], ov[M], ow[N], oNext[M], ofirst[N];   //旧图
int nu[M], nv[M], nw[N], nNext[M], nfirst[N], in[N];   //新图
int scc[N], noscc, MAX;
int low[N], dfn[N], counter;    //tarjan
int heap[N], noh;   //栈
bool vis[N], inheap[N];
void tarjan(int from)
{
    int to;
    heap[++noh] = from;
    inheap[from] = vis[from] = true;
    dfn[from] = low[from] = ++counter;
    for(int x=ofirst[from]; ~x; x=oNext[x])
    {
        to = ov[x];
        if(!vis[to])
        {
            tarjan(to);
            low[from] = small(low[from], low[to]);
        }
        else if(inheap[to])
            low[from] = small(low[from], dfn[to]);
    }
    if(low[from] == dfn[from])
    {
        nw[noscc] = 0;
        //printf("强连通分量：");
        for(; heap[noh] != from; --noh)
        {
            //printf("%d ", heap[noh]);
            nw[noscc] += ow[heap[noh]];
            scc[heap[noh]] = noscc;
            inheap[heap[noh]] = false;
        }
        //printf("%d\n", heap[noh]);
        nw[noscc] += ow[from];
        scc[heap[noh--]] = noscc++;
        inheap[from] = false;
    }
}
void DFS(int from, int sum)
{
    if(sum > MAX)
        MAX = sum;
    for(int x=nfirst[from]; ~x; x=nNext[x])
        DFS(nv[x], sum + nw[nv[x]]);
}
bool judge(int from, int to)
{
    if(from == to)
        return false;
    for(int x=nfirst[from]; ~x; x=nNext[x])
        if(nv[x] == to)
            return false;
    return true;
}
int main(void)
{
    int n, m;
    while(~scanf("%d %d", &n, &m))
    {
        for(int i=1; i<=n; ++i)
            scanf("%d", ow+i);
        mset(ofirst, -1);
        for(int i=0, t=0; i<m; ++i)
        {
            scanf("%d %d", ou+t, ov+t);
            oNext[t] = ofirst[ou[t]];
            ofirst[ou[t]] = t++;
        }
        noscc = counter = 0;
        noh = -1;
        mset(vis, 0);
        mset(inheap, 0);
        mset(scc, -1);
        tarjan(1);
        mset(nfirst, -1);
        mset(in, 0);
        for(int i=1, t=0; i<=n; ++i)
        {
            if(!~scc[i])
                continue;
            for(int x=ofirst[i]; ~x; x=oNext[x])
            {
                nu[t] = scc[i];
                nv[t] = scc[ov[x]];
                if(!judge(nu[t], nv[t]))
                    continue;
                ++in[nv[t]];
                nNext[t] = nfirst[nu[t]];
                nfirst[nu[t]] = t++;
            }
        }
        MAX = nw[scc[1]];
        DFS(scc[1], MAX);
        printf("%d\n", MAX);
    }
    return 0;
}
