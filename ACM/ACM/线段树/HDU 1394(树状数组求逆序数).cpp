#include <cstdio>
#include <string.h>
#define lowbit(x) (x&-x)
#define small(a, b) (a < b ? a : b)
const int N = 5010;
int a[N], c[N], n;
inline void add(int t){
    for(; t<=n; ++c[t], t+=lowbit(t));
}
inline int sum(int t)
{
    static int ans;
    for(ans = 0; t; ans+=c[t], t-=lowbit(t));
    return ans;
}
int main(void)
{
    int x, nixu, ans;
    while(~scanf("%d", &n))
    {
        memset(c, 0, sizeof(c));
        nixu = 0;
        for(int i=1; i<=n; ++i)
        {
            scanf("%d", &x);
            a[i] = x;
            add(x+1);
            nixu += i - sum(x+1);
        }
        ans = nixu;
        for(int i=1; i<=n; ++i)
        {
            nixu += n - 1 - (a[i] << 1);
            ans = small(ans, nixu);
        }
        printf("%d\n", ans);
    }
    return 0;
}
