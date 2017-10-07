#include <stdio.h>
#define MAXN 100//最大物品数量
#define MAXW 100//最大背包负重
int main(void)
{
    int n, maxweight, weight[MAXN+1], value[MAXN+1], tab[MAXN+1][MAXW+1] = {0};
    while(~scanf("%d %d", &n, &maxweight))
    {
        for(int i=1; i<=n; ++i)
            scanf("%d %d", weight+i, value+i);
        for(int i=1; i<=n; ++i)
        {
            for(int j=0; j<=maxweight; ++j)
            {
                if(j < weight[i])
                    tab[i][j] = tab[i-1][j];
                else
                {
                    int t = value[i] + tab[i-1][ j - weight[i] ];
                    tab[i][j] = tab[i-1][j] > t ? tab[i-1][j] : t;
                }
            }
        }
        for(int i=0; i<=n; ++i)
        {
            for(int j=0; j<=maxweight; ++j)
            {
                printf("%3d ", tab[i][j]);
            }
            printf("\n");
        }
        int max = 0;
        for(int i=1; i<=n; ++i)
            max = tab[i][maxweight] > max ? tab[i][maxweight] : max;
        printf("%d\n", max);
    }
}
