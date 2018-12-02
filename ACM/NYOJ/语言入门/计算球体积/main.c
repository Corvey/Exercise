#include <stdio.h>
#define pi 3.1415926
int main(void)
{
    double r;
    while(scanf("%lf", &r) != EOF)
        printf("%d\n", (int)(pi*r*r*r*4/3+0.5));
}
