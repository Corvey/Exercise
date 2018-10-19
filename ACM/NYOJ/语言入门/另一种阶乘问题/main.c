#include <stdio.h>
int qwe(int x)
{
    int ans, sum = 0;
    for(int i=1; i<=x; ++i)
    {
        ans = 1;
        for(int j=1; j<=i; ++j)
        {
            if(j&1)
            {
                ans *= j;
            }
        }
        sum += ans;
    }
    return sum;
}
int main(void)
{
    int n, x;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &x);
        printf("%d\n", qwe(x));
    }
}
