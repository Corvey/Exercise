#include <cstdio>
#include <string.h>
typedef long long int LL;
const LL MAX = 1e9 + 7;
const int fact[11] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
LL cnt[11][11], three[101];
int zuhe(int a, int b){
    return fact[b] / fact[a] / fact[b-a];
}
void init(void)
{
    three[0] = 1;
    for(int i=1; i<=100; ++i)
        three[i] = 3 * three[i-1] % MAX;
    memset(cnt, -1, sizeof(cnt));
    for(int i=0; i<=10; ++i)
    {
        cnt[i][0] = 0;
        cnt[1][i] = cnt[i][1] = 1 << i;
    }
    cnt[1][0] = 1;
    for(int n=2; n<=10; ++n)
    {
        for(int m=2; m<=n; ++m)
        {
            cnt[n][m] = three[n*m];
            for(int i=1; i<=n; ++i)
            {
                for(int j=0; j<=m; ++j)
                {
                    if(i==n && j==m)
                        break;
                    cnt[n][m] -= cnt[i][j] *  zuhe(i-1, n-1) % MAX * three[(n-i)*(m-j)] % MAX * zuhe(j, m) % MAX;
                }
            }
            for(; cnt[n][m]<0; cnt[n][m]+=MAX);
            cnt[m][n] = cnt[n][m];
        }
    }
}
int main(void)
{
    int n, m;
    init();
    while(~scanf("%d %d", &n, &m))
        printf("%lld\n", cnt[n][m]);
    return 0;
}
