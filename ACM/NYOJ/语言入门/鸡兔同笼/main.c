#include <stdio.h>
int main(void)
{
    int n, a, b, x, y;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d%d", &a, &b);
        for(x=0, y=a; 2*x+4*y != b && y >= 0; ++x, --y);
        if(y<0)
            printf("No answer\n");
        else
            printf("%d %d\n", x, y);
    }
}
