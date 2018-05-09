/*
#include <stdio.h>
int main(void)
{
    int n, a[10] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};
    char ch;
    while(~scanf("%c", &ch))
    {
        n = 1;
        while(ch != 10)
        {
            n *= a[ch-48];
            ch = getchar();
        }
        printf("%d\n", n);
    }
    return 0;
}
*/
/*
#include <stdio.h>
int main(void)
{
    int n, a[10] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};
    char s[6];
    while(~scanf("%s", s))
    {
        getchar();
        n = 1;
        for(int i=0; s[i]; ++i)
            n *= a[s[i]-48];
        printf("%d\n", n);
    }
}
*/
main(char c)
{
    int n, a[] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};

    while(1)
    {
        n = 1;

        do
        {
            c = getchar();

            if(c == -1)
            {
                return;
            }
            else
                if(c == 10)
                {
                    break;
                }

            n *= a[c - 48];
        }
        while(c - 10);

        printf("%d\n", n);
    }
}
///*
main(char c){int n,a[]={2,7,2,3,3,4,2,5,1,2};while(1){n=1;do{c=getchar();if(c==-1)return;else if(c==10)break;n*=a[c-48];}while(c-10);printf("%d\n",n);}}
//*/
