#include <stdio.h>
#include <math.h>
int main(void)
{
    int n, x, a, b, count, temp;
    char t[5];
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%s", t);
        count = 0;
        while(1)
        {
            x = 0;
            for(int j = 0; j < 4; ++j)
                x += (t[j] - '0') * pow(10, 3 - j);
            for(int j = 0; j < 3; ++j)
                for(int k = 0; k < 3 - j; ++k)
                    if(t[k] < t[k + 1])
                        a = t[k], t[k] = t[k + 1], t[k + 1] = a;
            a = 0;
            for(int j = 0; j < 4; ++j)
                a += (t[j] - '0') * pow(10, 3 - j);
            b = 0;
            for(int j = 0; j < 4; ++j)
                b += (t[j] - '0') * pow(10, j);
            ++count;
            if(x == a-b)
                break;
            else
            {
                temp = a-b;
                for(int j=3; j>=0; --j, temp/=10)
                    t[j] = temp%10 + '0';
            }
        }
        printf("%d\n", count);
    }
}
