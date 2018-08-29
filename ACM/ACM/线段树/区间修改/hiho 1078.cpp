#include <cstdio>
#include <string.h>
const int N = 1 << 18, INF = 0x3f3f3f3f;
int isum[N], lazy[N], ql, qr, data, pos, n;
void bulid(int o=1, int L=1, int R=n)
{
    if(L == R)
        isum[o] = data;
    else
    {
        int M = L + R >> 1;
        if(pos <= M)
            bulid(o<<1, L, M);
        else
            bulid(o<<1|1, M+1, R);
        isum[o] = isum[o<<1] + isum[o<<1|1];
    }
}
inline void pd(int o, int t)
{
    static int l, r;
    if(t > 1 && lazy[o] != INF)
    {
        l = o<<1;
        r = o<<1|1;
        lazy[l] = lazy[o];
        lazy[r] = lazy[o];
        isum[l] = lazy[o] * (t - (t>>1));
        isum[r] = lazy[o] * (t>>1);
        lazy[o] = INF;
    }
}
void change(int o=1, int L=1, int R=n)
{
    if(ql <= L && R <= qr)
    {
        isum[o] = data * (R - L + 1);
        lazy[o] = data;
        return ;
    }
    int M = L + R >> 1;
    pd(o, R - L + 1);
    if(ql <= M)
        change(o<<1, L, M);
    if(M < qr)
        change(o<<1|1, M+1, R);
    isum[o] = isum[o<<1] + isum[o<<1|1];
}
int query(int o=1, int L=1, int R=n)
{
    if(ql <= L && R <= qr)
        return isum[o];
    int M = L + R >> 1, ans = 0;
    pd(o, R - L + 1);
    if(ql <= M)
        ans += query(o<<1, L, M);
    if(M < qr)
        ans += query(o<<1|1, M+1, R);
    return ans;
}
int main(void)
{
    int m, order;
    scanf("%d", &n);
    memset(isum, 0, sizeof(isum));
    memset(lazy, INF, sizeof(lazy));
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &data);
        pos = i;
        bulid();
    }
    scanf("%d", &m);
    while(m--)
    {
        scanf("%d %d %d", &order, &ql, &qr);
        if(order)
        {
            scanf("%d", &data);
            change();
        }
        else
            printf("%d\n", query());
    }
}