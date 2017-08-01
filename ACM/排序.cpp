#include <cstdio>
const int N = 1e4;
inline void SWAP(int &a, int &b)
{
    static int t;
    t = a, a = b, b = t;
}
void pf(int *dst, int n)
{
    for(int i=0; i<n; ++i)
        printf("%d ", dst[i]);
    printf("\n\n");
}
void maopaoSort(int *dst, int n, bool order)    //ð������
{
    for(int i=0; i<n-1; ++i)
        for(int j=0; j<n-1-i; ++j)
            if(dst[j] > dst[j+1] != order)
                SWAP(dst[j], dst[j+1]);
}
void xuanzeSort(int *dst, int n, bool order)    //ѡ������
{
    int index;
    for(int i=0; i<n-1; ++i)
    {
        index = i;
        for(int j=i+1; j<n; ++j)
            if(dst[j] < dst[index] != order)
                index = j;
        SWAP(dst[i], dst[index]);
    }
}
void charuSort(int *dst, int n, bool order) //��������
{
    int t;
    for(int i=1; i<n; ++i)
    {
        if(dst[i] < dst[i-1])
        {
            t = dst[i];
            int j;
            for(j=i-1; j>=0 && t<dst[j]; --j)
                dst[j+1] = dst[j];
            dst[j+1] = t;
        }
        pf(dst, n);
    }
}
int main(void)
{
    int data[N], n, order;
    while(1)
    {
        printf("���������ݸ���(0Ϊ����)��");
        scanf("%d", &n);
        if(!n)
            break;
        printf("���������ݣ�");
        for(int i=0; i<n; ++i)
            scanf("%d", data+i);
        printf("�������������(����Ϊ0������Ϊ1)��");
        scanf("%d", &order);
        //maopaoSort(data, n, order);
        //xuanzeSort(data, n, order);
        charuSort(data, n, 0);
        //pf(data, n);
    }
    return 0;
}
