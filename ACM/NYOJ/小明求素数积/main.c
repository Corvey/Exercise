#include <stdio.h>
#include <math.h>
int judge(int x)
{
    if(x==1)
        return 0;
    int a = sqrt(x+1);
    for(int i=2; i<=a; ++i)
    {
        if(x%i == 0)
           return 0;
    }
    return 1;
}
int main(void)
{
    int t, n, x;
    scanf("%d", &t);
    for(int i=0; i<t; ++i)
    {
        scanf("%d", &n);
        x = 1;
        for(int j=2; j<=n; ++j)
        {
            if(judge(j))
                x = x%1000000 * j;
        }
        printf("%d\n", x%1000000);

    }
}
