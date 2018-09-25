#include <stdio.h>
int main(void)
{
    int n, x, count;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &x);
        count = 0;
        for(int j=0; (1<<j) <= x; ++j)
        {
            if( (x&(1<<j)) == 1<<j )
                ++count;
        }
        printf("%d\n", count);
    }
}
