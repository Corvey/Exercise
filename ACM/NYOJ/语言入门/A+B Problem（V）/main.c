#include <stdio.h>
#include <math.h>
int main(void)
{
    int a, b, sum, lena, lenb;
    scanf("%d%d", &a, &b);
    while(a && b)
    {
        sum = 0;
        for(lena = log10(a); a; a/=10, --lena)
            sum += a%10 * pow(10, lena);
        for(lenb = log10(b); b; b/=10, --lenb)
            sum += b%10 * pow(10, lenb);
        printf("%d\n", sum);
        scanf("%d%d", &a, &b);
    }
}
