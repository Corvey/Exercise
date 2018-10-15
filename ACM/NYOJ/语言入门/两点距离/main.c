#include <stdio.h>
#include <math.h>
int main(void)
{
    int n;
    double a, b, x, y;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%lf%lf%lf%lf", &a, &b, &x, &y);
        a -= x;
        b -= y;
        printf("%.2lf\n", sqrt(a*a+b*b));
    }
}
