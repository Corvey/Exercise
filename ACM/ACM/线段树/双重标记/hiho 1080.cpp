#include <cstdio>
#include <string.h>
const int N = 1 << 18;
int isum[N], addtag[N], changetag[N], ql, qr, val, pos, n, order;
void bulid(int o=1, int L=1, int R=n)
{
    if(L == R)
        scanf("%d", isum+o);
    else
    {
        int M = L + R >> 1;
        bulid(o<<1, L, M);
        bulid(o<<1|1, M+1, R);
        isum[o] = isum[o<<1] + isum[o<<1|1];
    }
}
void pd(int o, int t)
{
    if(t > 1)
    {
        if(changetag[o] > 0)
        {
            changetag[o<<1] = changetag[o<<1|1] = changetag[o];
            addtag[o<<1] = addtag[o<<1|1] = 0;
            isum[o<<1] = (t-(t>>1)) * changetag[o];
            isum[o<<1|1] = (t>>1) * changetag[o];
            changetag[o] = -1;
        }
        if(addtag[o])
        {
            addtag[o<<1] += addtag[o];
            addtag[o<<1|1] += addtag[o];
            isum[o<<1] += (t-(t>>1)) * addtag[o];
            isum[o<<1|1] += (t>>1) * addtag[o];
            addtag[o] = 0;
        }
    }
}
void update(int o=1, int L=1, int R=n)
{
    if(ql <= L && R <= qr)
    {
        if(order)
        {
            changetag[o] = val;
            addtag[o] = 0;
            isum[o] = (R - L + 1) * val;
            return ;
        }
        else
        {
            addtag[o] += val;
            isum[o] += (R - L + 1) * val;
            return ;
        }
    }
    pd(o, R - L + 1);
    int M = L + R >> 1;
    if(ql <= M)
        update(o<<1, L, M);
    if(M < qr)
        update(o<<1|1, M+1, R);
    isum[o] = isum[o<<1] + isum[o<<1|1];
}
int query(int o=1, int L=1, int R=n)
{
    if(ql <= L && R <= qr)
        return isum[o];
    int ans = 0, M = L + R >> 1;
    pd(o, R - L + 1);
    if(ql <= M)
        ans += query(o<<1, L, M);
    if(M < qr)
        ans += query(o<<1|1, M+1, R);
    return ans;
}
int main(void)
{
    int m;
    scanf("%d %d", &n, &m);
    memset(addtag, 0, sizeof(addtag));
    memset(changetag, -1, sizeof(changetag));
    ++n;
    bulid();
    while(m--)
    {
        scanf("%d %d %d %d", &order, &ql, &qr, &val);
        ++ql, ++qr;
        update();
        printf("%d\n", isum[1]);
    }
}
