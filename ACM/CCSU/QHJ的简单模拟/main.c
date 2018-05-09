#include <stdio.h>
#include <string.h>
int main(void)
{
    char s[101];
    int len, sign, n, count;
    while(~scanf("%s", s))
    {
        getchar();
        if(s[0] == '-')
        {
            printf("($");
            for(len = 0; s[len] && s[len] != '.'; ++len);
            --len;
            n = len / 3;
            n *= 3;
            if(len == n)
            {
                count = 1;
                for(int i=1; i<len+1; ++i, ++count)
                {
                    if(count == 4)
                        printf(","), count = 1;
                    printf("%c", s[i]);
                }
            }
            else
            {
                int i;
                for(i=1; i<len+1-n; ++i)
                    printf("%c", s[i]);
                if(len>3)
                    printf(",");
                count = 1;
                for(; i<len+1; ++i, ++count)
                {
                    if(count == 4)
                        printf(","), count = 1;
                    printf("%c", s[i]);
                }
            }
            if(s[len+1] == '.')
            {
                int i;
                for(i=0; s[len+i+1] && (s[len+1+i]>='0'||s[len+1+i]<='9') && i<3; ++i)
                    printf("%c", s[len+i+1]);
                for(; i<3; ++i)
                    printf("0");
            }
            else
                printf(".00");
            printf(")\n");
        }
        else
        {
            for(len = 0; s[len] && s[len] != '.'; ++len);
            n = len / 3;
            n *= 3;
            printf("$");
            if(len == n)
            {
                count = 1;
                for(int i=0; i<len; ++i, ++count)
                {
                    if(count == 4)
                        printf(","), count = 1;
                    printf("%c", s[i]);
                }
            }
            else
            {
                int i;
                for(i=0; i<len-n; ++i)
                    printf("%c", s[i]);
                if(len>3)
                    printf(",");
                count = 1;
                for(; i<len; ++i, ++count)
                {
                    if(count == 4)
                        printf(","), count = 1;
                    printf("%c", s[i]);
                }
            }
            if(s[len] == '.')
            {
                int i;
                for(i=0; s[len+i] && (s[len+i]>='0'||s[len+i]<='9') && i<3; ++i)
                    printf("%c", s[len+i]);
                for(; i<3; ++i)
                    printf("0");
            }
            else
                printf(".00");
            printf("\n");
        }
    }
}
