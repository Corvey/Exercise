#include <stdio.h>
int main(void)
{
    int n, h, t;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &h);
        h -= 10;
        if(h<=0)
            printf("1\n");
        else
        {
            t = h/5 + 1;
            printf("%d\n", t+(h%5>0));
        }

    }
}
