#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    int n, tag;
    char a[7], b[7];
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        getchar();
        scanf("%s%s", a, b);
        while(strcmp(a, b))
        {
            tag = 1;
            for(int j=0; j<5; ++j)
            {
                if(abs(a[j]-a[j+1]) > 4)
                {
                    tag = 0;
                    break;
                }
                if(j<=3)
                {
                    if(a[j] == a[j+1] && a[j+1] == a[j+2])
                    {
                        tag = 0;
                        break;
                    }
                }
            }
            if(tag)
                printf("%s\n", a);
            tag = 5;
            while(1)
            {
                ++a[tag];
                if(a[tag] > '6')
                {
                    a[tag] = '0';
                    --tag;
                }
                else
                    break;
            }
        }
        if(!strcmp(a, b))
        {
            tag = 1;
            for(int j=0; j<5; ++j)
            {
                if(abs(a[j]-a[j+1]) > 4)
                {
                    tag = 0;
                    break;
                }
                if(j<=3)
                {
                    if(a[j] == a[j+1] && a[j+1] == a[j+2])
                    {
                        tag = 0;
                        break;
                    }
                }
            }
            if(tag)
                printf("%s\n", a);
        }
        printf("\n");
    }
}
