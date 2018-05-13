#include <stdio.h>
int main(void)
{
    int t, n, a[100], b[100], as, bs;
    scanf("%d", &t);
    for(int i=0; i<t; ++i)
    {
        scanf("%d", &n);
        for(int j=0; j<n; ++j)
            scanf("%d", a+j);
        for(int j=0; j<n; ++j)
            scanf("%d", b+j);
        for(int j=0; j<n-1; ++j)
            for(int k=0; k<n-1-j; ++k)
                if(a[k] > a[k+1])
                    a[k] ^= a[k+1], a[k+1] ^= a[k], a[k] ^= a[k+1];
        for(int j=0; j<n-1; ++j)
            for(int k=0; k<n-1-j; ++k)
                if(b[k] > b[k+1])
                    b[k] ^= b[k+1], b[k+1] ^= b[k], b[k] ^= b[k+1];
        as = bs = 0;
        for(int j=0; j<n; ++j)
        {
            if(a[j] != b[j])
            {
                as += a[j]>b[j] ? 2 : 0;
                bs += a[j]>b[j] ? 0 : 2;
            }
        }
        if(as == bs)
            printf("none\n");
        else if(as > bs)
            printf("X\n");
        else
            printf("Y\n");
    }
}
