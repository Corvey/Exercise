#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 1e5+10, M = 1e6+20;
int u[M], v[M], w[M], pos[M], dad[N];
bool cmp(const int a, const int b){
    return w[a] < w[b];
}
int Find(int x){
    return dad[x] == x ? x : dad[x] = Find(dad[x]);
}
int Kruscal(int n)
{
    int wz, a, b, da, db, ans = 0;
    --n;
    for(int t=0; n; ++t)
    {
        wz = pos[t];
        a = u[wz];
        b = v[wz];
        da = dad[a] == -1 ? dad[a] = a : Find(a);
        db = dad[b] == -1 ? dad[b] = b : Find(b);
        if(da != db)
        {
            ans += w[wz];
            dad[b] = dad[db] = da;
            --n;
        }
    }
    return ans;
}
int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    memset(dad, -1, sizeof(dad));
    for(int i=0; i<m; ++i)
    {
        scanf("%d %d %d", u+i, v+i, w+i);
        pos[i] = i;
    }
    sort(pos, pos+m, cmp);
    printf("%d\n", Kruscal(n));
    return 0;
}
