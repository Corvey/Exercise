#include <stdio.h>
int main(void)
{
    int a[1001], n, m, x, count, out;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d%d", &m, &x);
        for(int j=1; j<=m; ++j)
            a[j] = 0;
        count = out = 0;
        for(int j=1; out<m-1; ++j)
        {
            j %= m+1;
            if(a[j])
                continue;
            ++count;
            if(count==x)
            {
                count = 0;
                a[j] = 1;
                ++out;
            }
        }
        for(int j=1; j<=m; ++j)
        {
            if(!a[j])
            {
                printf("%d\n", j);
                break;
            }
        }
    }
}
