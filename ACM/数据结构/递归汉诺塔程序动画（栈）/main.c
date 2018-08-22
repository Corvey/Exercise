#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct node //结点
{
    int n;
    struct node *pNext;
}NODE, * PNODE;

typedef struct stack  //栈
{
    char name;
    PNODE pTop;
    PNODE pBottom;
}STACK, * PSTACK;

PSTACK S[3]; //A、B、C三个栈
int time=0, num;

int hannuota(int n, PSTACK A, PSTACK B, PSTACK C)
{
    if(n==1)
    {
        push(C, pop(A));
        time++;
        //printf("将1号罗盘从%c移向%c\n", A->ch, C->ch);
        paint();
    }
    else
    {
        hannuota(n-1, A, C, B);
        push(C, pop(A));
        time++;
        //printf("将%d号罗盘从%c移向%c\n", n, A->ch, C->ch);
        paint();
        hannuota(n-1, B, A, C);
    }
}

PSTACK init(void) //初始化
{
    PSTACK pS;
    pS = (PSTACK)malloc(sizeof(STACK));
    pS->pBottom = (PNODE)malloc(sizeof(NODE));
    pS->pBottom->pNext = NULL;
    pS->pTop = pS->pBottom;
    return pS;
}

void push(PSTACK pS, int n)  //入栈
{
    PNODE pTemp = (PNODE)malloc(sizeof(NODE));
    pTemp->n = n;
    pTemp->pNext = pS->pTop;
    pS->pTop = pTemp;
}

int count_num(PSTACK pS) //求栈数据个数
{
    int n=0;
    PNODE pTemp = pS->pTop;
    while(pTemp->pNext)
    {
        n++;
        pTemp = pTemp->pNext;
    }
    return n;
}

int pop(PSTACK pS) //出栈
{
    int x = pS->pTop->n;
    if(pS->pTop->pNext)
    {
        PNODE pTemp = pS->pTop->pNext;
        free(pS->pTop);
        pS->pTop = pTemp;
    }
    return x;
}

void Gotoxy(int x,int y)  //移动光标
{
	COORD loc={x,y};
	HANDLE hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput,loc);
}

void paint(void)  //绘图
{
    PNODE pTemp;
    int y;
    system("cls");
    if(!time)
        printf("初始状态：\n");
    else
        printf("第%d步：\n", time);

    for(int i=0; i<3; i++)
    {
        y = num + 2 - count_num(S[i]);
        Gotoxy(6*i+2, y);
        pTemp = S[i]->pTop;

        while(pTemp->pNext)
        {
            printf("%2d", pTemp->n);
            pTemp = pTemp->pNext;
            y++;
            Gotoxy(6*i+2, y);
        }
        printf("%c柱", S[i]->name);
    }

    if(count_num(S[2])==num)
    {
        printf("\n\n已完成！\n");
        printf("共用步数：%d\n", time);
        printf("\n\n按任意键退出。。。");
        getch();
    }
    else
    {
        printf("\n\n按任意键进行下一步。。。");
        getch();
    }
}
int main(void)
{
    int n;
    for(int i=0; i<3; i++) //初始化栈
    {
        S[i] = init();
        S[i]->name = 'A' + i;
    }
    while(1)
    {
        printf("请输入罗盘个数：");
        fflush(stdin);
        if(fscanf(stdin, "%d", &num) && num>0)
            break;
        else
            printf("输入有误！请重新输入！\n");
    }

    for(int i=num-1; i>=0; i--)
    {
        push(S[0], i+1);
    }
    paint();
    hannuota(num, S[0], S[1], S[2]);
    return 0;
}
