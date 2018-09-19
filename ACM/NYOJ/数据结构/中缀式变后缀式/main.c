#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char ch;
    struct node *pNext;
}NODE, *PNODE;

typedef struct stack
{
    struct node *pHead;
    struct node *pBottom;
}STACK, *PSTACK;

PSTACK InitStack(void)
{
    PSTACK pS = (PSTACK)malloc(sizeof(STACK));
    pS->pBottom = NULL;
    pS->pHead = pS->pBottom;
    return pS;
}

void Push(PSTACK pS, char ch)
{
    PNODE p = (PNODE)malloc(sizeof(NODE));
    p->ch = ch;
    p->pNext = pS->pHead;
    pS->pHead = p;
}

void Pop(PSTACK pS)
{
    PNODE p = pS->pHead->pNext;
    free(pS->pHead);
    pS->pHead = p;
}

void DelStack(PSTACK pS)
{
    PNODE p = NULL;
    while(pS->pHead)
        Pop(pS);
}

int main(void)
{
    int n;
    char ch;
    PSTACK pS = NULL;
    scanf("%d", &n);
    getchar();
    for(int i=0; i<n; ++i)
    {
        pS = InitStack();
        while(1)
        {
            scanf("%c", &ch);
            if(ch >= '0' && ch <= '9' || ch == '.')
                printf("%c", ch);
            else  if(ch == '*' || ch == '/')
            {
                printf(" ");
                Push(pS, ch);
            }
            else if(ch == '+' || ch == '-')
            {
                printf(" ");
                if(pS->pHead)
                {
                    while(pS->pHead->ch == '*' || pS->pHead->ch == '/')
                    {
                        printf("%c ", pS->pHead->ch);
                        Pop(pS);
                    }
                }
                Push(pS, ch);
            }
            else if(ch == '(')
                Push(pS, ch);
            else if(ch == ')')
            {
                if(pS->pHead)
                {
                    while(pS->pHead->ch != '(')
                    {
                        printf(" %c", pS->pHead->ch);
                        Pop(pS);
                    }
                }
                Pop(pS);
            }
            else if(ch == '=')
            {
                getchar();
                if(pS->pHead)
                {
                    while(pS->pHead)
                    {
                        printf(" %c", pS->pHead->ch);
                        Pop(pS);
                    }
                    printf(" =\n");
                }
                else
                    printf(" =\n");
                DelStack(pS);
                free(pS);
                pS = NULL;
                break;
            }
        }
    }
}
