#include <cstdio>
#include <string.h>
const int N = 1 << 19;
int imax[N], ql, qr, val, n, pos;
inline int big(int a, int b){
    return a > b ? a : b;
}
inline int read(void)
{
    static int ans;
    static char ch;
    for(ch=getchar(); ch < '0' || ch > '9'; ch = getchar());
    for(ans = 0; ch >= '0' && ch <= '9'; ch = getchar())
        ans = ans * 10 + ch - '0';
    return ans;
}
void bulid(int o=1, int L=1, int R=n)
{
    if(L == R)
        imax[o] = read();
    else
    {
        int M = L + R >> 1;
        bulid(o<<1, L, M);
        bulid(o<<1|1, M+1, R);
        imax[o] = big(imax[o<<1], imax[o<<1|1]);
    }
}
void update(int o=1, int L=1, int R=n)
{
    if(L == R)
        imax[o] = val;
    else
    {
        int M = L + R >> 1;
        if(pos <= M)
            update(o<<1, L, M);
        else
            update(o<<1|1, M+1, R);
        imax[o] = big(imax[o<<1], imax[o<<1|1]);
    }
}
int query(int o=1, int L=1, int R=n)
{
    if(ql <= L && R <= qr)
        return imax[o];
    int ans = 0, M = L + R >> 1;
    if(ql <= M)
        ans = big(ans, query(o<<1, L, M));
    if(M < qr)
        ans = big(ans, query(o<<1|1, M+1, R));
    return ans;
}
int main(void)
{
    int q;
    char order[3];
    while(~scanf("%d %d", &n, &q))
    {
        bulid();
        while(q--)
        {
            scanf("%s", &order);
            if(order[0] == 'Q')
            {
                ql = read();
                qr = read();
                printf("%d\n", query());
            }
            else
            {
                pos = read();
                val = read();
                update();
            }
        }
    }
    return 0;
}
