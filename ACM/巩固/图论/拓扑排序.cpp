#include <cstdio>
#include <string.h>
const int N = 1e5+10, M = 5e5+10;
int u[M], v[M], Next[M], first[N], in[N], heap[N];
bool topo(int n)
{
    int top, bottom, t, done = 0;
    top = bottom = 0;
    for(int i=0; i<n; ++i)
        if(!in[i])
            heap[bottom++] = i, ++done;
    while(top < bottom && done != n)
    {
        t = heap[top++];
        for(int x=first[t]; ~x; x=Next[x])
            if(!--in[v[x]])
                heap[bottom++] = v[x], ++done;
    }
    return done == n;
}
int main(void)
{
    int kase, n, m;
    scanf("%d", &kase);
    while(kase--)
    {
        scanf("%d %d", &n, &m);
        memset(first, -1, sizeof(first));
        memset(in, 0, sizeof(in));
        for(int i=0; i<m; ++i)
        {
            scanf("%d %d", u+i, v+i);
            --u[i], --v[i];
            Next[i] = first[u[i]];
            first[u[i]] = i;
            ++in[v[i]];
        }
        printf("%s\n", topo(n) ? "Correct" : "Wrong");
    }
    return 0;
}
