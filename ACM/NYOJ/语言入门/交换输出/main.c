#include <stdio.h>
int main(void)
{
    int n, min, tag, a[100];
    while(1)
    {
        scanf("%d", &n);
        if(!n)
            break;
        scanf("%d", a);
        min = a[0];
        tag = 0;
        for(int i=1; i<n; ++i)
        {
            scanf("%d", a+i);
            if(a[i] < min)
            {
                min = a[i];
                tag = i;
            }
        }
        if(a[0]!=a[tag])
        {
            int temp = a[0];
            a[0] = min;
            a[tag] = temp;
        }
        for(int i=0; i<n; ++i)
            printf("%d ", a[i]);
        printf("\n");
    }
}
