#include <stdio.h>
#include <math.h>
int judge(int x)
{
    if(x<=1)
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
    int a[123], n, min, max;
    char s[101], *p;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        for(int j=97; j<123; ++j)
            a[j] = 0;
        getchar();
        scanf("%s", s);
        p = s;
        for(int j=0; s[j]; ++j)
            ++a[(int)s[j]];
        max = 0;
        min = 101;
        for(int j=97; j<123; ++j)
        {
            if(a[j] > max)
                max = a[j];
            if(a[j] && a[j] < min)
                min = a[j];
        }
        if(judge(max-min))
            printf("Lucky Word\n%d\n", max-min);
        else
            printf("No Answer\n0\n");
    }
}
