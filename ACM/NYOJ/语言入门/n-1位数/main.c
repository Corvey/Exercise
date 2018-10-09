#include <stdio.h>
#include <math.h>
int main(void)
{
    int n, x, j;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &x);
        for(j=0; x/(int)pow(10, j+1) != 0; ++j);
        printf("%d\n", x%(int)pow(10, j));
    }
}
