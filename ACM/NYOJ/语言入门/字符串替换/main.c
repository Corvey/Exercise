#include <stdio.h>
#include <string.h>
int main(void)
{
    char s[1001];
    char *p, *t;
    while(gets(s))
    {
        t = s;
        p = s;
        while(t = strstr(p, "you"))
        {
            for(int i = (t-p)/sizeof(char); i>0; --i)
            {
                printf("%c", *p);
                ++p;
            }
            printf("we");
            p += 3;
        }
        for(; *p; ++p)
            printf("%c", *p);
        printf("\n");
    }
}
