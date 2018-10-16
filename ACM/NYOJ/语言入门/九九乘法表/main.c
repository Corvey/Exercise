#include <stdio.h>
int main(void)
{
    int n, x;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &x);
        for(int j=1; j<=x; ++j)
        {
            for(int k=j; k<=9; ++k)
                printf("%d*%d=%d ", j, k, j*k);
            printf("\n");
        }
    }
}
