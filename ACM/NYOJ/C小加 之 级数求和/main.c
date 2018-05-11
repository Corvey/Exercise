#include <stdio.h>
int main(void)
{
    int n, k, i;
    double s;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &k);
        s = 0;
        for(i=0; s<k; )
            s += 1/(double)(++i);
        printf("%d\n", i);
    }
}
