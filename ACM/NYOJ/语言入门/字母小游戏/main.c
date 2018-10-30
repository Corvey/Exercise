#include <stdio.h>
int main(void)
{
    int n, all;
    char s[201];
    scanf("%d", &n);
    getchar();
    for(int i=0; i<n; ++i)
    {
        scanf("%s", s);
        all = 0;
        for(int j=0; s[j]!='\0'; ++j)
        {
            if(s[j] >= 'a' && s[j] <= 'z')
                ++all;
        }
        if(all%26 == 0)
            printf("z\n");
        else
            printf("%c\n", all%26+'a'-1);
    }
}
