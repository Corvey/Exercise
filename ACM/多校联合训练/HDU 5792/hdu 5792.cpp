#include <cstdio>
#include <string.h>
#include <algorithm>
#define lowbit(x) (x&-x)
typedef long long int LL;
using namespace std;
const int N = 5e4+100;
int n, val[N], pos[N], a[N], c1[N], c2[N], rg[N], lg[N], rs[N], ls[N];
bool cmp(const int x, const int y){
    return val[x] < val[y];
}
void Add(int *p, int t){
    for(int i=t; i<=n; ++p[i], i+=lowbit(i));
}
int Sum(int *p, int t){
    int sum = 0;
    for(; t; sum+=p[t], t-=lowbit(t));
    return sum;
}
int main(void)
{
    int t, allrg, allrs;
    LL ans;
    while(~scanf("%d", &n))
    {
        for(int i=0; i<n; ++i)
        {
            scanf("%d", val+i);
            pos[i] = i;
        }
        sort(pos, pos+n, cmp);
        a[pos[0]+1] = 1;
        for(int i=1; i<n; ++i)
        {
            if(val[pos[i]] == val[pos[i-1]])
                a[pos[i]+1] = a[pos[i-1]+1];
            else
                a[pos[i]+1] = i+1;
        }
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));
        allrg = allrs = 0;
        for(int i=1; i<=n; ++i)
        {
            t = a[i];
            Add(c1, t);
            lg[i] = i - Sum(c1, t);
            ls[i] = Sum(c1, t-1);
            t = a[n+1-i];
            Add(c2, t);
            rg[n+1-i] = i - Sum(c2, t);
            rs[n+1-i] = Sum(c2, t-1);
            allrg += rg[n+1-i];
            allrs += rs[n+1-i];
        }
        ans = (LL)allrg * allrs;
        for(int i=1; i<=n; ++i)
            ans -= rg[i] * rs[i] + rg[i] * lg[i] + ls[i] * rs[i] + ls[i] * lg[i];
        printf("%lld\n", ans);
    }
}
