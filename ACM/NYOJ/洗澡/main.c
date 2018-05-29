#include <stdio.h>
#include <string.h>
int main(void)
{
    char s[6];
    int n, a[50001], max=1, t;
    a[1] = 1;
    while(~scanf("%d", &n))
    {
        if(n > max)
        {
            t = a[max];
            for(int i=max+1; i<=n; ++i)
            {
                sprintf(s, "%d", i);
                if(!strchr(s, '4'))
                    ++t;
                a[i] = t;
            }
            max = n;
        }
        printf("%d\n", a[n]);
    }
}
