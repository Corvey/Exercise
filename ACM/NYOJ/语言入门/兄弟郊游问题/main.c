#include <stdio.h>
int main(void)
{
    int n, m, x, y, z;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d%d%d%d", &m, &x, &y, &z);
        printf("%.2lf\n", (double)x*m/(y-x)*z);
    }
}
