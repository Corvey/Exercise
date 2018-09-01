#include <cstdio>
#include <string.h>
const int N = 1 << 18, data = 1;
int isum[N], lazy[N], ql, qr;
inline void pushdown(int o, int t)
{
    if(t > 1 && lazy[o] > 0)
    {
        lazy[o<<1] += lazy[o];
        lazy[o<<1|1] += lazy[o];
        isum[o<<1] += lazy[o] * (t - (t>>1));
        isum[o<<1|1] += lazy[o] * (t>>1);
        lazy[o] = 0;
    }
}
void Add(int o, int L, int R)
{
    if(ql <= L && R <= qr)
    {
        lazy[o] += data;
        isum[o] += data * (R - L + 1);
        return ;
    }
    pushdown(o, R - L + 1);
    int M = L + R >> 1;
    if(ql <= M)
        Add(o<<1, L, M);
    if(M < qr)
        Add(o<<1|1, M+1, R);
    isum[o] = isum[o<<1] + isum[o<<1|1];
}
int query(int o, int L, int R)
{
    if(ql <= L && R <= qr)
        return isum[o];
    pushdown(o, R - L + 1);
    int M = L + R >> 1;
    int ans = 0;
    if(ql <= M)
        ans += query(o<<1, L, M);
    if(M < qr)
        ans += query(o<<1|1, M+1, R);
    return ans;
}
int main(void)
{
    int n;
    while(1)
    {
        scanf("%d", &n);
        if(!n)
            break;
        memset(isum, 0, sizeof(isum));
        memset(lazy, 0, sizeof(lazy));
        for(int i=0; i<n; ++i)
        {
            scanf("%d %d", &ql, &qr);
            Add(1, 1, n);
        }
        ql = qr = 1;
        printf("%d", query(1, 1, n));
        for(int i=2; i<=n; ++i)
        {
            ql = qr = i;
            printf(" %d", query(1, 1, n));
        }
        printf("\n");
    }
}
