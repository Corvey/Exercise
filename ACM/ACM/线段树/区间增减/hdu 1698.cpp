#include <cstdio>
#include <string.h>
const int N = 1 << 18;
int isum[N], settag[N], ql, qr, val, n;
inline void pd(int o, int t)
{
    static int L, R;
    if(t > 1 && settag[o] > 0)
    {
        L = o << 1;
        R = o << 1 | 1;
        settag[L] = settag[R] = settag[o];
        isum[L] = (t - (t>>1)) * settag[o];
        isum[R] = (t>>1) * settag[o];
        settag[o] = 0;
    }
}
void SET(int o=1, int L=1, int R=n)
{
    if(ql <= L && R <= qr)
    {
        settag[o] = val;
        isum[o] = (R - L + 1) * val;
        return ;
    }
    pd(o, R - L + 1);
    int M = L + R >> 1;
    if(ql <= M)
        SET(o<<1, L, M);
    if(M < qr)
        SET(o<<1|1, M+1, R);
    isum[o] = isum[o<<1] + isum[o<<1|1];
}
int main(void)
{
    int kase, q;
    scanf("%d", &kase);
    for(int T=0; T<kase; )
    {
        scanf("%d", &n);
        ql = 1, qr = n, val = 1;
        SET();
        scanf("%d", &q);
        while(q--)
        {
            scanf("%d %d %d", &ql, &qr, &val);
            SET();
        }
        printf("Case %d: The total value of the hook is %d.\n", ++T, isum[1]);
    }
}
