#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n[10] = {5, 6, 3, 2, 4, 9, 7, 8, 1, 10};
    for(int i=0; i<10; ++i)
    {
        int min = i;
        for(int j=i+1; j<10; ++j)
        {
            if(n[j] < n[min])
                min = j;
        }
        if(min != i)
        {
            int temp = n[min];
            n[min] = n[i];
            n[i] = temp;
        }
    }
    for(int i=0; i<10; ++i)
    {
        printf("%d ", n[i]);
    }
    return 0;
}
