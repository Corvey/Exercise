#include <cstdio>
#include <string.h>
#define big(a, b) (a > b ? a : b)
const int N = 1 << 19;
int imax[N], M;
inline int read(void)
{
    static int ans;
    static char ch;
    for(ch = getchar(); ch < '0' || ch > '9'; ch = getchar());
    for(ans = 0; ch >= '0' && ch <= '9'; ch = getchar())
        ans = ans * 10 + ch - '0';
    return ans;
}
inline void bulid(int n, int val)
{
    for(M=1; M<=n; M<<=1);
    for(int i=0; i<n; ++i)
        imax[i+M] = val;
    for(int i=M-1; i; --i)
        imax[i] = big(imax[i<<1], imax[i<<1|1]);
}
inline int update(int val)
{
    static int t;
    if(val > imax[1])
        return -1;
    for(t=1; t<M; )
    {
        t <<= 1;
        t += val <= imax[t] ? 0 : 1;
    }
    imax[t] -= val;
    for(int i=t>>1; i; i>>=1)
        imax[i] = big(imax[i<<1], imax[i<<1|1]);
    return t - M + 1;
}
int main(void)
{
    int h, w, n;
    while(~scanf("%d %d %d", &h, &w, &n))
    {
        memset(imax, 0, sizeof(imax));
        bulid(h <= n ? h : n, w);
        while(n--)
            printf("%d\n", update(read()));
    }
}
