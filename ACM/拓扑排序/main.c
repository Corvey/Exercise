#include <stdio.h>
#include <stdlib.h>
typedef struct graph
{
    int num;
    struct vertex *vertex;
}GRAPH, *PGRAPH;

typedef struct vertex
{
    int name;
    int degree;
    struct node *pNext;
}VERTEX, *PVERTEX;

typedef struct node
{
    int name;
    struct node *pNext;
}NODE, *PNODE;

PGRAPH InitGraph(void)
{
    int n;
    printf("请输入顶点个数：");
    scanf("%d", &n);
    PGRAPH pG = (PGRAPH)malloc(sizeof(GRAPH));
    pG->vertex = (PVERTEX)malloc(n * sizeof(VERTEX));
    for(int i=0; i<n; ++i)
    {
        ((pG->vertex)+i)->degree = 0;
    }
    for(int i=0; i<n; ++i)
    {
        printf("请输入第%d个顶点的名称及其所指向的点的名称：", i+1);
        int x;
        scanf("%d", &((pG->vertex)+i)->name);
        ((pG->vertex)+i)->pNext = (PNODE)malloc(sizeof(NODE));
        PNODE pTemp = ((pG->vertex)+i)->pNext;
        char c;
        while(1)
        {
            scanf("%c", &c);
            if(c == '\n')
                break;
            scanf("%d", &x);
            pTemp->pNext = (PNODE)malloc(sizeof(NODE));
            pTemp = pTemp->pNext;
            pTemp->name = x;
            pTemp->pNext = NULL;
        }
    }
    return pG;
}
int main(void)
{
    PGRAPH pG = InitGraph();
}
