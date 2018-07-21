#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CODEMAX 15
#define FILEMAX 30

typedef struct huffmantree
{
    char ch;
    int weight;
    char code[CODEMAX];
    struct huffmantree *pLeft;
    struct huffmantree *pRight;
}HTREE, *PHTREE;

typedef struct qnode
{
    struct huffmantree *pT;
    struct qnode *pNext;
}QNODE, *PQNODE;

typedef struct queue
{
    struct qnode *pFront;
    struct qnode *pRear;
}QUEUE, *PQUEUE;

typedef struct lnode
{
    char ch;
    struct lnode *pNext;
}LNODE, *PLNODE;

PQUEUE InitQueue(void)
{
    PQUEUE pQ = (PQUEUE)malloc(sizeof(QUEUE));
    pQ->pRear = (PQNODE)malloc(sizeof(QNODE));
    pQ->pRear->pNext = NULL;
    pQ->pFront = pQ->pRear;
    return pQ;
}

void EnQueue(PQUEUE pQ, PHTREE pT)
{
    pQ->pRear->pNext = (PQNODE)malloc(sizeof(QNODE));
    pQ->pRear = pQ->pRear->pNext;
    pQ->pRear->pT = pT;
    pQ->pRear->pNext = NULL;
}

PHTREE DeQueue(PQUEUE pQ)
{
    PQNODE pQTemp = pQ->pFront->pNext->pNext;
    PHTREE pTTemp = pQ->pFront->pNext->pT;
    free(pQ->pFront->pNext);
    pQ->pFront->pNext = pQTemp;
    if(!pQ->pFront->pNext)
        pQ->pRear = pQ->pFront;
    return pTTemp;
}

void PrintQList(PQNODE pHead)
{
    PQNODE  pTail = pHead->pNext;
    while(pTail)
    {
        printf("字符：%c \tASCII码：%d\t权：%d\n", pTail->pT->ch, pTail->pT->ch, pTail->pT->weight);
        pTail = pTail->pNext;
    }
    //printf("\n");
    system("pause");
}

int NumOfQueue(PQUEUE pQ)
{
    int n = 0;
    PQNODE pQTemp = pQ->pFront->pNext;
    while(pQTemp)
    {
        ++n;
        pQTemp = pQTemp->pNext;
    }
    return n;
}
PHTREE CreatHuffmanTree(char *file)   //done
{
    unsigned int *Frequency = (int *)malloc(257*sizeof(int));
    memset(Frequency, 0, 257*sizeof(int));   //初始化
    FILE *fp = fopen(file, "rt");
    if(!fp)
    {
        printf("Can not find this file.\n");
        printf("Please press anykey to return to previous menu...");
        getch();
        exit(0);
    }

    char c;
    do
    {
        c = fgetc(fp);
        ++Frequency[(int)c];

    } while (c != EOF);

    PQUEUE pQ = InitQueue();
    PHTREE pTTemp;
    for(int i=0; i<257; ++i)
    {
        if(!Frequency[i])
            continue;
        pTTemp = (PHTREE)malloc(sizeof(HTREE));
        pTTemp->ch = (char)i;
        pTTemp->weight = Frequency[i];
        pTTemp->pLeft = NULL;
        pTTemp->pRight = NULL;
        EnQueue(pQ, pTTemp);
    }
    pTTemp = (PHTREE)malloc(sizeof(HTREE));
    pTTemp->ch = (char)-1;
    pTTemp->weight = 1;
    pTTemp->pLeft = NULL;
    pTTemp->pRight = NULL;
    EnQueue(pQ, pTTemp);

    PQNODE pQTemp1 = pQ->pFront->pNext;
    while(pQTemp1)
    {
        PQNODE pQMin = pQTemp1;
        PQNODE pQTemp2 = pQTemp1->pNext;
        while(pQTemp2)
        {
            if(pQMin->pT->weight > pQTemp2->pT->weight)
                pQMin = pQTemp2;
            pQTemp2 = pQTemp2->pNext;
        }
        pTTemp = pQMin->pT;
        pQMin->pT = pQTemp1->pT;
        pQTemp1->pT = pTTemp;

        pQTemp1 = pQTemp1->pNext;
    }

    //printf("元素个数：%d\n", NumOfQueue(pQ));
    //PrintQList(pQ->pFront);

    while(pQ->pFront->pNext->pNext)
    {
        PHTREE a = DeQueue(pQ);
        PHTREE b = DeQueue(pQ);
        pTTemp = (PHTREE)malloc(sizeof(HTREE));
        //pTTemp->ch = '~';
        pTTemp->code[0] = '\0';
        pTTemp->pLeft = b;
        pTTemp->pRight = a;
        pTTemp->weight = a->weight + b->weight;

        if(!pQ->pFront->pNext)
        {
            free(pQ->pFront);
            free(pQ);
            return pTTemp;
        }

        pQTemp1 = pQ->pFront;
        while(pQTemp1->pNext)
        {
            if(pTTemp->weight < pQTemp1->pNext->pT->weight)
            {
                PQNODE  p = (PQNODE)malloc(sizeof(QNODE));
                p->pT = pTTemp;
                p->pNext = pQTemp1->pNext;
                pQTemp1->pNext = p;
                break;
            }
            pQTemp1 = pQTemp1->pNext;
        }
        if(!pQTemp1->pNext)
            EnQueue(pQ, pTTemp);

        //PrintQList(pQ->pFront);
    }
    pTTemp = DeQueue(pQ);
    free(pQ->pFront);
    free(pQ);
    return pTTemp;
}

void PreorderTraversal(PHTREE p)  //先序遍历
{
    printf("%d ", p->weight);
    if(p->pLeft)
        PreorderTraversal(p->pLeft);
    if(p->pRight)
        PreorderTraversal(p->pRight);
}

void InorderTraversal(PHTREE p)  //中序遍历
{
    if(p->pLeft)
        InorderTraversal(p->pLeft);
    printf("%d ", p->weight);
    if(p->pRight)
        InorderTraversal(p->pRight);
}

void EnCode(PHTREE pTHead, char *file)
{
    PQNODE pQHead = (PQNODE)malloc(sizeof(QNODE));
    PQNODE pQTail = pQHead;
    PQUEUE pQ = InitQueue();
    EnQueue(pQ, pTHead);
    FILE *fp = fopen("HuffmanCode.txt", "wt");

    while(pQ->pFront->pNext)
    {
        PHTREE pT = DeQueue(pQ);
        if(pT->pLeft)
        {
            strcpy(pT->pLeft->code, pT->code);
            char *pC;
            for(pC = pT->pLeft->code; *pC != '\0'; ++pC);
            *pC = '0';
            *(pC+1) = '\0';
            EnQueue(pQ, pT->pLeft);
        }
        else
        {
            pQTail->pNext = (PQNODE)malloc(sizeof(QNODE));
            pQTail = pQTail->pNext;
            pQTail->pT = pT;
            pQTail->pNext = NULL;
            fprintf(fp, "%c %d\n", pT->ch, pT->weight);
            continue;
        }

        if(pT->pRight)
        {
            strcpy(pT->pRight->code, pT->code);
            char *pC;
            for(pC = pT->pRight->code; *pC != '\0'; ++pC);
            *pC = '1';
            *(pC+1) = '\0';
            EnQueue(pQ, pT->pRight);
        }
        else
        {
            pQTail->pNext = (PQNODE)malloc(sizeof(QNODE));
            pQTail = pQTail->pNext;
            pQTail->pT = pT;
            pQTail->pNext = NULL;
            fprintf(fp, "%c %d\n", pT->ch, pT->weight);
        }
    }
    free(pQ->pFront);
    free(pQ);
    fclose(fp);
    fp = fopen(file, "rt");
    FILE *fp2 = fopen("EnCode.txt", "wt");
    char c;
    do
    {
        c = getc(fp);
        pQTail = pQHead->pNext;
        while(pQTail)
        {
            if(pQTail->pT->ch == c)
            {
                fprintf(fp2, "%s", pQTail->pT->code);
                break;
            }
            pQTail = pQTail->pNext;
        }

    } while (c != EOF);
    fclose(fp);
    fclose(fp2);
}

void DeCode()
{
    PQUEUE pQ = InitQueue();
    PQNODE pQHead = NULL;
    PQNODE pQTemp = pQHead;
    FILE *fp = fopen("HuffmanCode.txt", "rt");
    if(!fp)
    {
        printf("Can not find this file.\n");
        printf("Please press anykey to return to previous menu...");
        getch();
        exit(0);
    }
    char c;
    int weight;
    PHTREE pTTemp;
    do
    {
        c = fgetc(fp);
        fscanf(fp, "%d", &weight);
        fseek(fp, 2L, SEEK_CUR);
        pTTemp = (PHTREE)malloc(sizeof(HTREE));
        pTTemp->ch = c;
        pTTemp->weight = weight;
        pTTemp->pLeft = NULL;
        pTTemp->pRight = NULL;
        pQTemp = (PQNODE)malloc(sizeof(QNODE));
        pQTemp->pT = pTTemp;
        pQTemp->pNext = pQHead;
        pQHead = pQTemp;

    } while (c != EOF);

    c = fgetc(fp);
    while(c != EOF)
    {
        fscanf(fp, "%d", &weight);
        fseek(fp, 2L, SEEK_CUR);
        pTTemp = (PHTREE)malloc(sizeof(HTREE));
        pTTemp->ch = c;
        pTTemp->weight = weight;
        pTTemp->pLeft = NULL;
        pTTemp->pRight = NULL;
        pQTemp = (PQNODE)malloc(sizeof(QNODE));
        pQTemp->pT = pTTemp;
        pQTemp->pNext = pQHead;
        pQHead = pQTemp;
        c = fgetc(fp);
    }
    fclose(fp);
    while(pQHead)
    {
        pQTemp = pQHead->pNext;
        EnQueue(pQ, pQHead->pT);
        free(pQHead);
        pQHead = pQTemp;
    }
    free(pQHead);
    //PrintQList(pQ->pFront);

    PHTREE pTHead;
    while(pQ->pFront->pNext->pNext)
    {
        PHTREE a = DeQueue(pQ);
        PHTREE b = DeQueue(pQ);
        pTTemp = (PHTREE)malloc(sizeof(HTREE));
        //pTTemp->ch = '~';
        pTTemp->code[0] = '\0';
        pTTemp->pLeft = b;
        pTTemp->pRight = a;
        pTTemp->weight = a->weight + b->weight;

        if(!pQ->pFront->pNext)
        {
            pTHead = pTTemp;
            break;
        }

        pQTemp = pQ->pFront;
        while(pQTemp->pNext)
        {
            if(pTTemp->weight < pQTemp->pNext->pT->weight)
            {
                PQNODE  p = (PQNODE)malloc(sizeof(QNODE));
                p->pT = pTTemp;
                p->pNext = pQTemp->pNext;
                pQTemp->pNext = p;
                break;
            }
            pQTemp = pQTemp->pNext;
        }
        if(!pQTemp->pNext)
            EnQueue(pQ, pTTemp);

        //PrintQList(pQ->pFront);
    }
    if(pQ->pFront->pNext)
        pTHead = pQ->pFront->pNext;
    /*
    printf("树根：\n字符：%c \tASCII码：%d\t权：%d\n\n", pTHead->ch, pTHead->ch, pTHead->weight);
    printf("先序遍历树：");
    PreorderTraversal(pTHead);
    printf("\n");
    printf("中序遍历树：");
    InorderTraversal(pTHead);
    printf("\n");
    */

    while(pQ->pFront->pNext)
    {
        PHTREE pT = DeQueue(pQ);
        if(pT->pLeft)
        {
            strcpy(pT->pLeft->code, pT->code);
            char *pC;
            for(pC = pT->pLeft->code; *pC != '\0'; ++pC);
            *pC = '0';
            *(pC+1) = '\0';
            EnQueue(pQ, pT->pLeft);
        }
        else
            continue;

        if(pT->pRight)
        {
            strcpy(pT->pRight->code, pT->code);
            char *pC;
            for(pC = pT->pRight->code; *pC != '\0'; ++pC);
            *pC = '1';
            *(pC+1) = '\0';
            EnQueue(pQ, pT->pRight);
        }
    }
    free(pQ->pFront);
    free(pQ);

    fp = fopen("EnCode.txt", "rt");
    FILE *fp2 = fopen("DeCode.txt", "wt");
    pTTemp = pTHead;
    while(1)
    {
        c = getc(fp);
        if(c == '0')
        {
            pTTemp = pTTemp->pLeft;
            if(!pTTemp->pLeft)
            {
                fprintf(fp2, "%c", pTTemp->ch);
                pTTemp = pTHead;
            }
        }
        else if(c == '1')
        {
            pTTemp = pTTemp->pRight;
            if(!pTTemp->pRight)
            {
                fprintf(fp2, "%c", pTTemp->ch);
                pTTemp = pTHead;
            }
        }
        else
        {
            fclose(fp);
            fclose(fp2);
            return ;
        }
    }
}

int main(void)
{
    /*
    printf("树根：\n字符：%c \tASCII码：%d\t权：%d\n\n", pTHead->ch, pTHead->ch, pTHead->weight);
    printf("先序遍历树：");
    PreorderTraversal(pTHead);
    printf("\n");
    printf("中序遍历树：");
    InorderTraversal(pTHead);
    printf("\n");
    */
    while(1)
    {
        system("cls");
        printf(" ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁\n");
        printf(" ▏                                    ▕\n");
        printf(" ▏       Welcome to Huffman Code      ▕\n");
        printf(" ▏           Make your choice         ▕\n");
        printf(" ▏——————————————————▕\n");
        printf(" ▏                                    ▕\n");
        printf(" ▏            1、EnCode               ▕\n");
        printf(" ▏            2、DeCode               ▕\n");
        printf(" ▏            3、Exit                 ▕\n");
        printf(" ▏                                    ▕\n");
        printf(" ▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔\n");
        switch(getch())
        {
        case '1':
        {
            system("cls");
            char file[FILEMAX];
            printf("Please input the file you're ready to encode location:");
            fscanf(stdin, "%s", file);
            EnCode(CreatHuffmanTree(file), file);
            printf("Done!\nPlease press anykey to return to previous menu...");
            getch();
            continue;
        }
        case '2':
        {
            system("cls");
            DeCode();
            printf("Done!\nPlease press anykey to return to previous menu...");
            getch();
            continue;
        }
        case '3':
            exit(0);
            break;

        default:
            break;
        }
    }
}







