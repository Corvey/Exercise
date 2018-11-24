#include <stdio.h>
int main(void)
{
    int n;
    char x, y;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        getchar();
        scanf("%c %c", &x, &y);
        if(x == y)
            printf("%c=%c\n", x, y);
        else if(x<y)
            printf("%c>%c\n", x, y);
        else if(x>y)
            printf("%c<%c\n", x, y);
    }
}
