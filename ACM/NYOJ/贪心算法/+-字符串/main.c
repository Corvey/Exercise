#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    int n, i, j, t;
    char a[5001], b[5001];
    while(~scanf("%s", a))
    {
        getchar();
        scanf("%s", b);
        getchar();
        n = strlen(a);
        if(n != strlen(b))
        {
            printf("-1\n");
            memset(a, 0, sizeof(a));
            memset(b, 0, sizeof(b));
            continue;
        }
        t = 0;
        i = -1;
        j = -1;
        while(i!=n && j!=n)
        {
            for(++i; i<n && a[i] != '-'; ++i);
            for(++j; j<n && b[j] != '-'; ++j);
            t += abs(i-j);
        }
        if(i==j)
            printf("%d\n", t);
        else
            printf("-1\n");
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
    }
}
