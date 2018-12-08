#include <stdio.h>
int main(void)
{
    int a, b, c, n;
    scanf("%d%d%d", &a, &b, &c);
    for(n=10; n<=100; ++n)
    {
        if(n%3==a && n%5==b && n%7==c)
            break;
    }
    if(n==101)
        printf("No answer\n");
    else
        printf("%d\n", n);
}
