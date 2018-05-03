#include <cstdio>
#include <string.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define lowbit(x) (x&-x)
const int N = 1e6+10;
int prime[N], n, c[N] = {0};
bool IsPrime[N];
inline void Add(int t){
    for(; t<=N; ++c[t], t+=lowbit(t));
}
inline int Sum(int t)
{
    int sum = 0;
    for(; t; sum+=c[t], t-=lowbit(t));
    return sum;
}
void work(void)
{
    int t;
    mset(IsPrime, 1);
    n = 0;
    for(int i=2; i<=N; ++i)
    {
        if(IsPrime[i])
        {
            prime[n++] = i;
            Add(i);
        }
        for(int j=0; j<n; ++j)
        {
            t = i * prime[j];
            if(t > N)
                break;
            IsPrime[t] = false;
            if(!(i % prime[j]))
                break;
        }
    }
}
int main(void)
{
    work();
    while(~scanf("%d", &n))
        printf("%d\n", Sum(n));
    return 0;
}
