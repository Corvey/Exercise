#include <stdio.h>
int main(void)
{
    int n;
    char ch[3], t;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        getchar();//fflush(stdin)不行？
        scanf("%c%c%c", ch, ch+1, ch+2);
        for(int j=0; j<2; ++j)
        {
            for(int k=0; k<2-j; ++k)
            {
                if(ch[k] > ch[k+1])
                    t = ch[k], ch[k] = ch[k+1], ch[k+1] = t;
            }
        }
        printf("%c %c %c\n", ch[0], ch[1], ch[2]);
    }
}
