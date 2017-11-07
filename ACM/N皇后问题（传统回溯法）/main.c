#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int judge(int *a,int n);
void Try(int n,int max,int *a,int *result);
int main(void)
{
    int n,*a,result=0;
    printf("请输入你要解决的问题中有几个皇后：");
    fflush(stdin);
    fscanf(stdin,"%d",&n);
    a=(int*)malloc(n*sizeof(int));
    Try(0,n,a,&result);
    printf("%d皇后问题共有%d种方案！\n",n,result);
}
int judge(int *a,int n)
{
    for(int i = 0; i < n; i++)
    {
        if(a[n] == a[i] || fabs((float)(a[n] - a[i]) / (n - i)) == 1)
        {
            return 0;
        }
    }
    return 1;
}
void Try(int n,int max,int *a,int *result)
{
    for(int i=0;i<max;i++)
    {
        a[n]=i;
        if(judge(a,n)==1)
        {
            if(n==max-1)
            {
                (*result)++;
            }
            else
            {
                Try(n+1,max,a,result);
            }
        }
    }
}
