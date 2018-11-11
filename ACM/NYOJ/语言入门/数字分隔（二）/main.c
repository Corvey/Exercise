#include <stdio.h>
#include <string.h>

#define maxn 110
char buf[maxn];
int main()
{
    int sign, left, dot, i, len;
    char * ch;
    while(scanf("%s", buf + 1) != EOF)
    {
        sign = 0;
        buf[0] = '0';
        if(buf[1] == '-')
        {
            sign = 1;
            buf[1] = '0';
        }
        len = strlen(buf);
        if(ch = strchr(buf, '.'))
            dot = ch - buf;
        else
            dot = len;
        /*
        // 以下处理进位
        if(len - dot > 3)
        {
            if(buf[dot + 3] > '4')
            {
                if(++buf[dot + 2] > '9')
                {
                    buf[dot + 2] = '0';

                    if(++buf[dot + 1] > '9')
                    {
                        buf[dot + 1] = '0';
                        ++buf[dot - 1];
                    }
                }
                i = dot - 1;
                while(buf[i] > '9')
                {
                    buf[i--] = '0';
                    ++buf[i];
                }
            }
            buf[dot + 3] = '\0';
        }
        else if(len - dot == 2)
        {
            buf[len++] = '0';
            buf[len] = '\0';
        }
        else if(len - dot == 1)
        {
            buf[len++] = '0';
            buf[len++] = '0';
            buf[len] = '\0';
        }
        else if(len - dot == 0)
        {
            buf[len++] = '.';
            buf[len++] = '0';
            buf[len++] = '0';
            buf[len] = '\0';
        }
        */
        for(left = 0; buf[left] == '0'; ++left);
        // 输出整数部分
        if(buf[left] == '.')
            --left;
        if(sign)
            putchar('(');
        while(left < dot)
        {
            putchar(buf[left++]);
            if(left != dot && (dot - left) % 3 == 0)
                putchar(',');
        }
        // 输出小数部分
        printf("%s", buf + dot);
        if(sign)
            putchar(')');
        putchar('\n');
    }
    return 0;
}

