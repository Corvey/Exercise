#include <stdio.h>
#include <string.h>
int b[1000000][2] = {0};
int main(void)
{
    int x, y, count=0;
    char a[8];
    for(int i=125; i<1000000; ++i)
    {
        b[i][0] = b[i-1][0];
        b[i][1] = b[i-1][1];
        sprintf(a, "%d", i);
        if( strchr(a, '5') && strchr(a, '2') && strchr(a, '1') )
        {
            if(strstr(a, "521"))
                ++b[i][0], ++b[i][1];
            else
                ++b[i][0];
        }
    }
    while(~scanf("%d %d", &x, &y))
        printf("Case %d:%d %d\n", ++count, b[y][0] - b[x-1][0], b[y][1] - b[x-1][1]);
}
