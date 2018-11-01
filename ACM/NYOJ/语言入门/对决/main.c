#include <stdio.h>
#include <math.h>
int main(void)
{
    double a, x, y;
    while(1)
    {
        scanf("%lf%lf", &x, &y);
        if(!x && !y)
            break;
        if(y < x-1 || 4*y > x*x)
            printf("NO\n");
        else
        {
            a = (x+sqrt(x*x-4*y))/2;
            if((int)a == a)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
}
