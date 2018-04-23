#include <cstdio>
typedef long long int LL;
const int N = 2016;
int a[N], b[N];
LL ans;
int main(void)
{
    int n, m, nx, mx;
    while(~scanf("%d %d", &n, &m))
    {
        nx = n / N;
        mx = m / N;
        for(int i=0; i<N; ++i)
            a[i] = nx, b[i] = mx;
        nx = n % N;
        mx = m % N;
        for(int i=1; i<=nx; ++a[i++]);
        for(int i=1; i<=mx; ++b[i++]);
        ans = 0;
        for(int i=0; i<N; ++i)
            for(int j=0; j<N; ++j)
                if(i*j%2016 == 0)
                    ans += (LL)a[i] * b[j];
        printf("%lld\n", ans);
    }
    return 0;
}
