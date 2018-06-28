#include <cstdio>
#include <string.h>
const int N = 1e5+10, M = 5010;
int cntS[30], cntP[30];
char s[N] = {0}, p[M] = {0};
bool judge(int t, int m)
{
    int i;
    for(i=0; i<m-1; ++i)
    {
        if(s[t+i] != p[i])
        {
            if(s[t+i+1] == p[i] && s[t+i] == p[i+1])
            {
                ++i;
                continue;
            }
            else
                return false;
        }
    }
    return true;
}
int main(void)
{
    int t, n, m;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        scanf("%s", s);
        scanf("%s", p);
        for(int i=0; i<m; ++i)
        {
            ++cntS[ s[i] - 'a' ];
            ++cntP[ p[i] - 'a' ];
        }
        putchar(judge(0, m) ? '1' : '0');
        for(int i=1, t=n-m+1; i<t; ++i)
        {
            --cntS[ s[i-1] - 'a' ];
            ++cntS[ s[i+m-1] - 'a' ];
            putchar( memcmp(cntS, cntP, sizeof(cntS)) || !judge(i, m) ? '0' : '1' );
        }
        for(int i=n-m+1; i<n; ++i)
            putchar('0');
        putchar('\n');
        memset(cntS, 0, sizeof(cntS));
        memset(cntP, 0, sizeof(cntP));
    }
}
