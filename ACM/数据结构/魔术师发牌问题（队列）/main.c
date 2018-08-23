#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int num;
    struct node *pNext;
}NODE, *PNODE;

typedef struct queue
{
    struct node *pFront;
    struct node *pRear;
}QUEUE, *PQUEUE;

void Init(PQUEUE *pQ)//初始化
{
    *pQ = (PQUEUE)malloc(sizeof(QUEUE));
    (*pQ)->pRear = (PNODE)malloc(sizeof(NODE));
    (*pQ)->pFront = (*pQ)->pRear;
    (*pQ)->pFront->pNext = NULL;
}

void EnQueue(PQUEUE pQ, int data)//入队
{
    pQ->pRear->pNext = (PNODE)malloc(sizeof(NODE));
    pQ->pRear = pQ->pRear->pNext;
    pQ->pRear->num = data;
    pQ->pRear->pNext = NULL;
}

int DeQueue(PQUEUE pQ)//出队
{
    int x = pQ->pFront->pNext->num;
    PNODE pTemp = pQ->pFront->pNext->pNext;
    free(pQ->pFront->pNext);
    pQ->pFront->pNext = pTemp;
    return x;
}

void Print(PNODE pTemp)//打印队列
{
    while(pTemp)
    {
        printf("%d\n", pTemp->num);
        pTemp = pTemp->pNext;
    }
}

int main(void)
{
    PQUEUE pQ = NULL;
    Init(&pQ);
    for(int i=0; i<13; ++i)
    {
        EnQueue(pQ, 0);
    }
    for(int count=1; count!=14; ++count)
    {
        for(int i=1; i<count;)
        {
            if(!pQ->pFront->pNext->num)
                ++i;
            EnQueue( pQ, DeQueue(pQ) );
        }
        while(pQ->pFront->pNext->num)
            EnQueue( pQ, DeQueue(pQ) );
        pQ->pFront->pNext->num = count;
    }
    EnQueue( pQ, DeQueue(pQ) );
    Print(pQ->pFront->pNext);
}
