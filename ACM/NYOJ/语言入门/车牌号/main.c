#include <stdio.h>
#include <string.h>
int main(void)
{
    int n, m;
    char s[100], min[100];
    scanf("%d", &n);
    getchar();
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &m);
        getchar();
        scanf("%s", min);
        for(int j=1; j<m; ++j)
        {
            getchar();
            scanf("%s", s);
            if(strcmp(s, min) < 0)
                strcpy(min, s);
        }
        printf("%s\n", min);
    }
}
