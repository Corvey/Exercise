#include <stdio.h>
#include <stdlib.h>
#define N 8
int chess[N][N];

int next(int * x, int * y, int step)
{
    switch(step)
    {
    case 0:
        if(*y + 1 < N && *x - 2 >= 0 && !chess[*x - 2][*y + 1])
        {
            *x -= 2;
            *y += 1;
            return 1;
        }
        break;
    case 1:
        if(*y + 2 < N && *x - 1 >= 0 && !chess[*x - 1][*y + 2])
        {
            *x -= 1;
            *y += 2;
            return 1;
        }
        break;
    case 2:
        if(*y + 2 < N && *x + 1 < N && !chess[*x + 1][*y + 2])
        {
            *x += 1;
            *y += 2;
            return 1;
        }
        break;
    case 3:
        if(*y + 1 < N && *x + 2 < N && !chess[*x + 2][*y + 1])
        {
            *x += 2;
            *y += 1;
            return 1;
        }
        break;
    case 4:
        if(*y - 1 >= 0 && *x + 2 < N && !chess[*x + 2][*y - 1])
        {
            *x += 2;
            *y -= 1;
            return 1;
        }
        break;
    case 5:
        if(*y - 2 >= 0 && *x + 1 < N && !chess[*x + 1][*y - 2])
        {
            *x += 1;
            *y -= 2;
            return 1;
        }
        break;
    case 6:
        if(*y - 2 >= 0 && *x - 1 >= 0 && !chess[*x - 1][*y - 2])
        {
            *x -= 1;
            *y -= 2;
            return 1;
        }
        break;
    case 7:
        if(*y - 1 >= 0 && *x - 2 >= 0 && !chess[*x - 2][*y - 1])
        {
            *x -= 2;
            *y -= 1;
            return 1;
        }
        break;
    default:
        break;
    }
    return 0;
}
int traverse(int x, int y, int count)
{
    int x1=x, y1=y, flag, tag=-1;
    chess[x][y] = count;
    if(count == N*N)
    {
        return 1;
    }

    do
    {
        flag = next(&x1, &y1, ++tag);

    } while (!flag && tag<7);

    while(flag)
    {
        if( traverse(x1, y1, count+1) )
        {
            return 1;
        }
        else
        {
            x1 = x;
            y1 = y;
            do
            {
                flag = next(&x1, &y1, ++tag);

            }while(!flag && tag < 7);
        }
    }
    if(!flag)
        chess[x1][y1] = 0;
    return 0;
}
int deepsearch(int x, int y, int j)//other
{
    /*save the value x,y*/
    int x1 = x, y1 = y;
    int tag = 0, i = 0;
    /*save j on chess[x][y]*/
    chess[x][y] = j;

    /*recursion exit condition*/
    if(j == N*N)
    {
        return 1;
    }
    /*find the next point in eight directions*/
    tag = next(&x1,&y1,i);
    /*find the nextx,nexty */
    while (tag == 0 && i < 7)
    {
        i ++;
        tag = next(&x1,&y1, i);
    }

    /*the nextxy be found*/
    while(tag)
    {
        if(deepsearch(x1,y1,j+1))
            return 1;

     /*if failed, a new finding process */
        x1 = x; y1 = y;
        i ++;
        tag = next(&x1,&y1,i);
        while (tag == 0 && i < 7)
        {
            i ++;
            tag = next(&x1,&y1,i);
        }
    }
    /*no direction can find next point*/
    if(tag == 0)
        chess[x][y] = 0;
    return 0;
}
void draw(void)
{
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            printf("%-2d\t", chess[i][j]);
        }
        printf("\n");
    }
}
int main(void)
{
    if( !traverse(2, 0, 1) )
    {
        printf("无解！\n");
    }
    //deepsearch(2, 0, 1);
    draw();
}
