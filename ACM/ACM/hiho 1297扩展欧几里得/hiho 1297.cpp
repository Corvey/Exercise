#include <cstdio>
typedef long long int LL;
LL temp;
LL gcd(LL x, LL y){
    return !y ? x : gcd(y, x%y);
}
void extend_gcd(LL a, LL b, LL &x, LL &y)
{
    if(a % b == 0)
    {
        x = 0, y = 1;
        return ;
    }
    extend_gcd(b, a%b, x, y);
    temp = x;
    x = y;
    y = temp - (a / b) * y;
    return ;
}
LL work(LL s1, LL s2, LL v1, LL v2, LL m)
{
    LL a = v1 - v2;
    a += a < 0 ? m : 0;
    LL b = m;
    LL c = s2 - s1;
    LL d = gcd(a, b);
    if(c % d)
        return -1;
    a /= d;
    b /= d;
    c /= d;
    LL ansx, ansy;
    extend_gcd(a, b, ansx, ansy);
    for(ansx = (ansx * c) % b; ansx < 0; ansx += b);
    return ansx;
}
int main(void)
{
    LL s1, s2, v1, v2, m, yue;
    while(~scanf("%lld %lld %lld %lld %lld", &s1, &s2, &v1, &v2, &m))
        printf("%lld\n", work(s1, s2, v1, v2, m));
    return 0;
}
