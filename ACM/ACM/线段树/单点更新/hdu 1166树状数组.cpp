#include <cstdio>
#include <string.h>
#define lowbit(x) (x&-x)
const int N = 5e4+10;
int isum[N], n;
inline void update(int t, int x){
    for(; t<=n; isum[t]+=x, t+=lowbit(t));
}
int Sum(int t)
{
    int ans = 0;
    for(; t; ans += isum[t], t-=lowbit(t));
    return ans;
}
int main(void)
{
    int m, kase, x, pos, l, r;
    char str[10];
    scanf("%d", &kase);
    for(int T=0; T<kase; )
    {
        memset(isum, 0, sizeof(isum));
        scanf("%d", &n);
        for(int i=1; i<=n; ++i)
        {
            scanf("%d", &x);
            update(i, x);
        }
        printf("Case %d:\n", ++T);
        while(1)
        {
            scanf("%s", str);
            if(str[0] == 'E')
                break;
            if(str[0] == 'A')
            {
                scanf("%d %d", &pos, &x);
                update(pos, x);
            }
            else if(str[0] == 'S')
            {
                scanf("%d %d", &pos, &x);
                update(pos, 0-x);
            }
            else
            {
                scanf("%d %d", &l, &r);
                printf("%d\n", Sum(r) - Sum(l-1));
            }
        }
    }
    return 0;
}