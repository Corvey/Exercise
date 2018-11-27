#include <stdio.h>
int main(void)
{
    double a, b;
    while(~scanf("%lf%lf", &a, &b))
        printf("%.0lf\n", a*b*(a+1)*(b+1)/4);
}
