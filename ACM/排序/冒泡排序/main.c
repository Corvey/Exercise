#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n[10] = {1, 2, 5, 6, 8, 9, 3, 4, 10, 7};
    for(int i=0; i<9; ++i)
    {
        int exchange = 0;
        for(int j=0; j<9-i; ++j)
        {
            if(n[j] > n[j+1])
            {
                int temp = n[j];
                n[j] = n[j+1];
                n[j+1] = temp;
                ++exchange;
            }
        }
        if(exchange == 0)
            break;
    }
    for(int i=0; i<10; ++i)
    {
        printf("%d ", n[i]);
    }
}
