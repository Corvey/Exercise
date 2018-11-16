#include <stdio.h>
int main(void)
{
    int n, x;
    while(scanf("%d%d", &n, &x) != EOF)
    {
        printf("%d\n", n/x);
    }
}
