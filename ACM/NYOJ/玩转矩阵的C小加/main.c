#include <stdio.h>
int main(void)
{
    int a[3][3], n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<3; ++j)
            for(int k=0; k<3; ++k)
                scanf("%d", &a[j][k]);
        for(int j=0; j<3; ++j)
        {
            for(int k=0; k<3; ++k)
                printf("%d ", a[k][j]);
            printf("\n");
        }
    }
}
