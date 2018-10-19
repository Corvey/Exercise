#include <stdio.h>
int main(void)
{
    int n, x, max, temp;
    while(scanf("%d", &n) != EOF)
    {
        max = 0;
        for(int i=1; i<=n/3; ++i)
        {
            if(i&1)
            {
                temp = 0;
                for(int j=0; j<3; ++j)
                {
                    scanf("%d", &x);
                    if(x > temp)
                        temp = x;
                }
            }
            else
            {
                temp = 65535;
                for(int j=0; j<3; ++j)
                {
                    scanf("%d", &x);
                    if(x < temp)
                        temp = x;
                }
            }
            if(temp > max)
                max = temp;
        }
        printf("%d\n", max);
    }
}
