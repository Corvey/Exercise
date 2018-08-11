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
    int P[MAX][MAX];
    int D[MAX][MAX];
    //初始化数据
    for(int i=0; i < pG->num; ++i)
    {
        for(int j=0; j < pG->num; ++j)
        {
            D[i][j] = pG->side[i][j];
            P[i][j] = i;
        }
    }

    for(int i=0; i < pG->num; ++i)
    {
        for(int j=1; j < pG->num; ++j)
        {
            for(int k=0; k < pG->num; ++k)
            {
                if(D[i][j] > pG->side[i][j] + pG->side[j][k])
                {
                    D[i][j] = pG->side[i][j] + pG->side[j][k];
                    P[i][j] = k;
                }
            }
        }
    }

    printf("D=\n");
    for(int i=0; i < pG->num; ++i)
    {
        printf("%c:", i+'A');
        for(int j=0; j < pG->num; ++j)
        {
            printf("%d ", D[i][j]);
        }
        printf("\n");
    }
    printf("P=\n");
    for(int i=0; i < pG->num; ++i)
    {
        printf("%c:", i+'A');
        for(int j=0; j < pG->num; ++j)
        {
            printf("%c ", P[i][j]+'A');
        }
        printf("\n");
    }
}

int main(void)
{
    PGRAPH pG = InitGraph();
    FindShortestPath(pG);
}






