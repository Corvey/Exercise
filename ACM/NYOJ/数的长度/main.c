#include <stdio.h>
#include <math.h>
#define pi 3.1415926536
#define E 2.71828182846
int main(void)
{
    int m;
    double n, ans;
    scanf("%d", &m);
    for(int i=0; i<m; ++i)
    {
        scanf("%lf", &n);
        ans = log10(2*pi*n)/2 + n * log10(n/E);
        printf("%d\n", (int)ans+1);
    }
}
