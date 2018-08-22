#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *pNext;
}NODE, *PNODE;

typedef struct stack
{
    struct node *pTop;
    struct node *pBottom;
}STACK, *PSTACK;

void InitStack(PSTACK *pS)
{
    *pS = (PSTACK)malloc(sizeof(STACK));
    (*pS)->pBottom = (PNODE)malloc(sizeof(NODE));
    (*pS)->pBottom->pNext = NULL;
    (*pS)->pTop = (*pS)->pBottom;
}

void Push(PSTACK pS, int data)
{
    PNODE pTemp = (PNODE)malloc(sizeof(NODE));
    pTemp->num = data;
    pTemp->pNext = pS->pTop;
    pS->pTop = pTemp;
}

int Pop(PSTACK pS)
{
    PNODE pTemp = pS->pTop->pNext;
    int x = pS->pTop->num;
    free(pS->pTop);
    pS->pTop = pTemp;
    return x;
}

int main(void)
{
    PSTACK pS;
    InitStack(&pS);
    int x;
    while(~scanf("%d", &x))
    {
        if(x)
        {
            while(x)
            {
                Push(pS, x % 7);
                x /= 7;
            }
            while(pS->pTop != pS->pBottom)
            {
                x = Pop(pS);
                printf("%d", x);
            }
            printf("\n");
        }
        else
            printf("0\n");
    }
}
