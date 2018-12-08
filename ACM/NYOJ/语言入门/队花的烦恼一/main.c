#include <stdio.h>
int qwe(int x)
{
    if(x)
    {
        qwe(x / 2);
        printf("%d", x % 2);
    }
}
int main(void)
{
    int x;
    while(scanf("%d", &x)!=EOF)
    {
        if(!x)
            printf("0");
        else
            qwe(x);
        printf("\n");
    }
}
