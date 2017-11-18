#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *pPre, *pNext;
}NODE, *PNODE;

PNODE CreatDULList(void)//建立双向链表
{
    system("cls");
    printf("以下为“建立双向链表”：\n\n");
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    pHead->pNext = NULL;
    pHead->pPre = NULL;
    PNODE pTail = pHead;
    int data;
    for(int i=1; ; ++i)
    {
        printf("请输入第%d个结点的数据（输入0以结束）：", i);
        scanf("%d", &data);
        if(!data)
            break;
        pTail->pNext = (PNODE)malloc(sizeof(NODE));
        pTail->pNext->pPre = pTail;
        pTail->pNext->num = data;
        pTail->pNext->pNext = NULL;
        pTail = pTail->pNext;
    }
    printf("双向链表建立完成！\n\n以下为双向链表数据：\n");
    PrintfDULList(pHead);
    return pHead;
}

void PrintfDULList(PNODE pHead)//遍历输出
{
    PNODE pTail = pHead->pNext;
    for(int i=1; pTail; ++i)
    {
        printf("第%d个结点的数据：%d\n", i, pTail->num);
        pTail = pTail->pNext;
    }
}

void InsertDULList(PNODE pHead)//插入
{
    int n, data;
    printf("\n以下测试“插入”功能：\n\n");
    printf("请输入要插入的位置及数据：");
    scanf("%d%d", &n, &data);
    PNODE pTail = pHead;
    for(int i=1; i<n; ++i)
        pTail = pTail->pNext;
    PNODE pTemp = pTail->pNext;
    pTail->pNext = (PNODE)malloc(sizeof(NODE));
    pTail->pNext->pPre = pTail;
    pTail->pNext->num = data;
    pTail->pNext->pNext = pTemp;
    if(pTemp)
        pTemp->pPre = pTail->pNext;
    printf("插入完成！\n\n以下为双向链表数据：\n");
    PrintfDULList(pHead);
}

void DelDULList(PNODE pHead)//删除
{
    int n;
    printf("\n以下测试“删除功能”：\n\n");
    printf("请输入要删除的位置：");
    scanf("%d", &n);
    PNODE pTail = pHead;
    for(int i=1; i<n; ++i)
        pTail = pTail->pNext;
    PNODE pTemp = pTail->pNext;
    pTail->pNext = pTemp->pNext;
    if(pTemp->pNext)
        pTemp->pNext->pPre = pTail;
    free(pTemp);
    printf("插入完成！\n\n以下为双向链表数据：\n");
    PrintfDULList(pHead);
}

int main(void)
{
    PNODE pHead = CreatDULList();//建立双向链表
    InsertDULList(pHead);//插入
    DelDULList(pHead);//删除
}
