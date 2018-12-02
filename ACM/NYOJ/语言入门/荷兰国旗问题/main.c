#include <stdio.h>
int main(void)
{
    int r, w, b, n;
    char s[1001];
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        getchar();
        scanf("%s", s);
        r = w = b = 0;
        for(int j=0; s[j] != '\0'; ++j)
        {
            switch (s[j])
            {
            case 'R':
                ++r;
                break;

            case 'W':
                ++w;
                break;

            case 'B':
                ++b;
                break;

            default:
                break;
            }
        }
        for(int k=0; k<r; ++k)
            printf("R");
        for(int k=0; k<w; ++k)
            printf("W");
        for(int k=0; k<b; ++k)
            printf("B");
        printf("\n");
    }
}
