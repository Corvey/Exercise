#include <stdio.h>
#include <stdlib.h>
#define N 3

typedef char Elemtype;
typedef struct graph
{
    Elemtype vertex[N];
    struct brim *pBrim[N];
}GRAPH, *PGRAPH;
typedef struct brim
{
    int vertex;
    struct brim *pNext;
}BRIM, *PBRIM;
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
    for(int i=0; i<N; ++i)
    {
        pG->pBrim[i] = (PBRIM)malloc( sizeof(BRIM) );
        pG->pBrim[i]->pNext = NULL;
        PBRIM pTemp = pG->pBrim[i];
        pG->vertex[i] = 'A' + i;
        printf("请输入%c点指向的点：", 'A' + i);
        char c;
        scanf("%c", &c);
        while( c != '\n')
        {
            pG->pBrim[i]->pNext = (PBRIM)malloc( sizeof(BRIM) );
            pG->pBrim[i] = pG->pBrim[i]->pNext;
            pG->pBrim[i]->pNext = NULL;
            pG->pBrim[i]->vertex = c-'A';
            scanf("%c", &c);
        }
        pG->pBrim[i] = pTemp;
    }
}
int done[N] = {0};
void DFStraverse(PGRAPH pG, int i)  //深度优先遍历
{
    PBRIM pTemp = pG->pBrim[i]->pNext;
    printf("%c ", pG->vertex[i]);
    done[i] = 1;
    while(pTemp)
    {
        if(!done[pTemp->vertex])
        {
            DFStraverse(pG, pTemp->vertex);
        }
        pTemp = pTemp->pNext;
    }
}

void BFStraverse(PGRAPH pG) //广度优先遍历
{
    int done[N] = {0};
    PQUEUE pQ;
    InitQueue(pQ);
    for(int i=0; i<N; ++i)
    {
        if(!done[i])
        {
            InQueue(pQ, i);
            while(pQ->pFront->pNext)
            {
                int j = OutQueue(pQ);
                printf("%c ", pG->vertex[j]);
                done[j] = 1;
                PBRIM Temp = pG->pBrim[j]->pNext;
                while(Temp)
                {
                    InQueue(pQ, Temp->vertex);
                    Temp = Temp->pNext;
                }
            }
        }
    }
}

int main(void)
{
    PGRAPH pG = (PGRAPH)malloc( sizeof(GRAPH) );
    InitGraph(pG);
    printf("深度优先遍历：");
    DFStraverse(pG, 0);
    printf("\n");
    printf("广度优先遍历：");
    BFStraverse(pG);
    printf("\n");
    return 0;
}
