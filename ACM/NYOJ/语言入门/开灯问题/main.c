#include <stdio.h>
int main(void)
{
    int a[1001], n, k;
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; ++i)
        a[i] = 0;

    for(int i=1; i<=k; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            if(j%i == 0)
                a[j] = ~a[j];
        }
    }
    for(int i=1; i<=n; ++i)
    {
        if(a[i])
            printf("%d ", i);
    }
    printf("\n");
}
