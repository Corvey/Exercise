#include <stdio.h>
int main(void)
{
    int n, j, t;
    double x, count;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%lf", &x);
        if(x==1)
            printf("471\n");
        else
            printf("%.0lf471\n", x-1);
    }
}
