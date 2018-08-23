#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct data
{
    int num;
    char ch;
};
struct list
{
    struct data Data;
    struct list *pNext;
};
typedef struct list List;

List* Creat(void)//创建
{
    List *pHead = NULL, *pTail = NULL;
    int x;
    printf("------------------------------------------------\n");
    printf("现在开始创建链表！\n");
    for(int i=0; ; i++)
    {
        printf("请输入第%d个数据：", i+1);
        fflush(stdin);
        if(fscanf(stdin,"%d",&x) != 0)
        {
            if(i == 0)
            {
                pHead = (List *)malloc(sizeof(List));
                if(pHead == NULL)
                {
                    printf("分配内存失败！按任意键退出。。。\n");
                    getch();
                    exit(-1);
                }
                pTail = pHead;
                pTail->Data.num = x;
                pTail->Data.ch = (char)x;
                pTail->pNext = NULL;
            }
            else
            {
                pTail->pNext = (List *)malloc(sizeof(List));
                if(pTail == NULL)
                {
                    printf("分配内存失败！按任意键退出。。。\n");
                    getch();
                    exit(-1);
                }
                pTail = pTail->pNext;
                pTail->Data.num = x;
                pTail->Data.ch = (char)x;
                pTail->pNext = NULL;
            }
        }
        else
        {
            printf("输入结束，共输入%d个数据！\n", i);
            break;
        }
    }
    return pHead;
}
void show(List *pHead)//遍历输出
{
    printf("------------------------------------------------\n");
    printf("现在开始遍历链表输出！\n");
    for(int i=0; pHead != NULL; i++)
    {
        printf("第%d个数据：num=%d\tch=%c\n", i+1, pHead->Data.num, pHead->Data.ch);
        pHead = pHead->pNext;
    }
}
int length(List* pHead)//求长度
{
    int length;
    printf("------------------------------------------------\n");
    printf("现在开始求该链表长度！\n");
    for(length=0; pHead != NULL; length++)
    {
        pHead = pHead->pNext;
    }
    printf("该链表的长度为：%d\n",length);
    return length;
}
void insert(List **pHead)//插入
{
    int n;
    List *pTail = *pHead;
    List *pTemp = (List *)malloc(sizeof(List));
    if(pTemp == NULL)
    {
        printf("分配内存失败！按任意键退出。。。\n");
        getch();
        exit(-1);
    }
    printf("------------------------------------------------\n");
    printf("现在开始往链表中插入数据！\n");
    printf("请输入你要插入的位置：");
    fflush(stdin);
    fscanf(stdin,"%d", &n);
    printf("请输入你要插入的数据：");
    fflush(stdin);
    fscanf(stdin,"%d", &pTemp->Data.num);
    pTemp->Data.ch = (char)pTemp->Data.num;
    pTemp->pNext = NULL;
    for(int i=0; i<n-2; i++)
    {
        if(pTail->pNext == NULL)
            break;
        pTail = pTail->pNext;
    }
    if(n==1)
    {
        pTemp->pNext = *pHead;
        *pHead = pTemp;
    }
    else
    {
        pTemp->pNext = pTail->pNext;
        pTail->pNext = pTemp;
    }
    show(*pHead);
}
void Delete(List **pHead)//删除
{
    int n;
    List *pTail = *pHead, *pTemp = NULL;
    printf("------------------------------------------------\n");
    printf("现在开始删除结点。\n");
    printf("请输入你要删除的结点位置：");
    fflush(stdin);
    fscanf(stdin,"%d", &n);
    for(int i=0; i<n-2; i++)
    {
        pTail = pTail->pNext;
        if(pTail->pNext == NULL)
            break;
    }
    if(n==1)
    {
        pTemp = *pHead;
        *pHead = (*pHead)->pNext;
        memset(pTemp, 0, sizeof(List));
        free(pTemp);
    }
    else
    {
        pTemp = pTail->pNext;
        pTail->pNext = pTail->pNext->pNext;
        memset(pTemp, 0, sizeof(List));
        free(pTemp);
    }
    show(*pHead);
}
void destroy(List **pHead)//销毁
{
    List *pTail = *pHead, *pTemp = NULL;
    printf("------------------------------------------------\n");
    printf("现在开始销毁链表！\n");
    while(pTemp != NULL)
    {
        pTemp = pTail;
        pTail = pTail->pNext;
        memset(pTemp, 0, sizeof(List));
        free(pTemp);
    }
    *pHead = NULL;
}
void sort(List *pHead)//排序
{
    List *pTemp = NULL, *pMin = NULL;
    struct data temp;
    printf("------------------------------------------------\n");
    printf("现在开始排序。\n");
    while(pHead->pNext != NULL)
    {
        pTemp = pHead->pNext;
        pMin = pHead;
        while(pTemp != NULL)
        {
            if(pMin->Data.num >pTemp->Data.num)
            {
                pMin = pTemp;
            }
            pTemp = pTemp->pNext;
        }
        temp = pHead->Data;
        pHead->Data = pMin->Data;
        pMin->Data = temp;
        pHead = pHead->pNext;
    }
}
void inversion(List **pHead)//倒置
{
    List *pTail, *pTemp;
    printf("------------------------------------------------\n");
    printf("现在开始倒置链表。\n");
    pTail = (*pHead)->pNext;
    (*pHead)->pNext = NULL;
    while(pTail)
    {
        pTemp = pTail;
        pTail = pTail->pNext;
        pTemp->pNext = *pHead;
        *pHead = pTemp;
    }
}
int main(void)
{
    List *pHead = NULL;
    pHead = Creat();
    show(pHead);
    length(pHead);
    insert(&pHead);
    Delete(&pHead);
    sort(pHead);
    show(pHead);
    inversion(&pHead);
    show(pHead);
    destroy(&pHead);
    show(pHead);
    printf("\n\n已玩坏！\n");
    return 0;
}
