#include <stdio.h>
int main(void)
{
    int n, x, y;
    char c;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%x%c%x", &x, &c, &y);
        if(c == '+')
            printf("%o\n", x+y);
        else
            printf("%o\n", x-y);
    }
}
