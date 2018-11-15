#include <stdio.h>
int main(void)
{
    int n, x;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &x);
        while(x)
        {
            switch (x%10)
            {
            case 0:
            case 1:
                printf("O");
                break;
            case 2:
            case 3:
                printf("T");
                break;
            case 4:
            case 5:
                printf("F");
                break;
            case 6:
            case 7:
                printf("S");
                break;
            case 8:
                printf("E");
                break;
            case 9:
                printf("N");
                break;
            default:
                break;
            }
            x /= 10;
        }
        printf("\n");
    }
}
