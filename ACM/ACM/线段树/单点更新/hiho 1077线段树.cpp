#include <cstdio>
#include <string.h>
#define small(a, b) (a < b ? a : b)
const int N = 1 << 21;
int imin[N], ql, qr, val, pos, n;
void bulid(int o=1, int L=1, int R=n)
{
    if(L == R)
        scanf("%d", imin+o);
    else
    {
        int M = L + R >> 1;
        bulid(o<<1, L, M);
        bulid(o<<1|1, M+1, R);
        imin[o] = small(imin[o<<1], imin[o<<1|1]);
    }
}
void update(int o=1, int L=1, int R=n)
{
    if(L == R)
        imin[o] = val;
    else
    {
        int M = L + R >> 1;
        if(pos <= M)
            update(o<<1, L, M);
        else
            update(o<<1|1, M+1, R);
        imin[o] = small(imin[o<<1], imin[o<<1|1]);
    }
}
int query(int o=1, int L=1, int R=n)
{
    if(ql <= L && R <= qr)
        return imin[o];
    int M = L + R >> 1, ans = 0x3f3f3f3f;
    if(ql <= M)
        ans = small(ans, query(o<<1, L, M));
    if(M < qr)
        ans = small(ans, query(o<<1|1, M+1, R));
    return ans;
}
int main(void)
{
    int m, order;
    scanf("%d", &n);
    bulid();
    scanf("%d", &m);
    while(m--)
    {
        scanf("%d", &order);
        if(order)
        {
            scanf("%d %d", &pos, &val);
            update();
        }
        else
        {
            scanf("%d %d", &ql, &qr);
            printf("%d\n", query());
        }
    }
}
