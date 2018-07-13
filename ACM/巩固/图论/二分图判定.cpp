#include <cstdio>
#include <string.h>
const int N = 1e4+10, M = 8e4+10;
int u[M], v[M], Next[M], first[N], heap[N];
bool vis[N], cnt[N];
inline void bulid(int from, int to, int t)
{
    u[t] = from, v[t] = to;
    Next[t] = first[from];
    first[from] = t;
}
bool judge(int from)
{
    int top, bottom, t;
    vis[from] = true;
    cnt[from] = 0;
    top = bottom = 0;
    heap[bottom++] = from;
    while(top < bottom)
    {
        t = heap[top++];
        for(int x=first[t]; ~x; x=Next[x])
        {
            if(!vis[v[x]])
            {
                vis[v[x]] = true;
                cnt[v[x]] = !cnt[t];
                heap[bottom++] = v[x];
            }
            else if(cnt[v[x]] == cnt[t])
                return false;
        }
    }
    return true;
}
int main(void)
{
    int kase, n, m, from, to;
    bool tag;
    scanf("%d", &kase);
    while(kase--)
    {
        scanf("%d %d", &n, &m);
        memset(first, -1, sizeof(first));
        for(int i=0; m--; )
        {
            scanf("%d %d", &from, &to);
            bulid(--from, --to, i++);
            bulid(to, from, i++);
        }
        memset(vis, 0, sizeof(vis));
        tag = true;
        for(int i=0; i<n; ++i)
        {
            if(!vis[i] && !judge(i))
            {
                tag = false;
                break;
            }
        }
        printf("%s\n", tag ? "Correct" : "Wrong");
    }
    return 0;
}
