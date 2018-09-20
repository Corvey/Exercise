#include <stdio.h>
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

void InitStack(PSTACK *pS)
{
    *pS = (PSTACK)malloc(sizeof(STACK));
    (*pS)->pBottom = (PNODE)malloc(sizeof(NODE));
    (*pS)->pBottom->pNext = NULL;
    (*pS)->pHead = (*pS)->pBottom;
}
void Push(PSTACK pS, char ch)
{
    PNODE p = (PNODE)malloc(sizeof(NODE));
    p->ch = ch;
    p->pNext = pS->pHead;
    pS->pHead = p;
}
int Pop(PSTACK pS)
{
    if(!pS->pHead->pNext)
        return 0;
    PNODE p = pS->pHead->pNext;
    free(pS->pHead);
    pS->pHead = p;
}
void Destroy(PSTACK pS)
{
    PNODE p = NULL;
    while(pS->pHead->pNext)
    {
        p = pS->pHead->pNext;
        free(pS->pHead);
        pS->pHead = p;
    }
    free(pS->pHead);
    free(pS);
}
int main(void)
{
    int n;
    char s[10001];
    PSTACK pS;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        InitStack(&pS);
        scanf("%s", s);
        for(int j=0; s[j]; ++j)
        {
            if(s[j] == '[' || s[j] == '(')
                Push(pS, s[j]);
            else
            {
                if(!pS->pHead->pNext)
                {
                    Push(pS, 1);
                    break;
                }
                if(s[j] == ')')
                {
                    if(pS->pHead->ch == '(')
                        Pop(pS);
                    else
                        break;
                }
                else if(s[j] == ']')
                {
                    if(pS->pHead->ch == '[')
                        Pop(pS);
                    else
                        break;
                }
            }
        }
        if(pS->pHead->pNext)
            printf("No\n");
        else
        {
            printf("Yes\n");
            Destroy(pS);
        }
    }

}
