#include <stdio.h>
int main(void)
{
    int n, a[1000], t;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
        scanf("%d", a+i);
    for(int i=0; i<n-1; ++i)
        for(int j=0; j<n-1-i; ++j)
            if(a[j] > a[j+1])
                a[j] ^= a[j+1], a[j+1] ^= a[j], a[j] ^= a[j+1];
    t = 0;
    for(int i=0; i<n; ++i)
        if(a[i] != a[i+1])
            ++t;
    printf("%d\n", t);
    for(int i=0; i<n; ++i)
        if(a[i] != a[i+1])
            printf("%d ", a[i]);
    printf("\n");
}
