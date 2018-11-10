#include <stdio.h>
int main(void)
{
    int m, n, count, t;
    while(1)
    {
        scanf("%d%d", &m, &n);
        if(!m && !n)
            break;
        count = 0;
        t = m%10 + n%10;
        if(t>9)
            ++count;
        t = m/10%10 + n/10%10 + t/10;
        if(t>9)
            ++count;
        t = m/100 + n/100 + t/10;
        if(t>9)
            ++count;
        printf("%d\n", count);
    }
}
