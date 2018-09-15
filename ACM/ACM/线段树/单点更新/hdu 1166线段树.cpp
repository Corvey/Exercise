#include <cstdio>
#include <string.h>
const int N = 1 << 17, INF = 0x3f3f3f3f;
int isum[N], pos, data, ql, qr;
void update(int now, int L, int R)
{
    int mid = L + R >> 1;
    if(L == R)
        isum[now] += data;
    else
    {
        if(pos <= mid)
            update(now<<1, L, mid);
        else
            update(now<<1|1, mid+1, R);
        isum[now] = isum[now<<1] + isum[now<<1|1];
    }
}
int query(int now, int L, int R)
{
    int mid = L + R >> 1, ans = 0;
    if(ql <= L && R <= qr)
        return isum[now];
    if(ql <= mid)
        ans += query(now<<1, L, mid);
    if(mid < qr)
        ans += query(now<<1|1, mid+1, R);
    return ans;
}
int main(void)
{
    int n, m, kase;
    char str[10];
    scanf("%d", &kase);
    for(int T=0; T<kase; )
    {
        memset(isum, 0, sizeof(isum));
        scanf("%d", &n);
        for(int i=1; i<=n; ++i)
        {
            scanf("%d", &data);
            pos = i;
            update(1, 1, n);
        }
        printf("Case %d:\n", ++T);
        while(1)
        {
            scanf("%s", str);
            if(str[0] == 'E')
                break;
            switch (str[0])
            {
            case 'A':
            case 'S':
                scanf("%d %d", &pos, &data);
                if(str[0] == 'S')
                    data = 0 - data;
                update(1, 1, n);
                break;
            case 'Q':
                scanf("%d %d", &ql, &qr);
                printf("%d\n", query(1, 1, n));
                break;
            }
        }
    }
}