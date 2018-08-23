/************************************
   树           A
             ↙   ↘
            B       C
             ↘   ↙
              D   F
            ↙  ↙ ↘
           E   G     H
************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    char name;
    struct tree *pLchild;
    struct tree *pRchild;
}TREE, *PTREE;

PTREE init(void)
{
    PTREE pA = (PTREE)malloc(sizeof(TREE));
    pA->name = 'A';
    PTREE pB = (PTREE)malloc(sizeof(TREE));
    pB->name = 'B';
    PTREE pC = (PTREE)malloc(sizeof(TREE));
    pC->name = 'C';
    PTREE pD = (PTREE)malloc(sizeof(TREE));
    pD->name = 'D';
    PTREE pE = (PTREE)malloc(sizeof(TREE));
    pE->name = 'E';
    PTREE pF = (PTREE)malloc(sizeof(TREE));
    pF->name = 'F';
    PTREE pG = (PTREE)malloc(sizeof(TREE));
    pG->name = 'G';
    PTREE pH = (PTREE)malloc(sizeof(TREE));
    pH->name = 'H';

    pA->pLchild = pB;
    pA->pRchild = pC;
    pB->pLchild = NULL;
    pB->pRchild = pD;
    pD->pLchild = pE;
    pD->pRchild = NULL;
    pE->pLchild = NULL;
    pE->pRchild = NULL;
    pC->pLchild = pF;
    pC->pRchild = NULL;
    pF->pLchild = pG;
    pF->pRchild = pH;
    pG->pLchild = NULL;
    pG->pRchild = NULL;
    pH->pLchild = NULL;
    pH->pRchild = NULL;

    return pA;
}

void first(PTREE pT)
{
    printf("%c", pT->name);

    if(pT->pLchild)
        first(pT->pLchild);
    if(pT->pRchild)
        first(pT->pRchild);
}

void mid(PTREE pT)
{
    if(pT->pLchild)
        mid(pT->pLchild);

    printf("%c", pT->name);

    if(pT->pRchild)
        mid(pT->pRchild);
}

void behind(PTREE pT)
{
    if(pT->pLchild)
        behind(pT->pLchild);
    if(pT->pRchild)
        behind(pT->pRchild);

    printf("%c", pT->name);
}

int main(void)
{
    PTREE pRoot = NULL;
    pRoot = init();
    printf("先序输出：");
    first(pRoot);
    printf("\n");
    printf("中序输出：");
    mid(pRoot);
    printf("\n");
    printf("后序输出：");
    behind(pRoot);
    printf("\n");
}
