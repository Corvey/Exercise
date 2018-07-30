#include <stdio.h>
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
    char vertex[9]; //顶点
    int brim[9];    //边
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
            pG->brim[i] = 0;

    for(int i=0; i<9; i++)
    {
        pG->vertex[i] = 'A' + i;
        printf("请输入与%c相连的点：", 'A' + i);
        fflush(stdin);
        scanf("%c", &c);
        while( c!='\n')
        {
            pG->brim[i] |= 1<<(9-1-(int)c+'A');
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

void BFStraverse(PGRAPH pG)
{
    int done = 0;
    PQUEUE pQ = (PQUEUE)malloc( sizeof(QUEUE) );
    InitQueue(pQ);
    for(int i=0; i<9; i++)
    {
        if(! (done&(1<<(9-i-1))) )
        {
            printf("%c ", pG->vertex[i]);
            done |= 1<<(9-i-1);
            InQueue(pQ, i);
            while(pQ->pFront->pNext)
            {
                int j = OutQueue(pQ);
                for(int k=0; k<9; k++)
                {
                    if( (pG->brim[j] & (1<<(9-k-1))) && ! (done & (1<<(9-k-1))) )
                    {
                        printf("%c ", pG->vertex[k]);
                        done |= 1<<(9-k-1);
                        InQueue(pQ, k);
                    }
                }
            }

        }
    }
}

int main(void)
{
    PGRAPH pG = (PGRAPH)malloc( sizeof(GRAPH) );
    InitGraph(pG);
    BFStraverse(pG);
    return 0;
}
