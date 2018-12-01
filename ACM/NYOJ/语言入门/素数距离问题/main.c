#include <stdio.h>
#include <math.h>
int judge(int x)
{
    if(x<=1)
        return 0;
    int n = (int)sqrt(x+1);
    for(int i=2; i<=n; ++i)
    {
        if(x%i==0)
            return 0;
    }
    return 1;
}
int main(void)
{
    int n, x, y, rd, ld;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &x);
        if(judge(x))
            printf("%d 0\n", x);
        else
        {
            for(rd=1; ; ++rd)
                if(judge(x+rd))
                    break;
            for(ld=1; x-ld >= 2; ++ld)
                if(judge(x-ld))
                    break;
            if(ld <= rd && x-ld >= 2)
                printf("%d %d\n", x-ld, ld);
            else
                printf("%d %d\n", x+rd, rd);
        }
    }
}
