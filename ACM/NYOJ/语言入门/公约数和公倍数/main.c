#include <stdio.h>
int main(void)
{
    int n, a, b;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d%d", &a, &b);
        int x;
        for(x=a>b?a:b; a%x || b%x; --x);
        printf("%d %d\n", x, a*b/x);
    }
}
