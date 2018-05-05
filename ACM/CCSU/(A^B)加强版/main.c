#include <stdio.h>
#include <math.h>
#define x 1000000007
double qwe(double a, double b, double c)
{
    if(b <= 1)
        return fmod(a*c, x);
    else if(fmod(b, 2))
        return qwe(fmod(a*a, x), (b-1)/2, fmod(a*c, x));
    else
        return qwe(fmod(a*a, x), b/2, c);
}
int main(void)
{
    double a, b;
    while(~scanf("%lf%lf", &a, &b))
        printf("%.0lf\n", qwe(fmod(a, x), b, 1));
    return 0;
}
