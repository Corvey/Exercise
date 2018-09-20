#include <stdio.h>
#include <stdlib.h>
typedef struct tree
{
    int num;
    int ceng;
    struct tree *pLeft;
    struct tree *pRight;
}TREE, *PTREE;

typedef struct queue
{
    struct node *pFront;
    struct node *pRear;
}QUEUE, *PQUEUE;

typedef struct node
{
    struct tree *pTree;
    struct node *pNext;
}NODE, *PNODE;

void CreatTree(PTREE *pT, int ceng)
{
    char ch;
    while(1)
    {
        scanf("%c", &ch);
        if(ch != ' ')
            break;
    }
    if(ch >= '0' && ch <= '9')
    {
        *pT = (PTREE)malloc(sizeof(TREE));
        (*pT)->num = ch - '0';
        (*pT)->ceng = ceng;
        CreatTree(&(*pT)->pLeft, ceng+1);
        CreatTree(&(*pT)->pRight, ceng+1);
    }
    else if(ch == '#')
        *pT = NULL;
}

void InitQueue(PQUEUE *pQ)
{
    *pQ = (PQUEUE)malloc(sizeof(QUEUE));
    (*pQ)->pRear = (PNODE)malloc(sizeof(NODE));
    (*pQ)->pRear->pNext = NULL;
    (*pQ)->pFront = (*pQ)->pRear;
}

void EnQueue(PQUEUE pQ, PTREE pT)
{
    pQ->pRear->pNext = (PNODE)malloc(sizeof(NODE));
    pQ->pRear = pQ->pRear->pNext;
    pQ->pRear->pNext = NULL;
    pQ->pRear->pTree = pT;
}

void DeQueue(PQUEUE pQ)
{
    PNODE p = pQ->pFront->pNext->pNext;
    free(pQ->pFront->pNext);
    pQ->pFront->pNext = p;
}

void BFS(PTREE pT, PQUEUE pQ, int ceng)
{
    while(pQ->pFront->pNext)
    {
        if(pQ->pFront->pNext->pTree->pLeft)
            EnQueue(pQ, pQ->pFront->pNext->pTree->pLeft);
        if(pQ->pFront->pNext->pTree->pRight)
            EnQueue(pQ, pQ->pFront->pNext->pTree->pRight);
        if(pQ->pFront->pNext->pTree->ceng == ceng)
            printf("%d~", pQ->pFront->pNext->pTree->num);
        else if(pQ->pFront->pNext->pTree->ceng > ceng)
            break;
        DeQueue(pQ);
    }
    printf("\b \n");
}

void FreeQueue(PQUEUE pQ)
{
    PNODE p;
    while(pQ->pFront->pNext)
    {
        p = pQ->pFront->pNext->pNext;
        DeQueue(pQ);
    }
    free(pQ->pFront);
}

void FreeTree(PTREE *pT)
{
    if((*pT)->pLeft)
        FreeTree(&(*pT)->pLeft);
    if((*pT)->pRight)
        FreeTree(&(*pT)->pRight);
    free(*pT);
    *pT = NULL;
}

int main(void)
{
    int n, x;
    char ch;
    PTREE pT;
    PQUEUE pQ;
    PNODE p;
    scanf("%d", &n);
    getchar();
    for(int i=0; i<n; ++i)
    {
        CreatTree(&pT, 1);
        scanf(" @ %d", &x);
        getchar();
        InitQueue(&pQ);
        EnQueue(pQ, pT);
        BFS(pT, pQ, x);
        FreeQueue(pQ);
        FreeTree(&pT);
    }
}
