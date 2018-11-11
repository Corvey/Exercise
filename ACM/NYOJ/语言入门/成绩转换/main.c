#include <stdio.h>
int main(void)
{
    int n, x;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &x);
        switch (x/10)
        {
        case 10:
        case 9:
            printf("A\n");
            break;

        case 8:
            printf("B\n");
            break;

        case 7:
            printf("C\n");
            break;

        case 6:
            printf("D\n");
            break;

        default:
            printf("E\n");
            break;
        }

    }
}
