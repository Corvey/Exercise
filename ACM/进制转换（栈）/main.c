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
    int x, n;
    printf("请输入你要转换的数：");
    scanf("%d", &x);
    while(1)
    {
        printf("请输入你要将此数转换成几进制的数：");
        scanf("%d", &n);
        if(n>=2 && n<=16)
            break;
        else
            printf("只能进行二进制到十六进制之间的转换！请重新输入！\n");
    }
    while(x)
    {
        Push(pS, x%n);
        x /= n;
    }
    printf("转换结果：");
    while(pS->pTop != pS->pBottom)
    {
        x = Pop(pS);
        if(x < 10)
            printf("%d", x);
        else
            printf("%c", 'A'+x-10);
    }
    printf("\n");
    return 0;
}
