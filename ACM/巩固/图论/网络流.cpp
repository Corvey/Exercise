#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
const int N = 510, M = 2e4+10, INF = 0x3f3f3f3f;
inline int small(int a, int b){
    return a < b ? a : b;
}
struct graph
{
    int u[M], v[M], c[M], first[N], Next[M], num;
    void init(void)
    {
        memset(first, -1, sizeof(first));
        num = 0;
    }
    void AddEdge(int from, int to, int val)
    {
        u[num] = from, v[num] = to;
        c[num] = val;
        Next[num] = first[from];
        first[from] = num++;
    }
}fg, bg;
int flow[N], src[N];
queue<int> q;
void InitMark(void)
{
    memset(flow, 0, sizeof(flow));
    memset(src, 0, sizeof(src));
    flow[1] = INF;
    src[1] = -1;
    while(!q.empty())
        q.pop();
    q.push(1);
}
int FordFulkerson(int n)
{
    int use[M] = {0}, from, to, temp, path[N][N];
    InitMark();
    while(!q.empty())
    {
        from = q.front();
        q.pop();
        //前向边
        for(int x=fg.first[from]; ~x; x=fg.Next[x])
        {
            to = fg.v[x];
            if(!src[to])
            {
                temp = fg.c[x] - use[x];
                if(temp > 0)
                {
                    flow[to] = small(flow[from], temp);
                    src[to] = from;
                    path[from][to] = x;
                    q.push(to);
                }
            }
        }
        //后向边
        for(int x=bg.first[from]; ~x; x=bg.Next[x])
        {
            to = bg.v[x];
            if(!src[to] && use[x] > 0)
            {
                flow[to] = small(flow[from], use[x]);
                src[to] = 0 - from;
                path[from][to] = x;
                q.push(to);
            }
        }
        if(src[n]) //汇点被标记
        {
            for(int x=n; x!=1; )
            {
                if(src[x] > 0)
                {
                    temp = path[src[x]][x];
                    use[temp] += flow[n], x = src[x];
                }
                else
                {
                    temp = 0 - src[x];
                    temp = path[temp][x];
                    use[temp] -= flow[n], x = 0 - src[x];
                }
            }
            InitMark();
        }
    }
    int ans = 0;
    for(int x=bg.first[n]; ~x; x=bg.Next[x])
        ans += use[x];
    return ans;
}
int main(void)
{
    int n, m, u, v, c;
    while(~scanf("%d %d", &n, &m))
    {
        fg.init();
        bg.init();
        while(m--)
        {
            scanf("%d %d %d", &u, &v, &c);
            fg.AddEdge(u, v, c);
            bg.AddEdge(v, u, c);
        }
        printf("%d\n", FordFulkerson(n));
    }
    return 0;
}
