/*******************************************
    树
                A
             ↙   ↘
            B       C
             ↘   ↙
              D   F
            ↙  ↙ ↘
           E   G     H    AB0DE000CFG00H000

    先序遍历：ABDECFGH
    中序遍历：BEDAGFHC
    后序遍历：EDBGHFCA
*******************************************/
#include <stdio.h>
#include <stdlib.h>
typedef char Elemtype;
typedef enum {Link, Thread} PointerTag;
typedef struct TBiTree
{
    Elemtype name;
    struct TBiTree *pLchild, *pRchild;
    PointerTag pLtag, pRtag;
}TBITREE, *PTBITREE;

void CreatTree(PTBITREE *pT) //创建树
{
    char c;
    scanf("%c", &c);
    if(c != '0')
    {
        *pT = (PTBITREE)malloc( sizeof(TBITREE) );
        (*pT)->name = c;
        (*pT)->pLtag = (*pT)->pRtag = Link;
        CreatTree(&(*pT)->pLchild);
        CreatTree(&(*pT)->pRchild);
    }
    else
    {
        *pT = NULL;
    }
}

void FirstTraverse(PTBITREE pT) //先序遍历
{
    printf("%c", pT->name);
    if(pT->pLchild)
    {
        FirstTraverse(pT->pLchild);
    }
    if(pT->pRchild)
    {
        FirstTraverse(pT->pRchild);
    }
}

void MidTraverse(PTBITREE pT)  //中序遍历
{
    if(pT->pLchild)
    {
        MidTraverse(pT->pLchild);
    }
    printf("%c", pT->name);
    if(pT->pRchild)
    {
        MidTraverse(pT->pRchild);
    }
}

void BehindTraverse(PTBITREE pT)  //后序遍历
{
    if(pT->pLchild)
    {
        BehindTraverse(pT->pLchild);
    }
    if(pT->pRchild)
    {
        BehindTraverse(pT->pRchild);
    }
    printf("%c", pT->name);
}

void InThreading(PTBITREE pT) //树线索化
{
    if(pT)
    {
        InThreading(pT->pLchild);
        if(!pT->pLchild)
        {
            pT->pLtag = Thread;
            pT->pLchild = NULL;
        }
        PTBITREE pPre = pT;
        InThreading(pT->pRchild);
        if(!pT->pRchild)
        {
            pT->pRtag = Thread;
            pT->pRchild = ;
        }
    }
}

int main(void)
{
    PTBITREE pT;
    printf("请按先序遍历输入树的结点：");
    CreatTree(&pT);

    printf("先序遍历：");
    FirstTraverse(pT);
    printf("\n");

    printf("中序遍历：");
    MidTraverse(pT);
    printf("\n");

    printf("后序遍历：");
    BehindTraverse(pT);

    InThreading(pT);
    printf("\n");
}
