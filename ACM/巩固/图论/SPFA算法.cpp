#include <cstdio>
#include <deque>
#include <string.h>
using namespace std;
const int N = 1e5+10, M = 2e6+20, INF = 0x3f3f3f3f;
int u[M], v[M], w[M], Next[M], first[N], D[N];
deque<int> dq;
bool vis[N] = {0};
inline void bulid(int from, int to, int weight, int t)
{
    u[t] = from, v[t] = to, w[t] = weight;
    Next[t] = first[from];
    first[from] = t;
}
int SPFA(int n, int s, int t)
{
    int top;
    vis[s] = true;
    dq.push_front(s);
    memset(D, INF, sizeof(D));
    D[s] = 0;
    while(!dq.empty())
    {
        top = dq.front();
        dq.pop_front();
        for(int x=first[top]; ~x; x=Next[x])
        {
            if(D[top] + w[x] < D[v[x]])
            {
                D[v[x]] = D[top] + w[x];
                if(!vis[v[x]])
                {
                    vis[v[x]] = true;
                    if(!dq.empty() && D[v[x]] < D[dq.front()])
                        dq.push_front(v[x]);
                    else
                        dq.push_back(v[x]);
                }
            }
        }
        vis[top] = false;
    }
    return D[t];
}
int main(void)
{
    int n, m, s, t, from, to, weight;
    scanf("%d %d %d %d", &n, &m, &s, &t);
    memset(first, -1, sizeof(first));
    for(int i=0; m--; )
    {
        scanf("%d %d %d", &from, &to, &weight);
        --from, --to;
        bulid(from, to, weight, i++);
        bulid(to, from, weight, i++);
    }
    printf("%d\n", SPFA(n, --s, --t));
    return 0;
}
