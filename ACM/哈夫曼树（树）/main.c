#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *pNext;
}NODE, *PNODE;

typedef struct HuffmanTree  //哈夫曼树
{
    int num;
    struct HuffmanTree *pLeft;
    struct HuffmanTree *pRight;
}HTREE, *PHTREE;

typedef struct qnode
{
    struct HuffmanTree *pT;
    struct qnode *pNext;
}QNODE, *PQNODE;

typedef struct queue
{
    struct qnode *pFront;
    struct qnode *pRear;
}QUEUE, *PQUEUE;

void InitQueue(PQUEUE *pQ) //初始化队列
{
    *pQ = (PQUEUE)malloc(sizeof(QUEUE));
    (*pQ)->pRear = (PQNODE)malloc(sizeof(QNODE));
    (*pQ)->pRear->pNext = NULL;
    (*pQ)->pFront = (*pQ)->pRear;
}

void EnQueue(PQUEUE pQ, PHTREE p)  //入队
{
    pQ->pRear->pNext = (PQNODE)malloc(sizeof(QNODE));
    pQ->pRear = pQ->pRear->pNext;
    pQ->pRear->pT = p;
    pQ->pRear->pNext = NULL;
}

PHTREE DeQueue(PQUEUE pQ)  //出队
{
    PNODE pTemp = pQ->pFront->pNext->pNext;
    PHTREE p = pQ->pFront->pNext->pT;
    free(pQ->pFront->pNext);
    pQ->pFront->pNext = pTemp;
    return p;
}

int CountQueue(PQUEUE pQ) //计算队列元素个数
{
    int n=0;
    PQNODE pTemp = pQ->pFront->pNext;
    while(pTemp)
    {
        ++n;
        pTemp = pTemp->pNext;
    }
    return n;
}

PHTREE CreatHTree(PQUEUE pQ)   //创建哈夫曼树
{
    PHTREE p, a, b;
    PQNODE pQTemp = NULL;
    while(pQ->pFront->pNext->pNext)
    {
        p = (PHTREE)malloc(sizeof(HTREE));
        a = DeQueue(pQ);
        b = DeQueue(pQ);
        p->num = a->num + b->num;
        p->pLeft = a;
        p->pRight = b;
        if(CountQueue(pQ) >= 2 && p->num > pQ->pFront->pNext->pT->num && p->num > pQ->pFront->pNext->pNext->pT->num)
            EnQueue(pQ, p);
        else
        {
            PQNODE pQ = (PQNODE)malloc(sizeof(QNODE));
            pQTemp = pQ->pFront->pNext->pNext;
            while(pQTemp->pNext)
            {
                if(p->num < pQTemp->pNext->pT->num)
                    break;
                pQTemp = pQTemp->pNext;
            }
            pQ->pNext = pQ->pFront->pNext;
            pQ->pT = p;
            pQ->pFront->pNext = pQ;
        }
    }
    return DeQueue(pQ);
}

void PreorderTraversal(PHTREE p)  //先序遍历
{
    printf("%d ", p->num);
    if(p->pLeft)
        PreorderTraversal(p->pLeft);
    if(p->pRight)
        PreorderTraversal(p->pRight);
}

void InorderTraversal(PHTREE p)   //中序遍历
{
    if(p->pLeft)
        InorderTraversal(p->pLeft);
    printf("%d ", p->num);
    if(p->pRight)
        InorderTraversal(p->pRight);
}

void PostorderTraversal(PHTREE p)   //后序遍历
{
    if(p->pLeft)
        PostorderTraversal(p->pLeft);
    if(p->pRight)
        PostorderTraversal(p->pRight);
    printf("%d ", p->num);
}

void Sort(PNODE pLHead, PQUEUE pQ)      //将链表数据从小到大入队
{
    while(pLHead->pNext)
    {
        int min = pLHead->pNext->num;
        PNODE pTemp = pLHead->pNext->pNext;
        free(pLHead->pNext);
        pLHead->pNext = pTemp;
        pTemp = pLHead->pNext;
        while(pTemp)
        {
            if(min > pTemp->num)
            {
                int temp = min;
                min = pTemp->num;
                pTemp->num = temp;
            }
            pTemp = pTemp->pNext;
        }
        PHTREE pT = (PHTREE)malloc(sizeof(HTREE));
        pT->num = min;
        pT->pLeft = NULL;
        pT->pRight = NULL;
        EnQueue(pQ, pT);
    }
    free(pLHead);
}

int main(void)
{
    PNODE pLHead = (PNODE)malloc(sizeof(NODE));
    PNODE pLTail = pLHead;
    printf("请输入数据，输入0以结束：");
    while(1)
    {
        int x;
        scanf("%d", &x);
        if(!x)
            break;
        else
        {
            pLTail->pNext = (PNODE)malloc(sizeof(NODE));
            pLTail = pLTail->pNext;
            pLTail->num = x;
            pLTail->pNext = NULL;
        }
    }
    PQUEUE pQ = NULL;
    InitQueue(&pQ);
    Sort(pLHead, pQ);   //将链表数据从小到大入队

    /*  输出队列检查
    printf("节点个数：%d\n", CountQueue(pQ));
    while(pQ->pFront->pNext)
    {
        printf("%d ", pQ->pFront->pNext->pT->num);
        pQ->pFront->pNext = pQ->pFront->pNext->pNext;
    }
    exit(0);
    */

    PHTREE pHTHead = CreatHTree(pQ);

    printf("\n先序遍历：");
    PreorderTraversal(pHTHead);
    printf("\n");

    printf("中序遍历：");
    InorderTraversal(pHTHead);
    printf("\n");

    printf("后序遍历：");
    PostorderTraversal(pHTHead);
    printf("\n");

}
