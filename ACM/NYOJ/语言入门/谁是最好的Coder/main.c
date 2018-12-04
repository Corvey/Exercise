#include <stdio.h>
int main(void)
{
    int n, a, b, max;
    while(1)
    {
        scanf("%d", &n);
        if(!n)
            break;
        max=0;
        for(int i=0; i<n; ++i)
        {
            scanf("%d%d", &a, &b);
            if(a+b > max)
                max = a+b;
        }
        printf("%d\n", max);

    }
}
