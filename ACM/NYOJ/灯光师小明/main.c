#include <stdio.h>
#include <string.h>
int main(void)
{
    int n, t, a[100000] = {0}, x, open = 0;
    char s[7];
    scanf("%d%d\n", &n, &t);
    while(t--)
    {
        scanf("%s", s);
        if(!strcmp(s, "CHANGE"))
        {
            scanf("%d\n", &x);
            a[x-1] = !a[x-1];
            open += a[x-1]==0 ? -1 : 1;
        }
        else if(!strcmp(s, "QUERY"))
            printf("%d\n", open);
    }
}
