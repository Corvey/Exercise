#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 2e4+50, M = 1 << 16;
int op[N], np[N], pos[N], idata[M], settag[M], n, len, wz, ql, qr, val;
bool vis[N];
bool cmp(const int a, const int b){
    return op[a] < op[b];
}
inline void pd(int o, int t)
{
    static int L, R;
    if(t > 1 && settag[o])
    {
        L = o << 1;
        R = o << 1 | 1;
        settag[L] = settag[R] = idata[L] = idata[R] = settag[o];
        settag[o] = 0;
    }
}
void SET(int o=1, int L=1, int R=len)
{
    if(ql <= L && R <= qr)
    {
        settag[o] = val;
        idata[o] = val;
        return ;
    }
    int M = L + R >> 1;
    pd(o, R - L + 1);
    if(ql <= M)
        SET(o<<1, L, M);
    if(M < qr)
        SET(o<<1|1, M+1, R);
    idata[o] = idata[o<<1] == idata[o<<1|1] ? idata[o<<1] : 0;
}
int query(int o=1, int L=1, int R=len)
{
    if(L == R)
        return idata[o];
    else if(L <= wz && wz <= R && idata[o])
        return idata[o];
    else
    {
        int M = L + R >> 1;
        pd(o, R - L + 1);
        if(wz <= M)
            return query(o<<1, L, M);
        else
            return query(o<<1|1, M+1, R);
    }
}
int main(void)
{
    int kase, ans, x;
    scanf("%d", &kase);
    while(kase--)
    {
        scanf("%d", &n);
        n <<= 1;
        for(int i=0; i<n; ++i)
        {
            scanf("%d", op+i);
            if(i&1)
                ++op[i];
            pos[i] = i;
        }
        sort(pos, pos+n, cmp);
        np[pos[0]] = 1;
        len = 1;
        for(int i=1; i<n; ++i)
            np[pos[i]] = op[pos[i]] == op[pos[i-1]] ? np[pos[i-1]] : ++len;
        len = np[pos[n-1]] - 1;
        memset(settag, 0, sizeof(settag));
        memset(idata, 0, sizeof(idata));
        for(int i=0; i<n; ++i)
        {
            ql = np[i];
            qr = np[++i] - 1;
            val = (i>>1) + 1;
            SET();
        }
        memset(vis, 0, sizeof(vis));
        vis[0] = true;
        ans = 0;
        for(int i=1; i<=len; ++i)
        {
            wz = i;
            x = query();
            if(!vis[x])
            {
                ++ans;
                vis[x] = true;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
