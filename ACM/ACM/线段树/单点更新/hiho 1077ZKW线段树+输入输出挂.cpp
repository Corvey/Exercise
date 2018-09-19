#include <cstdio>
#define small(a, b) (a < b ? a : b)
const int N = 1 << 21, INF = 0x3f3f3f3f;
int imin[N], M;
char str[10];
inline int read(void)
{
    static int readnum;
    static char ch;
    readnum = 0;
    for(ch = getchar(); ch < '0' || ch > '9'; ch = getchar());
    for(; ch >= '0' && ch <= '9'; ch = getchar())
        readnum = readnum * 10 + ch - '0';
    return readnum;
}
inline int write(int x)
{
    static int wn;
    wn = 0;
    do
    {
        str[wn++] = x % 10 + '0';
    } while (x/=10);
    while(wn--)
        putchar(str[wn]);
    putchar('\n');
}
inline void bulid(int n)
{
    for(M=1; M<n+2; M<<=1);
    for(int i=M+1; i<=M+n; ++i)
        imin[i] = read();
    for(int i=M-1; i; --i)
        imin[i] = small(imin[i<<1], imin[i<<1|1]);
}
inline void update(int t, int data)
{
    imin[M+t] = data;
    for(t = t + M >> 1; t; t>>=1)
        imin[t] = small(imin[t<<1], imin[t<<1|1]);
}
inline int query(int l, int r)
{
    static int ans;
    ans = INF;
    l = l - 1 + M;
    r = r + 1 + M;
    for(; l^r^1; l>>=1, r>>=1)
    {
        if(~l&1)
            ans = small(ans, imin[l^1]);
        if(r&1)
            ans = small(ans, imin[r^1]);
    }
    return ans;
}
int main(void)
{
    int n, q, a, b;
    bool order;
    n = read();
    bulid(n);
    q = read() + 1;
    while(--q)
    {
        order = read();
        a = read();
        b = read();
        if(order)
            update(a, b);
        else
            write(query(a, b));
    }
    return 0;
}
