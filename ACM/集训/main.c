#include <stdio.h>
#include <string.h>
#include <math.h>
#define INFINITY 0x3f3f3f3f
#define N 8
int a[8][2];
double side[N][N];
int main(void)
{
    int n, x, y;
    for(int i=1; ; ++i)
    {
        scanf("%d", &n);
        if(!n)
            break;
        for(int i=0; i<n; ++i)
        {
            scanf("%d %d", &a[i][0], &a[i][1]);
        }
        for(int i=0; i<n; ++i)
        {
            side[i][i] = INFINITY;
            for(int j=i+1; j<n; ++j)
            {
                x = a[i][0] - a[j][0];
                y = a[i][1] - a[j][1];
                side[i][j] = sqrt(x*x + y*y);
                side[j][i] = side[i][j];
            }
        }
        ///*
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                printf("%.2lf ", side[i][j]);
            }
            printf("\n");
        }
        //*/
    }
}
