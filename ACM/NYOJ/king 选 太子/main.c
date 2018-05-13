#include <stdio.h>
int main(void)
{
    int a[15], n, m;
    scanf("%d", &m);
    while(m--)
    {
        scanf("%d", &n);
        for(int i=0; i<n; ++i)
            scanf("%d", a+i);
        for(int i=0; i<n-1; ++i)
            for(int j=0; j<n-1-i; ++j)
                if(a[j] > a[j+1])
                    a[j] ^= a[j+1], a[j+1] ^= a[j], a[j] ^= a[j+1];
        if(n&1)
            printf("%d\n", a[(n-1)/2]);
        else
            printf("%d\n", a[(n-1)/2+1]);
    }
}
