#include <cstdio>
#include <string.h>
#define mset(a, b) memset(a, b, sizeof(a))
typedef long long int LL;
const int N = 1e5+20, M = 5e5+50, P = 142857;
int u[M], v[M], first[N], Next[M], in[N];
LL w[N];
LL topo(int n)
{
    int from, to, heap[N], l = 0, r = 0;
    for(int i=1; i<=n; ++i)
        if(!in[i])
            heap[r++] = i;
    while(l < r)
    {
        from = heap[l++];
        for(int x=first[from]; ~x; x=Next[x])
        {
            to = v[x];
            w[to] += w[from];
            w[to] %= P;
            --in[to];
            if(!in[to])
                heap[r++] = to;
        }
    }
    LL ans = 0;
    for(int i=1; i<=n; ++i)
        ans = (ans + w[i]) % P;
    return ans;
}
int main(void)
{
    int n, m, k, t;
    while(~scanf("%d %d %d", &n, &m, &k))
    {
        mset(w, 0);
        mset(first, -1);
        mset(in, 0);
        for(int i=0; i<k; ++i)
        {
            scanf("%d", &t);
            ++w[t];
        }
        for(int i=0; i<m; )
        {
            scanf("%d %d", u+i, v+i);
            ++in[v[i]];
            Next[i] = first[u[i]];
            first[u[i]] = i++;
        }
        printf("%lld\n", topo(n));
    }
    return 0;
}
