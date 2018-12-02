#include <stdio.h>
int a[100][100];
int abc(int n, int count, int ceng)
{
    for(int i=ceng; i<n-ceng; ++i)
        a[i][n-1-ceng] = count++;
    if(count-1 == n*n)
        return 1;
    for(int i=n-2-ceng; i>=ceng; --i)
        a[n-1-ceng][i] = count++;
    if(count-1 == n*n)
        return 1;
    for(int i=n-2-ceng; i>=ceng; --i)
        a[i][ceng] = count++;
    if(count-1 == n*n)
        return 1;
    for(int i=ceng+1; i<=n-2-ceng; ++i)
        a[ceng][i] = count++;
    if(count-1 == n*n)
        return 1;
    else
        return abc(n, count, ceng+1);
}
int main(void)
{
    int n;
    scanf("%d", &n);
    abc(n, 1, 0);
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}
