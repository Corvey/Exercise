#include <stdio.h>
int main(void)
{
    int n;
    char s[101];
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%s", s);
        for(int j=0; s[j] != '\0'; ++j)
        {
            if(s[j] <= 'Z')
            {
                s[j] += 32;
            }
            else
                s[j] -= 32;
        }
        puts(s);
    }
}
