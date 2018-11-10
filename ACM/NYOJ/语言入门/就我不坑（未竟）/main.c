/*
void qwe(char *s, int n)
{
    switch (n)
    {
    case 1:
        strcat(s, "壹");
        break;

    case 2:
        strcat(s, "贰");
        break;

    case 3:
        strcat(s, "叁");
        break;

    case 4:
        strcat(s, "肆");
        break;

    case 5:
        strcat(s, "伍");
        break;

    case 6:
        strcat(s, "陆");
        break;

    case 7:
        strcat(s, "柒");
        break;

    case 8:
        strcat(s, "捌");
        break;

    case 9:
        strcat(s, "玖");
        break;

    default:
        break;
    }
}
void asd(char *s, int n)
{
    switch (n)
    {
    case 8:
        strcat(s, "亿");
        break;

    case 4:
        strcat(s, "万");
        break;

    case 7:
    case 3:
        strcat(s, "仟");
        break;

    case 6:
    case 2:
        strcat(s, "佰");
        break;

    case 9:
    case 5:
    case 1:
        strcat(s, "拾");
        break;

    default:
        break;
    }
}
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
void qwe(int n)
{
    switch (n)
    {
    case 1:
        printf("壹");
        break;

    case 2:
        printf("贰");
        break;

    case 3:
        printf("叁");
        break;

    case 4:
        printf("肆");
        break;

    case 5:
        printf("伍");
        break;

    case 6:
        printf("陆");
        break;

    case 7:
        printf("柒");
        break;

    case 8:
        printf("捌");
        break;

    case 9:
        printf("玖");
        break;

    default:
        break;
    }
}
void asd(int n)
{
    switch (n)
    {
    case 8:
        printf("亿");
        break;

    case 4:
        printf("万");
        break;

    case 7:
    case 3:
        printf("仟");
        break;

    case 6:
    case 2:
        printf("佰");
        break;

    case 9:
    case 5:
    case 1:
        printf("拾");
        break;

    default:
        break;
    }
}
int main(void)
{
    int x, count, temp, pre = 0;
    char a[19];
    while(~scanf("%d", &x))
    {
        if(!x)
        {
            printf("零\n");
            continue;
        }
        sprintf(a, "%d", x);
        count = strlen(a);
        while(x)
        {
            temp = x/pow(10, --count);
            qwe(temp);
            printf("temp:%d count:%d pre:%d\n", temp, count, pre);
            if(temp)
                pre = 0;
            else if(!pre && count != 4 && count != 8)
                printf("零"), pre = 1;
            if(temp || count ==4 && !pre || count == 8 && !pre)
                asd(count);
            x -= temp * pow(10, count);
            if(x < pow(10, count-1))
            {
                --count;
                if(count > 8)
                    printf("亿");
                else if(count > 4)
                    printf("万");
            }
        }
        printf("\n");
    }
}
