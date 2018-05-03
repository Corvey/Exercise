#include <cstdio>
#include <time.h>
typedef long long int LL;
const LL testnum[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
LL qmul(LL x, LL y, LL P)
{
    if(x < y)
        return qmul(y, x, P);
    LL ans = 0;
    while(y)
    {
        if(y&1)
            ans = (ans + x) % P;
        x = (x << 1) % P;
        y >>= 1;
    }
    return ans;
}
LL qpow(LL x, LL y, LL P)
{
    if(y == 0)
        return 1;
    if(x <= 1)
        return x;
    LL ans = 1;
    while(y)
    {
        if(y&1)
            ans = qmul(x, ans, P);
        x = qmul(x, x, P);
        y >>= 1;
    }
    return ans;
}
bool MRtest(LL n)
{
    if(n <= 2)
        return n == 2;
    if(!(n&1))
        return false;
    LL x, y, index = n - 1;
    for(; index > 2 && !(index&1); index>>=1);
    for(int i=0; i<12; ++i)
    {
        if(testnum[i] > n-1)
            break;
        x = qpow(testnum[i], index, n);
        while(index < n)
        {
            y = qmul(x, x, n);
            if(y == 1 && x != 1 && x != n-1)
                return false;
            x = y;
            index <<= 1;
        }
        if(x != 1)
            return false;
    }
    return true;
}
int main(void)
{
    int kase;
    LL x;
    scanf("%d", &kase);
    while(kase--)
    {
        scanf("%lld", &x);
        printf("%s\n", MRtest(x) ? "Yes" : "No");
    }
    return 0;
}
