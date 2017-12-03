#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10  //最大顶点个数

typedef struct node
{
    int from;
    int to;
    int weight;
    struct node *pNext;
}NODE, *PNODE;

typedef struct graph
{
    int num;
    char vertex[N];
    int edge[N][N];
}GRAPH, *PGRAPH;

PGRAPH InitGraph(void)   //初始化图
{
    PGRAPH pG = (PGRAPH)malloc(sizeof(GRAPH));
    for(int i=0; i<N; ++i)
    {
        pG->vertex[i] = 'A'+i;
        for(int j=0; j<N; ++j)
            pG->edge[i][j] = 0;
    }


    while(1)
    {
        printf("请输入顶点个数：");
        scanf("%d", &(pG->num) );
        if(pG->num > N)
        {
            printf("顶点个数最多为%d个，请重新输入！\n", N);
            fflush(stdin);
        }
        else
        {
            fflush(stdin);
            break;
        }
    }
    for(int i=0; i<pG->num; ++i)
    {
        printf("请输入%c点所连接的点及其弧的权：", 'A'+i);
        while(1)
        {
            char ch;
            scanf("%c", &ch);
            if(' ' == ch)
                continue;
            else if('\n' == ch)
                break;
            else
                scanf("%d", &(pG->edge[i][(int)ch-'A']) );
        }
    }
    return pG;
}

PNODE DeList(PNODE pHead, PNODE p)    //出链
{
    while(pHead->pNext != p)
        pHead = pHead->pNext;
    PNODE pTemp = p->pNext;
    free(p);
    pHead->pNext = pTemp;
    return pTemp;
}

void CreatMinTree(PGRAPH pG)   //生成最小生成树
{
    PNODE pMin = (PNODE)malloc(sizeof(NODE));
    pMin->pNext = NULL;
    int done = 0;
    int result = (1<<pG->num)-1;
    int MinWeight = 65535;
    //找出最小弧
    for(int i=0; i<pG->num; ++i)
    {
        for(int j=0; j<pG->num; ++j)
        {
            if(!pG->edge[i][j])
                continue;
            else if(MinWeight > pG->edge[i][j])
            {
                pMin->from = i;
                pMin->to = j;
                pMin->weight = pG->edge[i][j];
                MinWeight = pG->edge[i][j];
            }
        }
    }
    //读入起点所有弧
    PNODE pHead = (PNODE)malloc((sizeof(NODE)));
    pHead->pNext = NULL;
    PNODE pTail = pHead;
    for(int i=0; i<pG->num; ++i)
    {
        if(!pG->edge[pMin->from][i])
            continue;
        else
        {
            pTail->pNext = (PNODE)malloc(sizeof(NODE));
            pTail = pTail->pNext;
            pTail->pNext = NULL;
            pTail->from = pMin->from;
            pTail->to = i;
            pTail->weight = pG->edge[pMin->from][i];
        }
    }
    done |= 1<<(pMin->from);
    for(int i=0; i<pG->num; ++i)
    {
        if(!pG->edge[pMin->to][i])
            continue;
        else
        {
            pTail->pNext = (PNODE)malloc(sizeof(NODE));
            pTail = pTail->pNext;
            pTail->pNext = NULL;
            pTail->from = pMin->to;
            pTail->to = i;
            pTail->weight = pG->edge[pMin->to][i];
        }
    }
    done |= 1<<(pMin->to);
    printf("点%c连点%c。\n", pG->vertex[pMin->from], pG->vertex[pMin->to]);
    while(done != result)
    {
        MinWeight = 65535;
        pTail = pHead;
        while(pTail->pNext)
        {
            if( (done & 1<<pTail->pNext->to) == 1<<(pTail->pNext->to) )
            {
                pTail->pNext = DeList(pHead, pTail->pNext);
                continue;
            }
            else if(pTail->pNext->weight < MinWeight)
            {
                pMin->from = pTail->pNext->from;
                pMin->to = pTail->pNext->to;
                pMin->weight = pTail->pNext->weight;
                MinWeight = pTail->pNext->weight;
            }
            pTail = pTail->pNext;
        }
        done |= 1<<(pMin->to);
        printf("点%c连点%c。\n", pG->vertex[pMin->from], pG->vertex[pMin->to]);
        if(done == result)
            break;

        for(int i = 0; i < pG->num; ++i)
        {
            if(!pG->edge[pMin->to][i])
                continue;
            else
            {
                pTail->pNext = (PNODE)malloc(sizeof(NODE));
                pTail = pTail->pNext;
                pTail->pNext = NULL;
                pTail->from = pMin->to;
                pTail->to = i;
                pTail->weight  = pG->edge[pMin->to][i];
            }
        }
    }
}

int main(void)
{
    PGRAPH pG = InitGraph();
    /*  //检查邻接矩阵
    for(int i = 0; i < pG->num; ++i)
    {
        printf("%c\t", pG->vertex[i]);
        for(int j = 0; j < pG->num; ++j)
            printf("%d\t", pG->edge[i][j]);
        printf("\n");
    }
    */
    CreatMinTree(pG);
}
