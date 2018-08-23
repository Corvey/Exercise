#include <stdio.h>
#include <stdlib.h>
#define N 6  //队列最大容量

typedef struct Queue
{
    int *pBase;
    int front;
    int rear;
}QUEUE,* PQUEUE;

void init(PQUEUE pQ)  //初始化
{
    printf("-------------------------------\n");
    printf("现在开始初始化队列！\n");
    pQ->pBase = (int *)malloc(sizeof(int)*(N+1));
    pQ->front = 0;
    pQ->rear = 0;
    printf("成功创建最大容量为%d的队列！\n",N);
}

int if_full(QUEUE Q) //队列是否满
{
    if( (Q.rear+1)%(N+1) == Q.front)
        return 1;
    else
        return 0;
}

int if_empty(QUEUE Q) //队列是否空
{
    if( Q.front == Q.rear )
        return 1;
    else
        return 0;
}

void enqueue(PQUEUE pQ)  //入队
{
    printf("-------------------------------\n");
    printf("现在开始入队！\n");
    int n, x;
    for(n=0;;n++)
    {
        if(if_full(*pQ))
        {
            printf("队列已满！\n");
            break;
        }
        printf("请输入第%d个数据：", n+1);
        fflush(stdin);
        if(fscanf(stdin, "%d", &x))
        {
            pQ->pBase[pQ->rear] = x;
            pQ->rear = (pQ->rear+1)%(N+1);
        }
        else
            break;
    }
    printf("入队结束！共输入%d个数据！\n", n);
}

void dequeue(PQUEUE pQ)  //出队
{
    printf("-------------------------------\n");
    printf("现在开始出队！\n");
    if(if_empty(*pQ))
    {
        printf("队列已空！\n");
        return ;
    }
    printf("出队数据为：%d\n", pQ->pBase[pQ->front]);
    pQ->front = (pQ->front+1) % (N+1);
}

void traverse(QUEUE Q)  //遍历输出
{
    printf("-------------------------------\n");
    printf("现在开始遍历输出！\n");

    if(if_empty(Q))
    {
        printf("队列已空！\n");
        return ;
    }

    for(int n=0; Q.front != Q.rear;)
    {
        printf("第%d个数据：%d\n", ++n, Q.pBase[Q.front]);
        Q.front = (Q.front+1) % (N+1);
    }
}

int main(void)
{
    QUEUE Q;
    init(&Q);  //初始化队列
    enqueue(&Q); //入队
    traverse(Q); //遍历输出
    dequeue(&Q); //出队
    traverse(Q); //遍历输出
}
