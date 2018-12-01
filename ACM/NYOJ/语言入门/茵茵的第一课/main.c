#include <stdio.h>
int main(void)
{
    char s[21];
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%s", s);
        puts(s);
    }
}
