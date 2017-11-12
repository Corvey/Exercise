#include <stdio.h>
#include <stdlib.h>
int success;
int result = 0;
void Try(int row,int ld,int rd)
{
    int p,pos;
    if(row!=success)
    {
        pos = success & (~(row|ld|rd));
        while(pos)
        {
            p = pos & (~pos + 1);
            pos -= p;
            Try( row|p , (ld|p)<<1 , (rd|p)>>1 );
        }
    }
    else
    {
        ++result;
    }
}
int main(void)
{
    int n;
    printf("请输入你要解决的问题里有几个皇后：");
    fflush(stdin);
    fscanf(stdin, "%d", &n);
    success = (1 << n) - 1;
    Try(0, 0, 0);
    printf("%d皇后问题共有%d种方案！\n", n, result);
}
