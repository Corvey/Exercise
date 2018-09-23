#include <stdio.h>
int main(void)
{
    int n, m, k, a[50][50], b[50][50], c[50][50];
    while(1)
    {
        scanf("%d%d%d", &m, &n, &k);
        if(!m && !n && !k)
            break;
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                scanf("%d", &a[i][j]);
        for(int i=0; i<n; ++i)
            for(int j=0; j<k; ++j)
                scanf("%d", &b[i][j]);
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<k; ++j)
            {
                c[i][j] = 0;
                for(int x=0; x<n; ++x)
                    c[i][j] += a[i][x] * b[x][j];
            }
        }
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<k; ++j)
                printf("%d ", c[i][j]);
            printf("\n");
        }
    }
}
