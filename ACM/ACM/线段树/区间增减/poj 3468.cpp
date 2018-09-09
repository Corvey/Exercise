#include <cstdio>
#include <string.h>
typedef long long int LL;
const int N = 1<<18;
LL isum[N], lazy[N];
int pos, data, ql, qr;
void bulid(int o, int L, int R)
{
    if(L == R)
        isum[o] += data;
    else
    {
        int M = L + R >> 1;
        if(pos <= M)
            bulid(o<<1, L, M);
        else
            bulid(o<<1|1, M+1, R);
        isum[o] = isum[o<<1] + isum[o<<1|1];
    }
}
inline void pushdown(int o, int t)
{
    if(t > 1 && lazy[o])
    {
        lazy[o<<1] += lazy[o];
        lazy[o<<1|1] += lazy[o];
        isum[o<<1] += lazy[o] * (t - (t>>1));
        isum[o<<1|1] += lazy[o] * (t>>1);
        lazy[o] = 0;
    }
}
void Add(int o, int L, int R)
{
    if(ql <= L && R <= qr)
    {
        lazy[o] += data;
        isum[o] += (LL)data * (R - L + 1);
        return ;
    }
    pushdown(o, R - L + 1);
    int M = L + R >> 1;
    if(ql <= M)
        Add(o<<1, L, M);
    if(qr > M)
        Add(o<<1|1, M+1, R);
    isum[o] = isum[o<<1] + isum[o<<1|1];
}
LL query(int o, int L, int R)
{
    if(ql <= L && R <= qr)
        return isum[o];
    pushdown(o, R - L + 1);
    LL ans = 0;
    int M = L + R >> 1;
    if(ql <= M)
        ans += query(o<<1, L, M);
    if(qr > M)
        ans += query(o<<1|1, M+1, R);
    return ans;
}
inline int read(void)
{
    static char ch;
    static int readnum;
    static bool fuhao;
    readnum = 0;
    fuhao = false;
    for(ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
        if(ch == '-')
            fuhao = true;
    for(; ch >= '0' && ch <= '9'; ch = getchar())
        readnum = readnum * 10 + ch - '0';
    return fuhao ? 0 - readnum : readnum;
}
int main(void)
{
    int n, m;
    char order[3];
    while(~scanf("%d %d", &n, &m))
    {
        memset(isum, 0, sizeof(isum));
        memset(lazy, 0, sizeof(lazy));
        for(int i=1; i<=n; ++i)
        {
            data = read();
            pos = i;
            bulid(1, 1, n);
        }
        while(m--)
        {
            scanf("%s", order);
            ql = read();
            qr = read();
            if(order[0] == 'Q')
                printf("%lld\n", query(1, 1, n));
            else
            {
                data = read();
                Add(1, 1, n);
            }
        }
    }
    return 0;
}
