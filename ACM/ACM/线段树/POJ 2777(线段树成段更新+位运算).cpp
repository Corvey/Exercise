#include <cstdio>
#include <string.h>
const int N = 1 << 18;
int tree[N], settag[N], ql, qr, val, n;
inline void SWAP(int &x, int &y)
{
    static int t;
    t = x, x = y, y = t;
}
inline int countone(int x)
{
    static int ans;
    for(ans = 0; x; ans+=x&1, x>>=1);
    return ans;
}
inline void pd(int o, int t)
{
    static int L, R;
    if(t > 1)
    {
        if(settag[o])
        {
            L = o << 1;
            R = o << 1 | 1;
            settag[L] = settag[R] = tree[L] = tree[R] = settag[o];
            settag[o] = 0;
        }
    }
}
void SET(int o=1, int L=1, int R=n)
{
    if(ql <= L && R <= qr)
    {
        settag[o] = val;
        tree[o] = val;
        return ;
    }
    pd(o, R - L + 1);
    int M = L + R >> 1;
    if(ql <= M)
        SET(o<<1, L, M);
    if(M < qr)
        SET(o<<1|1, M+1, R);
    tree[o] = tree[o<<1] | tree[o<<1|1];
}
int query(int o=1, int L=1, int R=n)
{
    if(ql <= L && R <= qr)
        return tree[o];
    pd(o, R - L + 1);
    int M = L + R >> 1, ans = 0;
    if(ql <= M)
        ans |= query(o<<1, L, M);
    if(M < qr)
        ans |= query(o<<1|1, M+1, R);
    return ans;
}
int main(void)
{
    int t, o;
    char order[3];
    while(~scanf("%d %d %d", &n, &t, &o))
    {
        memset(settag, 0, sizeof(settag));
        settag[1] = 1;
        tree[1] = 1;
        while(o--)
        {
            scanf("%s %d %d", order, &ql, &qr);
            if(ql > qr)
                SWAP(ql, qr);
            if(order[0] == 'P')
                printf("%d\n", countone(query()));
            else
            {
                scanf("%d", &val);
                val = 1 << val - 1;
                SET();
            }
        }
    }
}
