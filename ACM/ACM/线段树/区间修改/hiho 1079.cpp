#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 1 << 20, M = 2e5+100;
int op[M], np[M], pos[M], idata[N], lazy[N], ql, qr, data, wz;
bool vis[M] = {0};
bool cmp(const int a, const int b){
    return op[a] < op[b];
}
inline void pd(int o)
{
    static int l, r;
    if(lazy[o] > 0)
    {
        l = o << 1;
        r = o << 1 | 1;
        idata[l] = idata[r] = lazy[l] = lazy[r] = lazy[o];
        lazy[o] = -1;
    }
}
void change(int o, int L, int R)
{
    if(ql <= L && R <= qr)
    {
        idata[o] = data;
        lazy[o] = data;
        return ;
    }
    pd(o);
    int M = L + R >> 1;
    if(ql <= M)
        change(o<<1, L, M);
    if(M < qr)
        change(o<<1|1, M+1, R);
}
int query(int o, int L, int R)
{
    if(L == R)
        return idata[o];
    pd(o);
    int M = L + R >> 1;
    if(wz <= M)
        return query(o<<1, L, M);
    else
        return query(o<<1|1, M+1, R);
}
int main(void)
{
    int n, l, ans = 0;
    scanf("%d %d", &n, &l);
    memset(lazy, -1, sizeof(lazy));
    n <<= 1;
    for(int i=0; i<n; ++i)
    {
        scanf("%d", op+i);
        pos[i] = i;
    }
    sort(pos, pos+n, cmp);
    np[pos[0]] = 1;
    l = 1;
    for(int i=1; i<n; ++i)
        np[pos[i]] = op[pos[i]] == op[pos[i-1]] ? np[pos[i-1]] : ++l;
    l = np[pos[n-1]] - 1;
    for(int i=0; i<n; ++i)
    {
        ql = np[i];
        qr = np[++i] - 1;
        data = i + 1 >> 1;
        change(1, 1, l);
    }
    for(int i=1; i<=l; ++i)
    {
        wz = i;
        n = query(1, 1, l);
        if(!vis[n] && n)
        {
            ++ans;
            vis[n] = true;
        }
    }
    printf("%d\n", ans);
    return 0;
}
