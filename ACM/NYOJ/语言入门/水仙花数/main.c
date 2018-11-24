#include <stdio.h>
int main(void)
{
    int n, a, b, c;
    scanf("%d", &n);
    while(n)
    {
        a = n%10;
        b = n/10%10;
        c = n/100;
        if(n == a*a*a + b*b*b + c*c*c)
            printf("Yes\n");
        else
            printf("No\n");
        scanf("%d", &n);
    }
}
