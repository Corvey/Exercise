#include <stdio.h>
int Fibonacci(int n,int a, int b)
{
    if(n<=2)
    {
        printf("%d\n", b);
        return 1;
    }
    else
        return Fibonacci(n-1, b, a+b);
}
int main(void)
{
    int n, x;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &x);
        Fibonacci(x, 1, 1);
    }
}
