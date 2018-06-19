#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long int LL;
const int N = 1e5+10, M = 1e6+10, N2= 2e5+20;
int u[M], v[M], edge[M], dad[N], nu[N2], nv[N2], first[N2], Next[N2], cnt[N] = {0};
LL w[M], nw[N2], sum = 0;
bool cmp(const int a, const int b){
    return w[a] < w[b];
}
int FindDad(int x){
    return dad[x] == x ? x : dad[x] = FindDad(dad[x]);
}
LL Kruscal(int n)
{
    int x, a, b, da, db;
    memset(first, -1, sizeof(first));
    LL ans = 0;
    for(int i=1; i<=n; ++i)
        dad[i] = i;
    for(int i=0, t=1, num=0; t<n; ++i)
    {
        x = edge[i];
        a = u[x];
        b = v[x];
        da = FindDad(a);
        db = FindDad(b);
        if(da - db)
        {
            dad[b] = dad[db] = da;
            ans += w[x];

            nu[num] = --a, nv[num] = --b, nw[num] = w[x];
            Next[num] = first[a];
            first[a] = num++;

            nu[num] = b, nv[num] = a, nw[num] = w[x];
            Next[num] = first[b];
            first[b] = num++;

            ++t;
        }
    }
    return ans;
}
void DFS(int n, int from, int to)
{
    ++cnt[from];
    for(int i=first[from]; ~i; i=Next[i])
    {
        if(nv[i] != to)
        {
            DFS(n, nv[i], from);
            cnt[from] += cnt[nv[i]];
            sum += nw[i] * (n - cnt[nv[i]]) * cnt[nv[i]];
        }
    }
}
int main(void)
{
    int n, m, t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        for(int i=0; i<m; ++i)
        {
            scanf("%d %d %lld", u+i, v+i, w+i);
            edge[i] = i;
        }
        sort(edge, edge+m, cmp);
        printf("%lld ", Kruscal(n));
        DFS(n, 0, 0);
        printf("%.2lf\n", (double)sum / n / (n-1) * 2);
        sum = 0;
        memset(cnt, 0, sizeof(cnt));
    }
    return 0;
}
