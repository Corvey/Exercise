#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long int LL;
const int N = 1e5+10, MLEN = 1e6+10, N2 = 2e5+20;
int u[MLEN], v[MLEN], dad[N], nu[N2], nv[N2], nw[N2], first[N2], Next[N2], cnt[N];
LL sum;
int FindDad(int x){
    return dad[x] == x ? x : dad[x] = FindDad(dad[x]);
}
LL Kruscal(int n, int MIN)
{
    int a, b, da, db, num = 0;
    LL ans = 0;
    memset(first, -1, sizeof(first));
    for(int i=1; i<=n; ++i)
        dad[i] = i;
    for(int i=MIN, t=1; t<n; ++i)
    {
        a = u[i];
        b = v[i];
        if(a)
        {
            da = FindDad(a);
            db = FindDad(b);
            if(da != db)
            {
                ans += i;
                dad[b] = dad[db] = da;

                nu[num] = --a, nv[num] = --b, nw[num] = i;
                Next[num] = first[a];
                first[a] = num++;

                nu[num] = b, nv[num] = a, nw[num] = i;
                Next[num] = first[b];
                first[b] = num++;
                ++t;
            }
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
            sum += (LL)nw[i] * cnt[nv[i]] * (n - cnt[nv[i]]);
        }
    }
}
int main(void)
{
    int t, n, m, a, b, w, MIN;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        MIN = MLEN;
        memset(u, 0, sizeof(u));
        for(int i=0; i<m; ++i)
        {
            scanf("%d %d %d", &a, &b, &w);
            u[w] = a, v[w] = b;
            MIN = w < MIN ? w : MIN;
        }
        printf("%lld ", Kruscal(n, MIN));
        memset(cnt, 0, sizeof(cnt));
        sum = 0;
        DFS(n, 0, 0);
        printf("%.2lf\n", (double)sum / n / (n-1) * 2);
    }
}
