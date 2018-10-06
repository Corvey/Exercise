#include <stdio.h>
int main(void)
{
    int n, m, a[100], x, count, temp;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &m);
        count = 0;
        for(int j=0; j<m; ++j)
        {
            scanf("%d", &x);
            int k=0;
            for(; k<count; ++k)
                if(a[k] == x)
                    break;
            if(k==count)
            {
                a[k] = x;
                ++count;
            }
        }
        for(int j=0; j<count-1; ++j)
            for(int k=0; k<count-j-1; ++k)
                if(a[k] > a[k+1])
                    temp = a[k], a[k] = a[k+1], a[k+1] = temp;
        printf("%d\n", count);
        for(int j=0; j<count; ++j)
            printf("%d ", a[j]);
        printf("\n");
    }
}
