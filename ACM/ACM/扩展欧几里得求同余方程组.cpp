#include <cstdio>
typedef long long int LL;
const int N = 1e3+10;
LL m[N], r[N];
LL gcd(LL x, LL y){
    return y ? gcd(y, x%y) : x;
}
void exgcd(LL a, LL b, LL &x, LL &y)
{
    static LL temp;
    if(a % b == 0)
        return ;
    exgcd(b, a%b, x, y);
    temp = y;
    y = x - a / b * y;
    x = temp;
}
LL work(int n)
{
    LL a, b, c, d, x, y;
    for(int i=1; i<n; ++i)
    {
        a = m[0];
        b = m[i];
        c = r[i] - r[0];
        d = gcd(a, b);
        if(c % d)
            return -1;
        a /= d;
        b /= d;
        c /= d;
        x = 0;
        y = 1;
        exgcd(a, b, x, y);
        x = ((x * c) % b + b) % b;
        r[0] += x * m[0];
        m[0] = a * m[i];
        r[0] %= m[0];
    }
    return r[0] < 0 ? r[0] + m[0] : r[0];
}
int main(void)
{
    int n;
    while(~scanf("%d", &n))
    {
        for(int i=0; i<n; ++i)
            scanf("%lld %lld", m+i, r+i);
        printf("%lld\n", work(n));
    }
    return 0;
}
