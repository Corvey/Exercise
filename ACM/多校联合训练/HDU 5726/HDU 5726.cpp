#include <cstdio>
#include <string.h>
#include <map>
using namespace std;
typedef long long int LL;
const int N = 1 << 18;
int igcd[N], M, val, ql, qr, qval[100100];
map<int, LL> cnt;
map<int, LL>::iterator iter;
int gcd(int a, int b){
    return b ? gcd(b, a%b) : a;
}
inline int read(void)
{
    static int ans;
    static char ch;
    for(ch = getchar(); ch < '0' || ch > '9'; ch =getchar());
    for(ans = 0; ch >= '0' && ch <= '9'; ch = getchar())
        ans = ans * 10 + ch - '0';
    return ans;
}
inline void bulid(int n)
{
    for(M=1; M<n+2; M<<=1);
    for(int i=M+1; i<=n+M; ++i)
        igcd[i] = read();
    for(int i=M-1; i; --i)
        igcd[i] = gcd(igcd[i<<1], igcd[i<<1|1]);
}
inline int query(int L=ql, int R=qr)
{
    static int ans;
    if(L == R)
        return igcd[L+M];
    L += M - 1, R += M + 1;
    for(ans=0; L^R^1; L >>= 1, R >>= 1)
    {
        if(~L&1)
            ans = gcd(igcd[L^1], ans);
        if(R&1)
            ans = gcd(igcd[R^1], ans);
    }
    return ans;
}
inline int half(int L, int R)
{
    static int M;
    static int ans;
    while(L < R)
    {
        M = L + R + 1 >> 1;
        qr = M;
        ans = query();
        if(ans == val)  L = M;
        else if(ans > val)  L = M;
        else    R = M - 1;
    }
    return R;
}
void work(int n)
{
    static int L, R, t;
    for(L=1; L<=n; ++L)
    {
        ql = L;
        for(R=L; R<=n; ++R)
        {
            qr = R;
            val = query();
            t = half(R, n);
            iter = cnt.find(val);
            if(iter != cnt.end())
                iter->second += t - R + 1;
            R = t;
        }
    }
}
int main(void)
{
    int kase, n, q;
    scanf("%d", &kase);
    for(int T=0; T<kase; )
    {
        memset(igcd, 0, sizeof(igcd));
        scanf("%d", &n);
        bulid(n);
        scanf("%d", &q);
        for(int i=0; i<q; ++i)
        {
            ql = read();
            qr = read();
            val = query();
            qval[i] = val;
            if(cnt.find(val) == cnt.end())
                cnt[val] = 0;
        }
        work(n);
        printf("Case #%d:\n", ++T);
        for(int i=0; i<q; ++i)
        {
            val = qval[i];
            printf("%d %lld\n", val, cnt[val]);
        }
        cnt.clear();
    }
    return 0;
}
