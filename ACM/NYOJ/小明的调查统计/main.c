#include <stdio.h>
int main(void)
{
    int t, n, a[100];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i=0; i<n; ++i)
            scanf("%d", a+i);
        for(int i=0; i<n-1; ++i)
            for(int j=0; j<n-1-i; ++j)
                if(a[j] > a[j+1])
                    a[j] ^= a[j+1], a[j+1] ^= a[j], a[j] ^= a[j+1];
        printf("%d\n", a[n-1] - a[0]);
    }
}
