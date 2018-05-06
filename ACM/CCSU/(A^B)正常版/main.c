#include <stdio.h>
#define x 10007
int qwe(int a, int b, int c)
{
    if(b <= 1)
        return a*c%x;
    else if(b&1)
        return qwe(a*a%x, (b-1)/2, c*a%x);
    else
        return qwe(a*a%x, b/2, c);
}
int main(void)
{
    int a, b;
    while(~scanf("%d%d", &a, &b))
        printf("%d\n", qwe(a, b, 1));
    return 0;
}
/*
#define x 10007
int q(int a,int b,int c){return b<=1?a*c%x:b&1?q(a*a%x,(b-1)/2,c*a%x):q(a*a%x,b/2,c);}main(int a,int b){while(~scanf("%d%d",&a,&b))printf("%d\n",q(a,b,1));}
*/
