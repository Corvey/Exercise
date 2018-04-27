#include <cstdio>
#include <string.h>
#include <algorithm>
#define mset(a, b) memset(a, b, sizeof(a))
#define lowbit(x) (x&-x)
typedef long long int LL;
using namespace std;
const int N = 1e5+100;
int n, a[N], pos[N], b[N], c[N];
inline void Add(int t){
    for(; t<=n; ++c[t], t+=lowbit(t));
}
inline int Sum(int t){
    int sum = 0;
    for(; t; sum+=c[t], t-=lowbit(t));
    return sum;
}
bool cmp(const int x, const int y){
    return a[x] < a[y];
}
int main(void)
{
    LL ans;
    while(~scanf("%d", &n))
    {
        for(int i=0; i<n; ++i)
        {
            scanf("%d", a+i);
            pos[i] = i;
        }
        sort(pos, pos+n, cmp);
        b[pos[0]+1] = 1;
        for(int i=1; i<n; ++i)
            b[pos[i]+1] = a[pos[i]] == a[pos[i-1]] ? b[pos[i-1]+1] : i+1;
        mset(c, 0);
        ans = 0;
        for(int i=1; i<=n; ++i)
        {
            Add(b[i]);
            ans += i - Sum(b[i]);
        }
        printf("%lld\n", ans);
    }
}
