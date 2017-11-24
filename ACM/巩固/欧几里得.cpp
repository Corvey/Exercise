LL gcd(LL a, LL b){
	return b ? gcd(b, a%b) : a;
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
//解不定方程
LL work(LL a, LL b, LL c)
{
	LL x = 0, y = 1;
	LL d = gcd(a, b);
	if(c % d)
		return -1;
	a /= d, b /= d, c /= d;
	exgcd(a, b, x, y);
	x = ((x * c) % b + b) % b;
	y = (c - a * x) / b;
	printf("%lld %lld\n", x, y);
}
//解模线性方程组
LL m[N], r[N];	//m为模数，r为余数
LL work(int n)
{
    LL a, b, c, d, x, y;
    for(int i=1; i<n; ++i)
    {
        a = m[0], b = m[i], c = r[i] - r[0], d = gcd(a, b);
        if(c % d)
            return -1;
        a /= d, b /= d, c /= d;
        x = 0, y = 1;
        exgcd(a, b, x, y);
        x = ((x * c) % b + b) % b;
        r[0] += x * m[0];
        m[0] = a * m[i];
        r[0] %= m[0];
    }
    return r[0] < 0 ? r[0] + m[0] : r[0];
}