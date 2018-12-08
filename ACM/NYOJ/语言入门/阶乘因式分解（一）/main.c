#include <stdio.h>
int main(void)
{
    int n, x, m, count, t;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d%d", &x, &m);
        count = 0;
        for(int j=x; j>1; --j)
        {
            t = j;
            while(!(t%m))
            {
                t /= m;
                ++count;
            }
        }
        printf("%d\n", count);
    }
}
