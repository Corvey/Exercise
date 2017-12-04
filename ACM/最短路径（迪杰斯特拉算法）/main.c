#include <stdio.h>
#include <stdlib.h>
#define MAX 10   //最大顶点个数
#define INFINITY 65535

typedef struct graph
{
    int num;  //顶点个数
    int side[MAX][MAX];  //弧
}GRAPH, *PGRAPH;

PGRAPH InitGraph(void) //
{
    PGRAPH pG = (PGRAPH)malloc(sizeof(GRAPH));
    while(1)
    {
        printf("请输入顶点个数：");
        scanf("%d", &pG->num);
        fflush(stdin);
        if(pG->num <= MAX)
            break;
        else
            printf("最大顶点个数为%d个，请重新输入！\n");
    }
    for(int i=0; i < pG->num; ++i)
    {
        for(int j=0; j < pG->num; ++j)
        {
            if(i==j)
                pG->side[i][j] = 0;
            else
                pG->side[i][j] = INFINITY;
        }
    }
    for(int i=0; i < pG->num; ++i)
    {
        printf("请输入点%c相连的点及其弧的权值：", i+'A');
        while(1)
        {
            char c;
            scanf("%c", &c);
            if(c == ' ')
                continue;
            else if(c == '\n')
                break;
            else
                scanf("%d", &pG->side[i][(int)c-'A']);
        }
    }
    //输出邻接矩阵检查
    for(int i=0; i < pG->num; ++i)
    {
        for(int j=0; j < pG->num; ++j)
            printf("%-5d ", pG->side[i][j]);
        printf("\n");
    }
    return pG;
}

void FindShortestPath(PGRAPH pG)
{
    int *D = (int *)malloc(sizeof(int)*(pG->num));
    int *P = (int *)malloc(sizeof(int)*(pG->num));
    //初始化数据
    for(int i=0; i < pG->num; ++i)
    {
        D[i] = pG->side[0][i];
        P[i] = 0;
    }
    int done = 1;
    while(done != (1<<pG->num)-1)
    {
        int min = INFINITY;
        int x;
        for(int i=1; i < pG->num; ++i)
        {
            if( !((done>>i)&1) && D[i] < min)
            {
                min = D[i];
                x = i;
            }
        }
        done |= 1<<x;
        for(int i=1; i < pG->num; ++i)
        {
            if( !((done>>i)&1) && i != x && min + pG->side[x][i] < D[i])
            {
                D[i] = min + pG->side[x][i];
                P[i] = x;
            }
        }
    }
    for(int i=0; i < pG->num; ++i)
    {
        printf("%d ", D[i]);
    }
    printf("\n0 ");
    for(int i=1; i < pG->num; ++i)
    {
        printf("%c ", P[i]+'A');
    }
}

int main(void)
{
    PGRAPH pG = InitGraph();
    FindShortestPath(pG);
}







