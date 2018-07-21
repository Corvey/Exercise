#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int x,i;
    /*******定义链表*********/
    struct data
    {
        int num;
        char ch;
    }temp;
    struct list
    {
        struct data Data;
        struct list *next;
    }*p_head=NULL,*p_tail=NULL,*p_temp=NULL,*p_max=NULL,*p_last=NULL;
    /*********创建链表并写入数据***********/
    printf("-----------------------------------------------------------\n");
    printf("现在开始写入数据，输入非数字则结束。\n\n");
    for(i=0;1;i++)
    {
        printf("请输入第%d个数据：",i+1);
        if(fscanf(stdin,"%d",&x) != 1)
        {
            break;
        }
        if(i==0)
        {
            p_head=(struct list *)malloc(sizeof(struct list));
            p_tail=p_head;
            p_head->Data.num=x;
            p_head->Data.ch=(char)x;
            p_head->next=NULL;
        }
        else
        {
            p_tail->next=(struct list *)malloc(sizeof(struct list));
            p_tail=p_tail->next;
            p_tail->Data.num=x;
            p_tail->Data.ch=(char)x;
            p_tail->next=NULL;
        }
    }
    printf("-----------------------------------------------------------\n");
    /*********遍历链表输出数据***********/
    printf("开始遍历链表输出数据:\n\n");
    p_tail=p_head;
    while(p_tail != NULL)
    {
        printf("num=%d,char=%c\n",p_tail->Data.num,p_tail->Data.ch);
        p_tail=p_tail->next;
    }
    printf("-----------------------------------------------------------\n");
    /*********遍历链表查找数据***********/
    printf("开始遍历链表查找数据！\n\n");
    printf("请输入你要查找的数据:");
    fflush(stdin);
    fscanf(stdin,"%d",&x);
    p_tail=p_head;
    while(p_tail!=NULL)
    {
        if(p_tail->Data.num==x)
        {
            printf("已找到！数据如下！\n");
            printf("num=%d,char=%c\n",p_tail->Data.num,p_tail->Data.ch);
            break;
        }
        p_tail=p_tail->next;
        if(p_tail==NULL)
        {
            printf("遍历链表仍未找到！\n");
        }
    }
    printf("-----------------------------------------------------------\n");
    /*********链表选择排序从大到小排序并输出*********/
    printf("现在开始排序！\n\n");
    p_tail=p_head;
    while(p_tail->next != NULL)
    {
        p_max=p_tail;
        p_temp=p_tail->next;
        while(p_temp != NULL)
        {
            if(p_temp->Data.num > p_max->Data.num)
            {
                p_max=p_temp;
            }
            p_temp = p_temp->next;
        }
        temp = p_tail->Data;
        p_tail->Data = p_max->Data;
        p_max->Data = temp;
        p_tail = p_tail->next;
    }
    p_tail=p_head;
    while(p_tail != NULL)
    {
        printf("num=%d\tchar=%c\n",p_tail->Data.num,p_tail->Data.ch);
        p_tail=p_tail->next;
    }
    printf("-----------------------------------------------------------\n");
    /*********删除节点*********/
    printf("现在开始删除节点测试！\n\n");
    printf("请输入你要删除的节点的数据：");
    fflush(stdin);
    fscanf(stdin,"%d",&x);
    p_tail = p_head;
    while(p_tail != NULL)
    {
        if(p_tail->Data.num == x)
        {
            printf("已找到相关数据：num=%d\tch=%c\n",p_tail->Data.num,p_tail->Data.ch);
            printf("开始删除！\n");
            if(p_tail == p_head)
            {
                p_tail = p_tail->next;
                free(p_head);
                p_head = p_tail;
            }
            else
            {
                p_tail = p_tail->next;
                free(p_last->next);
                p_last->next = p_tail;
            }
            printf("删除完成！\n");
            break;
        }
        p_last = p_tail;
        p_tail = p_tail->next;
        if(p_tail == NULL)
        {
            printf("没有找到相关数据！\n");
        }
    }
    p_tail=p_head;
    while(p_tail != NULL)
    {
        printf("num=%d,char=%c\n",p_tail->Data.num,p_tail->Data.ch);
        p_tail=p_tail->next;
    }
    printf("-----------------------------------------------------------\n");
    /*********有序插入节点*********/
    printf("现在开始插入节点测试！\n\n");
    printf("请输入你要插入的数据：");
    fflush(stdin);
    fscanf(stdin,"%d",&x);
    p_temp = (struct list *)malloc(sizeof(struct list));
    p_temp->Data.num = x;
    p_temp->Data.ch = (char)x;
    p_temp->next = NULL;
    printf("开始插入！\n");
    p_tail = p_head;
    while(p_tail != NULL)
    {
        if(x > p_tail->Data.num)
        {
            if(p_tail == p_head)
            {
                p_temp->next = p_head;
                p_head = p_temp;
            }
            else
            {
                p_temp->next = p_tail;
                p_last->next = p_temp;
            }
            printf("插入成功！\n");
            break;
        }
        else if(p_tail->next == NULL)
        {
            p_tail->next = p_temp;
            break;
        }
        p_last = p_tail;
        p_tail = p_tail->next;
    }
    p_tail=p_head;
    while(p_tail != NULL)
    {
        printf("num=%d,char=%c\n",p_tail->Data.num,p_tail->Data.ch);
        p_tail=p_tail->next;
    }
    printf("-----------------------------------------------------------\n");
    /***************删除链表*****************/
    printf("现在开始删除链表测试！\n\n");
    x=0;
    p_tail = p_head;
    while(p_tail != NULL)
    {
        p_last = p_tail;
        p_tail = p_tail->next;
        free(p_last);
        x++;
        printf("成功删除第%d个数据！\n",x);
    }
    printf("删除完毕！\n");
    printf("-----------------------------------------------------------\n");

    printf("恭喜你！链表已玩坏！\n");
}
