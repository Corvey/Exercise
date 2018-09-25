#include <stdio.h>
int main(void)
{
    int x, min, max;
    scanf("%d", &x);
    max = min = x;
    for(int i=1; i<5; ++i)
    {
        scanf("%d", &x);
        if(x>max)
            max = x;
        if(x<min)
            min = x;
    }
    printf("%d %d", min, max);
}
