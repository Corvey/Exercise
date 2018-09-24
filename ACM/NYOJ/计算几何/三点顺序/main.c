#include <stdio.h>
int main(void)
{
    int x1, y1, x2, y2, x3, y3;
    while(1)
    {
        scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
        if(!x1 && !y1 && !x2 && !y2 && !x3 && !y3)
            break;
        printf("%d\n", (x2-x1)*(y3-y1) - (x3-x1)*(y2-y1) > 0 ? 0 : 1);
    }
}
