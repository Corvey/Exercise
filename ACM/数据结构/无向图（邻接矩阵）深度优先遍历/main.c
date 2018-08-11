﻿#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *pNext;
}NODE, *PNODE;

typedef struct queue
{
    struct node *pFront;
    struct node *pRear;
}QUEUE, *PQUEUE;

typedef struct graph
{
    char vertex[9];
    int brim[9][9];
}GRAPH, *PGRAPH;

void InitQueue(PQUEUE pQ)//初始化队列
{
    pQ->pRear = (PNODE)malloc( sizeof(NODE) );
    pQ->pFront = pQ->pRear;
    pQ->pFront->pNext = NULL;
}

void InQueue(PQUEUE pQ, int data)//入队
{
    pQ->pRear->pNext = (PNODE)malloc( sizeof(NODE) );
    pQ->pRear = pQ->pRear->pNext;
    pQ->pRear->pNext = NULL;
    pQ->pRear->data = data;
}

int OutQueue(PQUEUE pQ)//出队
{
    int data = pQ->pFront->pNext->data;
    PNODE pTemp = pQ->pFront->pNext->pNext;
    free(pQ->pFront->pNext);
    pQ->pFront->pNext = pTemp;
    return data;
}

void InitGraph(PGRAPH pG)//初始化图
{
    char c;

    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            pG->brim[i][j] = 0;

    for(int i=0; i<9; i++)
    {
        pG->vertex[i] = 'A' + i;
        printf("请输入与%c相连的点：", 'A' + i);
        fflush(stdin);
        scanf("%c", &c);
        while( c!='\n')
        {
            pG->brim[i][(int)c-'A'] = 1;
            scanf("%c", &c);
        }
    }
    /*
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            printf("%d ", pG->brim[i][j]);
        }
        printf("\n");
    }
    */
}

void BFStraverse(PGRAPH pG) //广度优先遍历
{
    int done[9]={0};
    PQUEUE pQ = (PQUEUE)malloc( sizeof(QUEUE) );
    InitQueue(pQ);
    for(int i=0; i<9; i++)
    {
        if(!done[i])
        {
            printf("%c ", pG->vertex[i]);
            done[i] = 1;
            InQueue(pQ, i);
            while(pQ->pFront->pNext)
            {
                int i = OutQueue(pQ);
                for(int j=0; j<9; j++)
                {
                    if(pG->brim[i][j] && !done[j])
                    {
                        printf("%c ", pG->vertex[j]);
                        done[j] = 1;
                        InQueue(pQ, j);
                    }
                }
            }

        }
    }
}
int done[9]={0};
void DFStraverse(PGRAPH pG, int i) //深度优先遍历
{
    printf("%c ", pG->vertex[i]);
    done[i] = 1;
    for(int j=0; j<9; ++j)
    {
        if(pG->brim[i][j] && !done[j])
        {
            DFStraverse(pG, j);
        }
    }
}

int main(void)
{
    PGRAPH pG = (PGRAPH)malloc( sizeof(GRAPH) );
    InitGraph(pG);
    //BFStraverse(pG);  //广度优先遍历
    DFStraverse(pG, 0);//深度优先遍历
    return 0;
}
