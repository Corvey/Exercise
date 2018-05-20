#include <stdio.h>
int main(void)
{
    int n, a[7][2], max, maxtag;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        max = 0;
        maxtag = 0;
        for(int j=0; j<7; ++j)
        {
            scanf("%d%d", &a[j][0], &a[j][1]);
            if(max < a[j][0] + a[j][1])
                max = a[j][0] + a[j][1], maxtag = j;
        }
        if(max > 8)
            printf("%d\n", maxtag+1);
        else
            printf("0\n");
    }
}
