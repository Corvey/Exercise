#include <stdio.h>
int qwe(int y, int m, int d)
{
    int sum = d;
    switch(m-1)
    {
    case 11:
        sum += 30;
    case 10:
        sum += 31;
    case 9:
        sum += 30;
    case 8:
        sum += 31;
    case 7:
        sum += 31;
    case 6:
        sum += 30;
    case 5:
        sum += 31;
    case 4:
        sum += 30;
    case 3:
        sum += 31;
    case 2:
        if(y%4 == 0 && y%100 != 0 || y%400 == 0)
            sum += 29;
        else
            sum += 28;
    case 1:
        sum += 31;
        break;
    default:
        break;
    }
    return sum;
}
int main(void)
{
    int n, y, m, d;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d%d%d", &y, &m, &d);
        printf("%d\n", qwe(y, m, d));
    }
}
