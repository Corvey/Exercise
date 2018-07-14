#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n[10], i, j, k, temp;
    for(i=9; i>=0; i--)
    {
        n[i] = 10-i;
    }

    for(i = 0; i < 9; i++)
    {
        if(n[i] > n[i+1])
        {
            temp = n[i+1];
            for(j = i; j >= 0 && temp < n[j]; j--)
            {
                n[j + 1] = n[j];
            }
            n[j + 1] = temp;
        }
    }

    for(i=0; i<10; i++)
    {
        printf("%d\n", n[i]);
    }
}
