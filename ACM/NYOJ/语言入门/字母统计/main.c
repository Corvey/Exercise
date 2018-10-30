#include <stdio.h>
#include <string.h>
int main(void)
{
    int n, a[26], max, x;
    char c;
    scanf("%d", &n);
    getchar();
    for(int i=0; i<n; ++i)
    {
        memset(a, 0, 26*sizeof(int));
        while(1)
        {
            scanf("%c", &c);
            if(c == '\n')
                break;
            else
                ++a[(int)c-'a'];
        }
        max = a[0];
        x = 0;
        for(int j=0; j<26; ++j)
        {
            if(a[j] > max)
            {
                max = a[j];
                x = j;
            }
        }
        printf("%c\n", x+'a');
    }
}
