#include <stdio.h>
#include <math.h>
#define pi 3.1415926
int main(void)
{
    int n;
    double x, r;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%lf", &x);
        r = x/sqrt(3);
        printf("%.2lf\n", r*r*pi);
    }
}
