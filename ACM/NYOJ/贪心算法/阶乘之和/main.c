#include <stdio.h>
int Factorial(int n, int a)
{
    n==1 ? a : Factorial(n-1, a*n);
}
int main(void)
{
    int a[10], m, n;
    for(int i=1; i<10; ++i)
        a[i] = Factorial(10-i, 1);
    scanf("%d", &m);
    for(int i=0; i<m; ++i)
    {
        scanf("%d", &n);
        for(int i=1; i<10; ++i)
        {
            if(n < a[i])
                continue;
            else
                n -= a[i];
        }
        if(!n)
            printf("Yes\n");
        else
            printf("No\n");
    }
}
