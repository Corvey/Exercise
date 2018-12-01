#include <stdio.h>
#include <math.h>
int judge(int x)
{
    if(x<=2)
        return 1;
    int n = (int)sqrt(x+1);
    for(int i=2; i<n; ++i)
    {
        if(x%i==0)
            return 0;
    }
    return 1;
}
int main(void)
{
    int n, m, x, sum;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &m);
        sum = 0;
        for(int j=0; j<m; ++j)
        {
            scanf("%d", &x);
            if(judge(x))
                sum += x;
        }
        printf("%d\n", sum);
    }
}
