#include <stdio.h>
void qwe(char *s, int x, int n)
{
    if(x)
    {
        s[n] = x%7 + '0';
        qwe(s, x/7, n-1);
    }
    else
        return;
}
int main(void)
{
    int n;
    while(~scanf("%d", &n))
    {
        char s[] = {-1,-1,-1,-1,-1,-1,-1,0};
        if(n)
        {
            qwe(s, n, 6);
            for(int i=0; s[i]; ++i)
            {
                if(~s[i])
                    printf("%c", s[i]);
            }
            printf("\n");
        }
        else
            printf("0\n");
    }
    return 0;
}

/*
int q(char *s,int x,int n){if(x){s[n]=x%7+48;q(s,x/7,n-1);}else return;}main(int n){while(~scanf("%d", &n)){char s[]={-1,-1,-1,-1,-1,-1,-1,0};if(n){q(s,n,6);for(int i=0;s[i];++i)if(~s[i])putchar(s[i]);printf("\n");}else printf("0\n");}}
*/
