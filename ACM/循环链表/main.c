#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *pNext;
}NODE, *PNODE;

PNODE CreatCLList(void)//建立循环链表
{
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    pHead->pNext = NULL;
    PNODE pRear = pHead;
    system("cls");
    printf("以下为“建立循环链表”：\n\n");
    int data;
    for(int i=1; ; ++i)
    {
        printf("请输入第%d个结点的数据(输入0以结束)：", i);
        scanf("%d", &data);
        if(!data)
            break;
        pRear->pNext = (PNODE)malloc(sizeof(NODE));
        pRear = pRear->pNext;
        pRear->num = data;
        pRear->pNext = NULL;
    }
    pRear->pNext = pHead->pNext;
    printf("\n循环链表建立完成!\n\n循环链表数据如下：\n");
    PrintfCLList(pHead);
    return pHead;
}

void PrintfCLList(PNODE pHead)
{
    PNODE pTemp = pHead->pNext;
    for(int i=1; ; ++i)
    {
        printf("第%d个结点：%d\n", i, pTemp->num);
        if(pTemp->pNext == pHead->pNext)
            break;
        else
            pTemp = pTemp->pNext;
    }
}

void InsertCLList(PNODE pHead)//插入
{
    int n, data;
    printf("\n以下测试“插入”功能：\n\n");
    printf("请输入要插入的位置及数据：");
    scanf("%d%d", &n, &data);
    if(n==1)
    {
        PNODE pRear = pHead->pNext;
        while(pRear->pNext != pHead->pNext)
            pRear = pRear->pNext;
        PNODE pTemp = pHead->pNext;
        pHead->pNext = (PNODE)malloc(sizeof(NODE));
        pHead->pNext->num = data;
        pHead->pNext->pNext = pTemp;
        pRear->pNext = pHead->pNext;
    }
    else
    {
        PNODE pTail = pHead;
        for(int i=1; i<n; ++i)
            pTail = pTail->pNext;
        PNODE pTemp = pTail->pNext;
        pTail->pNext = (PNODE)malloc(sizeof(NODE));
        pTail = pTail->pNext;
        pTail->num = data;
        pTail->pNext = pTemp;
    }
    printf("\n插入完成!\n\n循环链表数据如下：\n");
    PrintfCLList(pHead);
}

void DelCLList(PNODE pHead)//删除
{
    int n;
    printf("\n以下测试“删除”功能：\n\n");
    printf("请输入要删除的位置：");
    scanf("%d", &n);
    if(n==1)
    {
        PNODE pRear = pHead->pNext;
        while(pRear->pNext != pHead->pNext)
            pRear = pRear->pNext;
        PNODE pTemp = pHead->pNext->pNext;
        free(pHead->pNext);
        pHead->pNext = pTemp;
        pRear->pNext = pHead->pNext;
    }
    else
    {
        PNODE pTail = pHead;
        for(int i=1; i<n; ++i)
            pTail = pTail->pNext;
        PNODE pTemp = pTail->pNext->pNext;
        free(pTail->pNext);
        pTail->pNext = pTemp;
    }
    printf("\n删除完成!\n\n循环链表数据如下：\n");
    PrintfCLList(pHead);

}

int main(void)
{
    PNODE pHead = CreatCLList();//建立循环链表
    InsertCLList(pHead);//插入
    DelCLList(pHead);//删除
    return 0;
}
