#include <stdio.h>
#include <stdlib.h>
#define N 11
typedef struct node
{
        int num;
        struct node * pNext;
}NODE, *LIST;

void Print(LIST pTail)
{
    for(int i=0; i<N; ++i)
    {
        pTail = pTail->pNext;
        printf("%2d\n", pTail->num);
    }

}

void GetMidNode(LIST pL)
{
    LIST pTail = pL->pNext;
    LIST pMid = pL->pNext;
    while(pTail->pNext)
    {
        if(pTail->pNext->pNext)
        {
            pTail = pTail->pNext->pNext;
            pMid = pMid->pNext;
        }
        else
        {
            pTail = pTail->pNext;
        }
    }
    printf("\nMid=%d\n", pMid->num);
}

int main(void)
{
    LIST pHead = NULL, pTail = NULL, pMid = NULL;
    pHead = (LIST)malloc(sizeof(NODE));
    pHead->pNext = NULL;
    pTail = pHead;
    for(int i=0; i<N; ++i)
    {
        pTail->pNext = (LIST)malloc(sizeof(NODE));
        pTail = pTail->pNext;
        pTail->pNext = NULL;
        pTail->num = i+1;
    }
    Print(pHead);
    GetMidNode(pHead);
}
