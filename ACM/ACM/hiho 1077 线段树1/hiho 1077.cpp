#include <cstdio>
#include <string.h>
#define small(a, b) (a < b ? a : b)
const int N = 5e6, INF = 0x3f3f3f3f;
int imin[N], ql, qr, pos, data;
void updata(int now, int l, int r)
{
    int mid = l + (r - l) / 2;
    if(l == r)
        imin[now] = data;
    else
    {
        if(pos <= mid)
            updata(now * 2, l, mid);
        else
            updata(now * 2 + 1, mid+1, r);
        imin[now] = small(imin[now*2], imin[now*2+1]);
    }
}
int query(int now, int l, int r)
{
    int mid = l + (r - l) / 2, ans = INF;
    if(ql <= l && r <= qr)
        return imin[now];
    if(ql <= mid)
        ans = small(ans, query(now*2, l, mid));
    if(mid < qr)
        ans = small(ans, query(now*2+1, mid+1, r));
    return ans;
}
inline int read(void)
{
    int ans = 0;
    char ch = getchar();
    for(; ch < '0' || ch > '9'; ch = getchar());
    do
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    } while (ch >= '0' && ch <= '9');
    return ans;
}
int main(void)
{
    int n, m, order;
    memset(imin, INF, sizeof(imin));
    n = read();
    for(int i=1; i<=n; ++i)
    {
        data = read();
        pos = i;
        updata(1, 1, n);
    }
    m = read();
    while(m--)
    {
        scanf("%d", &order);
        if(order)
        {
            pos = read();
            data = read();
            updata(1, 1, n);
        }
        else
        {
            ql = read();
            qr = read();
            printf("%d\n", query(1, 1, n));
        }
    }
}
