#include <stdio.h>
int main(void)
{
    int x1, x2, x3, y1, y2, y3;
    double s;
    while(1)
    {
        scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
        if(!x1 && !y1 && !x2 && !y2 && !x3 && !y3)
            break;
        s = (double)((x1*y2-x2*y1)+(x2*y3-x3*y2)+(x3*y1-x1*y3));
        s /= 2;
        if(s>0)
            printf("%.1lf\n", s);
        else
            printf("%.1lf\n", s*(-1));
    }
}
