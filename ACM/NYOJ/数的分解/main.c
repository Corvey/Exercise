#include <stdio.h>
#include <math.h>
int judge(int x)
{
    if(x==1)
        return 0;
    int a = sqrt(x+1);
    for(int i=2; i<=a; ++i)
    {
        if(x%i == 0)
           return 0;
    }
    return 1;
}
int main(void)
{
    int n, a[401];
    for(int i=0; i<401; ++i)
    {
        if(judge(i))
            a[i] = -1;
    }

}
