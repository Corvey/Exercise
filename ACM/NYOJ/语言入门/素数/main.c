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
    int n, x, ld, rd;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &x);
        for(rd=x; !judge(rd); ++rd);
        for(ld=x; !judge(ld); --ld);
        if(rd-x <= x-ld)
            printf("%d\n", rd);
        else
            printf("%d\n", ld);
    }
}
