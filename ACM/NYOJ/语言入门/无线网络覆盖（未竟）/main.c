#include <stdio.h>
#include <math.h>
int main(void)
{
    int n, l, d, r;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d%d%d", &l, &d, &r);
        if(4*r*r - d*d < 1)
            printf("impossible\n");
        else
        {
            double x = 2*sqrt(r*r - d*d/4);
            printf("%d\n", (int)(l/x+0.5));
        }
    }
}
