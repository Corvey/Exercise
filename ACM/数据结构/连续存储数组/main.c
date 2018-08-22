#include <stdio.h>
#include <stdlib.h>
struct list
{
    int * pbase;
    int max;
    int have;
};
int main(void)
{
    struct list arr;
    creat_arr(&arr);
    init_arr(&arr);
    append_arr(&arr);
    show_arr(arr);
    insert_arr(&arr);
    show_arr(arr);
    sort_arr(&arr);
    inversion_arr(&arr);
    delete_arr(&arr);
    printf("\n\n已玩坏！\n");
}
void creat_arr(struct list * p) //创建
{
    int max;
    printf("-----------------------------------------------\n");
    printf("现在开始创建数组！\n");
    printf("请输入数组的最大元素个数：");
    fflush(stdin);
    fscanf(stdin, "%d", &max);
    p->pbase = (int *)malloc(sizeof(int) * max);

    if(p->pbase == NULL)
    {
        printf("申请内存失败！按任意键后退出。。。\n");
        getch();
        exit(-1);
    }

    p->max = max;
    p->have = 0;
    printf("创建数组完毕！\n");
}
void init_arr(struct list * p) //初始化
{
    int i, x;
    printf("-----------------------------------------------\n");
    printf("现在开始初始化数据，输入非数字以结束！\n");

    for(i = 0;; i++)
    {
        printf("请输入第%d个数据：", i + 1);
        fflush(stdin);

        if(fscanf(stdin, "%d", &x) != 0)
        {
            p->have++;
            p->pbase[i] = x;

            if(p->have == p->max)
            {
                printf("数组已满！输入自动结束！\n");
                i++;
                break;
            }
        }
        else
        {
            break;
        }
    }

    printf("输入结束，共录入%d个数据！\n", i);
}
void show_arr(struct list arr)//打印
{
    printf("-----------------------------------------------\n");
    printf("现在开始打印数组！\n");

    for(int i = 0; i < arr.have; i++)
    {
        printf("第%d个数据：%d\n", i + 1, arr.pbase[i]);
    }
}
void append_arr(struct list * p) //追加
{
    int i, x;
    printf("-----------------------------------------------\n");
    printf("现在开始追加数据！输入非数字结束！\n");

    for(i = p->have;; i++)
    {
        if(p->have == p->max)
        {
            printf("数组已满！输入自动结束！\n");
            break;
        }

        printf("请输入第%d个数据：", i + 1);
        fflush(stdin);

        if(fscanf(stdin, "%d", &x) != 0)
        {
            p->have++;
            p->pbase[i] = x;
        }
        else
        {
            break;
        }
    }

    printf("输入结束，共输入%d个数据！\n", i);
}
void insert_arr(struct list * p) //插入
{
    int i, n;
    printf("-----------------------------------------------\n");
    printf("现在开始插入数据。\n");

    if(p->have == p->max)
    {
        printf("数组已满，无法再插入！\n");
        return ;
    }

    while(1)
    {
        printf("请输入你要插入的位置：");
        fflush(stdin);
        fscanf(stdin, "%d", &n);

        if(n >= p->max || n > p->have + 1 || n<=0 )
        {
            printf("输入有误，请重新输入！\n", p->max);
        }
        else
        {
            break;
        }
    }

    p->have++;

    for(i = p->have-1; i >= n - 1; i--)
    {
        p->pbase[i] = p->pbase[i - 1];
    }

    printf("请输入你要插入的数据：");
    fflush(stdin);
    fscanf(stdin, "%d", &p->pbase[n - 1]);
}
void sort_arr(struct list * p) //排序
{
    int temp, exchange;
    printf("-----------------------------------------------\n");
    printf("现在开始排序。\n");

    for(int i = 0; i < p->have - 1; i++)
    {
        exchange = 0;

        for(int j = 0; j < p->have - i - 1; j++)
        {
            if(p->pbase[j] < p->pbase[j + 1])
            {
                temp = p->pbase[j];
                p->pbase[j] = p->pbase[j + 1];
                p->pbase[j + 1] = temp;
                exchange++;
            }
        }

        if(exchange == 0)
        {
            break;
        }
    }

    printf("排序完毕。\n");
    show_arr(*p);
}
void inversion_arr(struct list * p) //倒置
{
    int l = 0, r = p->have - 1, temp;
    printf("-----------------------------------------------\n");
    printf("现在开始倒置。\n");

    for(; l != p->have / 2; l++, r--)
    {
        temp = p->pbase[l];
        p->pbase[l] = p->pbase[r];
        p->pbase[r] = temp;
    }
    printf("倒置完毕。\n");
    show_arr(*p);
}
void delete_arr(struct list * p) //删除
{
    int n;
    printf("-----------------------------------------------\n");
    printf("现在开始删除。\n");
    while(1)
    {
        printf("请输入你要删除的元素：");
        fflush(stdin);
        fscanf(stdin, "%d", &n);
        if(n<0||n>=p->have)
        {
            printf("输入有误，请重新输入！\n");
        }
        else
        {
            break;
        }
    }

    p->have--;
    for(int i=n-1; i < p->have; i++)
    {
        p->pbase[i] = p->pbase[i+1];
    }
    printf("删除成功！\n");
    show_arr(*p);
}







