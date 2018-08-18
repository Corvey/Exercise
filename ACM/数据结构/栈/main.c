#include <stdio.h>
#include <stdlib.h>
typedef struct node //结点
{
    int n;
    struct node *pNext;
}NODE, * PNODE;

typedef struct stack  //栈
{
    PNODE pTop;
    PNODE pBottom;
}STACK, * PSTACK;

PSTACK init(void) //初始化
{
    printf("------------------------------------------\n");
    printf("现在开始创建栈！\n");
    PSTACK pS;
    pS = (PSTACK)malloc(sizeof(STACK));
    pS->pBottom = (PNODE)malloc(sizeof(NODE));
    pS->pBottom->n = 1;
    pS->pBottom->pNext = NULL;
    pS->pTop = pS->pBottom;
    return pS;
}

void push(PSTACK pS)//入栈
{
    printf("------------------------------------------\n");
    printf("现在开始入栈！\n\n");
    int i,x;
    for(i=0;;i++)
    {
        printf("请输入第%d个数据：",i+1);
        if(fscanf(stdin,"%d",&x)==0)
        {
            break;
        }
        if(i==0)
        {
            pS->pTop->n = x;
        }
        else
        {
            PNODE pTemp = (PNODE)malloc(sizeof(NODE));
            pTemp->n = x;
            pTemp->pNext = pS->pTop;
            pS->pTop = pTemp;
        }
    }
    printf("入栈结束！共输入%d个数据！\n",i);
}

void traverse(PSTACK pS) //遍历输出
{
    printf("------------------------------------------\n");
    printf("现在开始遍历输出！\n\n");
    int i=0;
    PNODE pTemp = pS->pTop;
    while(pTemp)
    {
        printf("第%d个数据：%d\n",++i,pTemp->n);
        pTemp = pTemp->pNext;
    }
    printf("出栈结束！共输出%d个数据！\n",i);
}

void pop(PSTACK pS)
{
    printf("------------------------------------------\n");
    printf("现在开始出栈！\n\n");
    if(pS->pTop)
    {
        PNODE pTemp = pS->pTop->pNext;
        printf("出栈数据：%d\n",pS->pTop->n);
        free(pS->pTop);
        pS->pTop = pTemp;
    }
}
void clear(PSTACK pS) //清空栈
{
    printf("------------------------------------------\n");
    printf("现在开始清空栈！\n\n");
    PNODE pTemp = NULL;
    do
    {
        pTemp = pS->pTop->pNext;
        free(pS->pTop);
        pS->pTop = pTemp;
    }while(pTemp);
    printf("清空完毕！\n");
}
int main(void)
{
    PSTACK pS;
    pS = init();
    push(pS);
    traverse(pS);
    pop(pS);
    clear(pS);
    traverse(pS);
    return 0;
}
