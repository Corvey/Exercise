#include <stdio.h>
#include <string.h>
int main(void)
{
    int t, n, time, k;
    double sum;
    char s[5];
    scanf("%d", &t);
    for(int i=0; i<t; ++i)
    {
        scanf("%d", &n);
        k = 1;
        sum = 0;
        for(int j=0; j<n; ++j)
        {
            scanf("%s", s);
            if(!strcmp(s, "IN"))
                k *= 20;
            else if(!strcmp(s, "STAY"))
            {
                scanf("%d", &time);
                sum += (double)time/k;
            }
            else if(!strcmp(s, "OUT"))
                k /= 20;
        }
        printf("%.0lf\n", sum*60);
    }
}
