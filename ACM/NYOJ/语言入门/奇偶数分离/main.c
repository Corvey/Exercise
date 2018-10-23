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
            if(j&1)
                printf("%d ", j);
        }
        printf("\n");
        for(int j=2; j<=x; ++j)
        {
            if(!(j&1))
                printf("%d ", j);
        }
        printf("\n");
    }
}
