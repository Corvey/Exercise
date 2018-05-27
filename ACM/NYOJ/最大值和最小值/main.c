#include <stdio.h>
int main(void)
{
    int n, count;
    char s[101];
    scanf("%d\n", &n);
    while(n--)
    {
        for(count=0; (s[count] = getchar())!='\n'; ++count);
        s[count] = '\0';
        if(s[0] == '0')
            printf("0 0\n");
        else
        {
            for(int i=0; i<count-1; ++i)
                for(int j=0; j<count-i-1; ++j)
                    if(s[j] < s[j+1])
                        s[j] ^= s[j+1], s[j+1] ^= s[j], s[j] ^= s[j+1];
            printf("%s ", s);
            for(int i=count-1; i>=0; --i)
                if(s[i] != '0')
                    putchar(s[i]);
            putchar('\n');
        }
    }
}
