#include <cstdio>
#include <string.h>
const int N = 1e5;
int a[N], c[N] = {0}, ans[N];
int main(void)
{
    int n, t, kase;
    scanf("%d", &kase);
    for(int T=0; T<kase; )
    {
        scanf("%d", &n);
        for(int i=1; i<=n; ++i)
        {
            scanf("%d", &t);
            a[i] = t;
            for(int j=t; j<=n; ++c[j], j+=j&-j);
            ans[t] = t;
            for(int j=t; j; ans[t]-=c[j], j-=j&-j);
            ans[t] = i >= t ? i+ans[t]-t : ans[t];
        }
        printf("Case #%d:", ++T);
        for(int i=1; i<=n; ++i)
            printf(" %d", ans[i]);
        putchar('\n');
        memset(c, 0, sizeof(c));
    }
}
