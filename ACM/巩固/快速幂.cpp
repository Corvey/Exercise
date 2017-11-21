LL qmul(LL x, LL y, LL P)
{
    if(x < y)
        return qmul(y, x, P);
    static LL ans;
    ans = 0;
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
    static LL ans;
    ans = 1;
    while(y)
    {
        if(y&1)
            ans = qmul(x, ans, P);
        x = qmul(x, x, P);
        y >>= 1;
    }
    return ans;
}