#include <stdio.h>
int qwe(int m, int num)
{
    if(m == 0)
        return num;
    else
        qwe(m-1, (num+1)*2);
}
int main(void)
{
    int n, m;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &m);
        printf("%d\n", qwe(m, 1));
    }
}
