#include <stdio.h>
#include <math.h>
int main(void)
{
    int n, m, count;
    double r[600], length;
    scanf("%d", &m);
    for(int i=0; i<m; ++i)
    {
        scanf("%d", &n);
        for(int j=0; j<n; ++j)
            scanf("%lf", r+j);
        for(int j=0; j<n-1; ++j)
            for(int k=0; k<n-1-j; ++k)
                if(r[k] < r[k+1])
                    length = r[k] , r[k] = r[k+1], r[k+1] = length;
        length = 20;
        count = 0;
        for(int j=0; length>0; ++j)
        {
            if(r[j] <= 1)
                continue;
            length -= 2 * sqrt(r[j] * r[j] - 1);
            ++count;
        }
        printf("%d\n", count);
    }
}
