#include <stdio.h>
int main(void)
{
    int n, m, l, d, code, maxl, mind, maxcode;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &m);
        scanf("%d%d%d", &maxl, &mind, &maxcode);
        for(int j=1; j<m; ++j)
        {
            scanf("%d%d%d", &l, &d, &code);
            if(l > maxl)
            {
                maxl = l;
                mind = d;
                maxcode = code;
            }
            else if(l == maxl)
            {
                if(d < mind)
                {
                    maxl = l;
                    mind = d;
                    maxcode = code;
                }
                else if(d == mind)
                {
                    if(code > maxcode)
                    {
                        maxl = l;
                        mind = d;
                        maxcode = code;
                    }
                }
            }
        }
        printf("%d\n", maxcode);
    }
}
