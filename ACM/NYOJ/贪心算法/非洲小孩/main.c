#include <stdio.h>
int main(void)
{
    int a[100][2], n, temp, count;
    while(~scanf("%d", &n))
    {
        for(int i=0; i<n; ++i)
        {
            a[i][0] = 0;
            a[i][1] = 0;
            scanf("%d", &temp);
            a[i][0] += temp*100;
            getchar();
            scanf("%d", &temp);
            a[i][0] += temp;
            getchar();
            scanf("%d", &temp);
            a[i][1] += temp*100;
            getchar();
            scanf("%d", &temp);
            a[i][1] += temp;
            if(a[i][0] > a[i][1])
                a[i][0] ^= a[i][1], a[i][1] ^= a[i][0], a[i][0] ^= a[i][1];
        }
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
        count = 0;
        for(int i=0; i<n; ++count)
            for(temp = a[i][1], ++i; i<n && temp >= a[i][0]; ++i);
        printf("%d\n", count);
    }
}
