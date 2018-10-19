#include <stdio.h>
int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        if(n == 1 || n == 2)
            printf("Hrdv\n");
        else
            printf("Yougth\n");
    }
}
