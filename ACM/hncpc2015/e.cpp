#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
const int N = 505, INF = 0x3f3f3f3f, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int g[N][N], D[N][N], cnt[N][N][4], n, m;
bool vis[N][N];
struct vertex{
    int x, y;
}from, to, vtemp, vtop;
struct node{
    int x, y, way, d;
    bool operator < (const node &a) const {
        return d > a.d;
}}ntemp, ntop;
deque<vertex> dq;
priority_queue<node> pq;
inline int read(void)
{
    int ans = 0;
    char ch = getchar();
    for(; ch == ' ' || ch == '\n'; ch = getchar());
    while(1)
    {
        if(ch >= '0' && ch <= '9')
            ans = ans * 10 + ch - '0';
        else if(ch == '*')
            return -1;
        else
            break;
        ch = getchar();
    }
    return ans;
}
int Dijkstra(void)
{
    int d, nd;
    memset(D, INF, sizeof(D));
    memset(vis, 0, sizeof(vis));
    D[from.x][from.y] = g[from.x][from.y];
    vis[from.x][from.y] = true;
    dq.push_front(from);
    while(!dq.empty())
    {
        vtop = dq.front();
        dq.pop_front();
        d = D[vtop.x][vtop.y];
        for(int i=0; i<4; ++i)
        {
            vtemp.x = vtop.x + dx[i];
            vtemp.y = vtop.y + dy[i];
            if(vtemp.x >=0 && vtemp.x < n && vtemp.y >= 0 && vtemp.y < m && g[vtemp.x][vtemp.y] != -1)
            {
                nd = d + g[vtemp.x][vtemp.y];
                if(nd < D[vtemp.x][vtemp.y])
                {
                    D[vtemp.x][vtemp.y] = nd;
                    if(!vis[vtemp.x][vtemp.y])
                    {
                        vis[vtemp.x][vtemp.y] = true;
                        if(!dq.empty() && nd < D[dq.front().x][dq.front().y])
                            dq.push_front(vtemp);
                        else
                            dq.push_back(vtemp);
                    }
                }
            }
        }
        vis[vtop.x][vtop.y] = false;
    }
    return D[to.x][to.y] == INF ? -1 : D[to.x][to.y];
}
int BFS(void)
{
    memset(cnt, INF, sizeof(cnt));
    ntop.x = from.x, ntop.y = from.y, ntop.d = g[from.x][from.y], ntop.way = -1;
    cnt[ntop.x][ntop.y][0] = ntop.d;
    cnt[ntop.x][ntop.y][1] = ntop.d;
    cnt[ntop.x][ntop.y][2] = ntop.d;
    cnt[ntop.x][ntop.y][3] = ntop.d;
    pq.push(ntop);
    while(!pq.empty())
    {
        ntop = pq.top();
        pq.pop();
        for(int i=0; i<4; ++i)
        {
            if(ntop.way == i)
                continue;
            ntemp.x = ntop.x + dx[i];
            ntemp.y = ntop.y + dy[i];
            if(ntemp.x >=0 && ntemp.x < n && ntemp.y >= 0 && ntemp.y < m && g[ntemp.x][ntemp.y] != -1)
            {
                ntemp.d = ntop.d + g[ntemp.x][ntemp.y];
                if(ntemp.x == to.x && ntemp.y == to.y)
                {
                    while(!pq.empty())
                        pq.pop();
                    return ntemp.d;
                }
                if(ntemp.d < cnt[ntemp.x][ntemp.y][i])
                {
                    ntemp.way = i;
                    cnt[ntemp.x][ntemp.y][i] = ntemp.d;
                    pq.push(ntemp);
                }
            }
        }
    }
    return -1;
}
int main(void)
{
//    freopen("in.txt", "rt", stdin);
//    freopen("out.txt", "wt", stdout);
    int kase = 0, ans;
    while(~scanf("%d %d %d %d %d %d", &n, &m, &from.x, &from.y, &to.x, &to.y))
    {
        --from.x, --from.y, --to.x, --to.y;
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                g[i][j] = read();
        printf("Case %d: ", ++kase);
        if(g[from.x][from.y] == -1 || g[to.x][to.y] == -1)
            printf("-1 -1\n");
        else
        {
            ans = Dijkstra();
            if(ans == -1)
                printf("-1 -1\n");
            else
                printf("%d %d\n", ans, BFS());
        }
    }
}
