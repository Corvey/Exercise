#include <stdio.h>
int main(void)
{
    double a[200], len, money;
    int n, l, c, p, q, t, b[50][2];
    while(~scanf("%d%d%d", &n, &l, &c))
    {
        for(int i=0; i<c; ++i)
            scanf("%lf", a+i);
        for(int i=0; i<c-1; ++i)
            for(int j=0; j<c-1-i; ++j)
                if(a[j] > a[j+1])
                    len = a[j], a[j] = a[j+1], a[j+1] = len;
        len = a[c-1] - a[0];
        len /= (double)n;
        q = 0;
        money = 0;
        for(t=0; q!=c; ++t)
        {
            p = q;
            for(q = p+1; a[q]-a[p]<len && q<c; ++q);
            money += a[q-1] - a[p] + 1;
            b[t][0] = p;
            b[t][1] = q-1;
        }
        if(t > n)
        {
            double min;
            int mintag;
            min = 10000007;
            while(t>n)
            {
                for(int i=0; i<t-1; ++i)
                {
                    if(min > a[ b[i+1][0] ] - a[ b[i][1] ])
                        min = a[ b[i+1][0] ] - a[ b[i][1] ], mintag = i;
                }
                --t;
                money += min - 1;
                b[mintag][1] = b[mintag+1][0];
            }
        }
        printf("%.0lf\n", money);
    }
}
