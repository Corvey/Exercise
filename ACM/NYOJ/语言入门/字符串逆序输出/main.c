#include <stdio.h>
char s[41];
int abc(int n)
{
    if(s[n] == '\0')
        return 1;
    else if(s[n] == ' ' || s[n]>='0' && s[n]<='9')
        return abc(n+1);
    else
    {
        abc(n+1);
        printf("%c", s[n]);
    }
}
int main(void)
{
    int n;
    scanf("%d", &n);
    getchar();
    for(int i=0; i<n; ++i)
    {
        gets(s);
        abc(0);
        printf("\n");
    }
}
