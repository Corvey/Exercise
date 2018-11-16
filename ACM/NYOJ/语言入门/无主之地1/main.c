#include <stdio.h>
int main(void)
{
    int m[100][2], x, n, j;
    for(int i=0; i<100; ++i)
    {
        m[i][0] = 0;
        m[i][1] = 0;
    }

    for(int i=0; ; ++i)
    {
        scanf("%d%d", &x, &n);
        if(x && n)
        {
            for(j=0; j<i; ++j)
            {
                if(m[j][0] == x)
                {
                    m[j][1] += n;
                    break;
                }
            }
            if(j == i)
            {
                m[i][0] = x;
                m[i][1] = n;
            }

        }
        else
            break;
    }

    for(int i=0; i<100; ++i)
    {
        if(m[i][0])
            printf("%d %d\n", m[i][0], m[i][1]);
    }
}
