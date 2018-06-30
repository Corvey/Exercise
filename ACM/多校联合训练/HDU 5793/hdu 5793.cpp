#include <cstdio>
typedef long long int LL;
const LL P = 1e9 + 7;
LL qpow(LL x, LL y)
{
    LL ans = 1;
    if(!y)
        return ans;
    if(x <= 1)
        return x;
    while(y)
    {
        if(y&1)
            ans = ans * x % P;
        x = x * x % P;
        y >>= 1;
    }
    return ans;
}
int main(void)
{
    int kase;
    LL n, m;
    scanf("%d", &kase);
    while(kase--)
    {
        scanf("%lld %lld", &n, &m);
        printf("%lld\n", (qpow(m, n+1) - 1 + P) % P * qpow(m-1, P-2) % P);
    }
}
