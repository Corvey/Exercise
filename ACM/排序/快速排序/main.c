#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int FindPos(int *n, int low, int high)
{
    int temp = n[low];
    do
    {
        for(; temp < n[high]; --high)
        {
            if(low == high)
                return low;
        }
        n[low] = n[high];
        for(; low < high && temp > n[low]; ++low);
        n[high] = n[low];


    } while(low < high);
    n[high] = temp;
    return low;
}

void QuickSort(int *n, int low, int high)
{
    if(low < high)
    {
        int pos = FindPos(n, low, high);
        QuickSort(n, low, pos-1);
        QuickSort(n, pos+1, high);
    }
}

int main(void)
{
    int n[MAX];
    for(int i=0; i<MAX; i++)
    {
        printf("请输入第%d个数据：", i+1);
        scanf("%d", &n[i]);
    }
    QuickSort(n , 0, MAX-1);

    printf("\n排序后：\n");
    for(int i=0; i<MAX; i++)
    {
        printf("%d ", n[i]);
    }
    printf("\n");
    return 0;
}

