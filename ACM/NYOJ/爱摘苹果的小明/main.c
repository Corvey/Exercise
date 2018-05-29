#include <stdio.h>
int main(void)
{
    int n, a[10], h, t;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<10; ++j)
            scanf("%d", a+j);
        scanf("%d", &h);
        h += 30;
        t = 0;
        for(int j=0; j<10; ++j)
            if(h >= a[j])
                ++t;
        printf("%d\n", t);
    }
}
