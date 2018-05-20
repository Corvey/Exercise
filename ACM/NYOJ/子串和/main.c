#include <stdio.h>
int a[1000010], b[1000010];
int main(void)
{
    int n, m, max, x, y, j;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &m);
        for(j=0; j<m; ++j)
            scanf("%d", a+j);
        for(j=0; a[j]<=0 && j<m; ++j);
        b[j] = a[j];
        max = a[j];
        x = j;
        //printf("j:%d\n", j);
        for(++j; j<m; ++j)
        {
            b[j] = b[j-1] + a[j];
            if(max <= b[j])
            {
                max = b[j];
                x = j;
            }
        }
        //for(j=m-1; a[j]<=0 && j>=0; --j);
        j = m-1;
        max = a[j];
        y = j;
        //printf("j:%d\n", j);
        for(--j; j>=0; --j)
        {
            a[j] += a[j+1];
            if(max <= a[j])
            {
                max = a[j];
                y = j;
            }
        }
        ///*
        for(j=0; j<m; ++j)
        {
            printf("%d ", b[j]);
        }
        printf("\n");
        for(j=0; j<m; ++j)
        {
            printf("%d ", a[j]);
        }
        printf("\n");
        //*/
        if(x==n)
            printf("%d\n", max);
        else
            printf("%d\n", max - a[x+1]);
    }
}
