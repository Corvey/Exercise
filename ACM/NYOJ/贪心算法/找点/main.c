#include <stdio.h>
int main(void)
{
    int a[100][2], n, temp, count;
    while(~scanf("%d", &n))
    {
        for(int i=0; i<n; ++i)
            scanf("%d%d", &a[i][0], &a[i][1]);
        for(int i=0; i<n-1; ++i)
        {
            for(int j=0; j<n-1-i; ++j)
            {
                if(a[j][1] > a[j+1][1])
                {
                    a[j][0] ^= a[j+1][0], a[j+1][0] ^= a[j][0], a[j][0] ^= a[j+1][0];
                    a[j][1] ^= a[j+1][1], a[j+1][1] ^= a[j][1], a[j][1] ^= a[j+1][1];
                }
            }
        }
        count = -1;
        for(int i=0; i<=n; ++count)
        {
            temp = a[i][1];
            for(++i; i<n && temp >= a[i][0]; ++i);
        }
        printf("%d\n", count);
        for(int i=0; i<n; ++i)
            a[i][0] = 0, a[i][1] = 0;
    }
}
