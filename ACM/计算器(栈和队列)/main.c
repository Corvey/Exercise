#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 10  //单个数据最大位数（含小数点）

typedef enum {NUM, SIGN} DataType;
typedef struct node
{
    DataType Tag;
    double Data;
    struct node *pNext;
}NODE, *PNODE;

typedef struct stack
{
    struct node *pTop;
    struct node *pBottom;
}STACK, *PSTACK;

typedef struct queue
{
    struct node *pFront;
    struct node *pRear;
}QUEUE, *PQUEUE;

void InitStack(PSTACK *pS)//初始化栈
{
    *pS = (PSTACK)malloc(sizeof(STACK));
    (*pS)->pBottom = (PNODE)malloc(sizeof(NODE));
    (*pS)->pBottom->pNext = NULL;
    (*pS)->pTop = (*pS)->pBottom;
}

void Push(PSTACK pS, double data)//入栈
{
    PNODE pTemp = (PNODE)malloc(sizeof(NODE));
    pTemp->Data = data;
    pTemp->pNext = pS->pTop;
    pS->pTop = pTemp;
}

double Pop(PSTACK pS)//出栈
{
    PNODE pTemp = pS->pTop->pNext;
    double x = pS->pTop->Data;
    free(pS->pTop);
    pS->pTop = pTemp;
    return x;
}

void InitQueue(PQUEUE *pQ)//初始化队列
{
    *pQ = (PQUEUE)malloc(sizeof(QUEUE));
    (*pQ)->pRear = (PNODE)malloc(sizeof(NODE));
    (*pQ)->pRear->pNext = NULL;
    (*pQ)->pFront = (*pQ)->pRear;
}

void EnQueue(PQUEUE pQ, DataType tag, double data)//入队
{
    pQ->pRear->pNext = (PNODE)malloc(sizeof(NODE));
    pQ->pRear = pQ->pRear->pNext;
    pQ->pRear->pNext = NULL;
    pQ->pRear->Tag = tag;
    pQ->pRear->Data = data;
}

double DeQueue(PQUEUE pQ)//出队
{
    PNODE pTemp = pQ->pFront->pNext->pNext;
    double x = pQ->pFront->pNext->Data;
    free(pQ->pFront->pNext);
    pQ->pFront->pNext = pTemp;
    return x;
}

void Print(PNODE pTemp)//打印队列
{
    while(pTemp)
    {
        if(pTemp->Tag == NUM)
            printf("%g ", pTemp->Data);
        else if(pTemp->Tag == SIGN)
            printf("%c ", (char)pTemp->Data);
        pTemp = pTemp->pNext;
    }
    printf("\n");
}

int main(void)
{
    char c, n[MAX]; //n[]储存单个数据

    PQUEUE pQ;
    InitQueue(&pQ);

    PSTACK pNum, pSign;
    InitStack(&pNum);
    InitStack(&pSign);

    printf("请输入要计算的式子：");
    while(1)
    {
        scanf("%c", &c);
        if( isdigit(c) || c == '.' )
        {
            n[0] = c;
            for(int i=1;; ++i)
            {
                if(i == MAX)
                {
                    printf("单个数据长度超出最大值！\n");
                    exit(0);
                }
                scanf("%c", &c);
                if( isdigit(c) || c == '.' )
                {
                    n[i] = c;
                }
                else
                {
                    n[i] = '\0';
                    EnQueue(pQ, NUM, atof(n));
                    memset(n, '\0', sizeof(n[MAX]));
                    break;
                }
            }
        }
        switch (c)
        {
        case '(':
            Push(pSign, c);
            break;
        case '*':
        case '/':
            while(pSign->pTop->Data == '*' || pSign->pTop->Data == '/')
                EnQueue(pQ, SIGN, Pop(pSign));
            Push(pSign, c);
            break;
        case '+':
        case '-':
            if(pSign->pTop == pSign->pBottom)
                Push(pSign, c);
            else
            {
                if(pSign->pTop->Data == '*' || pSign->pTop->Data == '/')
                {
                    do
                    {
                        EnQueue(pQ, SIGN, Pop(pSign));

                    } while(pSign->pTop->Data != '(' && pSign->pTop != pSign->pBottom);
                }
                Push(pSign, c);
            }
            break;
        case ')':
            do
            {
                EnQueue(pQ, SIGN, Pop(pSign));

            }while(pSign->pTop->Data != '(');
            Pop(pSign);
            break;

        case '\n':
            break;

        default:
            printf("表达式中出现奇怪的符号，系统无法识别！\n");
            exit(0);
        }
        if( c == '\n')
            break;
    }

    while(pSign->pTop != pSign->pBottom)
        EnQueue(pQ, SIGN, Pop(pSign));

    //printf("后缀表达式：");
    //Print(pQ->pFront->pNext);

    while(pQ->pFront->pNext)
    {
        if(pQ->pFront->pNext->Tag == NUM)
            Push(pNum, DeQueue(pQ));
        else if(pQ->pFront->pNext->Tag == SIGN)
        {
            switch ((char)DeQueue(pQ))
            {
            case '+':
                Push(pNum, Pop(pNum)+Pop(pNum));
                break;

            case '-':
            {
                double x = Pop(pNum);
                Push(pNum, Pop(pNum)-x);
                break;
            }
            case '*':
                Push(pNum, Pop(pNum)*Pop(pNum));
                break;

            case '/':
            {
                if(!pNum->pTop->Data)
                {
                    printf("除数不能为0！\n");
                    exit(0);
                }
                double x = Pop(pNum);
                Push(pNum, Pop(pNum)/x);
                break;
            }
            default:
                break;
            }
        }
    }
    printf("结果为：%g\n", Pop(pNum));
    return 0;
}
