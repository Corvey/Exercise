#include <stdio.h>
int main(void)
{
    int n;
    char s[12];
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%s", s);
        getchar();
        for(int j=0; j<11; ++j)
        {
            if(s[j] >= 'w')
                printf("9");
            else if(s[j] >= 't')
                printf("8");
            else if(s[j] >= 'p')
                printf("7");
            else if(s[j] >= 'm')
                printf("6");
            else if(s[j] >= 'j')
                printf("5");
            else if(s[j] >= 'g')
                printf("4");
            else if(s[j] >= 'd')
                printf("3");
            else if(s[j] >= 'a')
                printf("2");
        }
        printf("\n");
    }
}
