#include <cstdio>
typedef long long int LL;
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
LL work(LL a, LL b, LL c)
{
	LL x = 0;
	LL y = 1;
	LL d = gcd(a, b);
	if(c % d)
		return -1;
	a /= d;
	b /= d;
	c /= d;
	exgcd(a, b, x, y);
	x = ((x * c) % b + b) % b;
	y = (c - a * x) / b;
	printf("%lld %lld\n", x, y);
}
int main(void)
{
	LL a, b, c;
	while(~scanf("%lld %lld %lld", &a, &b, &c))
		work(a, b, c);
}
