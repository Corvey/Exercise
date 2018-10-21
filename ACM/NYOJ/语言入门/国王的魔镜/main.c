#include <stdio.h>
#include <string.h>
int judge(char *s, int len)
{
    if(len&1)
        return 0;
    for(int i=0; i<len-1; ++i, --len)
    {
        if(s[i] != s[len-1])
            return 0;
    }
    return 1;
}
int main(void)
{
    int n, len;
    char s[101];
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        getchar();
        scanf("%s", s);
        len = strlen(s);
        while(judge(s, len))
        {
            len /= 2;
            memset(s+len, '\0', len*sizeof(char));
        }
        printf("%d\n", len);
    }
}
