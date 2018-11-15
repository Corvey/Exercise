#include <stdio.h>
int main(void)
{
    int n, x, sum, last;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &x);
        sum = 1;
        last = 1;
        for(int j=2; j<=x; ++j)
        {
            sum += last + j;
            last += j;
        }
        printf("%d\n", sum);
    }
}
