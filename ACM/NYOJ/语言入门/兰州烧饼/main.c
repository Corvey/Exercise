#include <stdio.h>
int main(void)
{
    int n, x;
    while(~scanf("%d%d", &n, &x))
        printf("%d\n", n>=x? n*2/x+(n*2%x>0) : 2);
}
