#include <stdio.h>
#include <string.h>
int main(void)
{
    char s[120];
    int n, x, len, t, pre;
    scanf("%d", &n);
    getchar();
    for(int i=0; i<n; ++i)
    {
        scanf("%s", s);
        getchar();
        scanf("%d", &x);
        getchar();
        len = strlen(s);
        pre = 0;
        for(int j=0; j<len-x; ++j)
        {
            for(int k=9; k>=0; --k)
            {
                for(t=pre; t<len && s[t]!='0'+k; ++t);
                if( t != len )
                {
                    if( t == x+j )
                    {
                        for(; t<len; ++t)
                            printf("%c", s[t]);
                        pre = t;
                        break;
                    }
                    else if( t < x+j )
                    {
                        printf("%c", s[t]);
                        pre = t+1;
                        break;
                    }
                }
            }
        }
        printf("\n");
    }
}
