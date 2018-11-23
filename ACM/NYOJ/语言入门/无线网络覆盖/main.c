#include <stdio.h>
#include <math.h>
int main(void)
{
    int n;
    double l, d, r, x, t;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%lf%lf%lf", &l, &d, &r);
        x = 2 * sqrt(r*r - d*d/4);
        if(x < 1 || d >= 2*r )
            printf("impossible\n");
        else
        {
            t = l/x;
            if(t == (int)t)
                printf("%.0lf\n", t);
            else
            {
                if(l/(t+1) < 1)
                    printf("impossible\n");
                else
                    printf("%d\n", (int)(t+1));
            }
        }
    }
}
