#include <stdio.h>
int GCD(int a, int b)
{
    return b==0 ? a : GCD(b, a%b);
}
int main(void)
{
    int a, b, x, y, gcd, lcm, t;
    char temp, ch;
    while(~scanf("%d%c%d%c%d%c%d", &a, &temp, &b, &ch, &x, &temp, &y))
    {
        gcd = GCD(b, y);
        lcm = b*y/gcd;
        a *= y/gcd;
        x *= b/gcd;
        if(ch == '+')
        {
            a += x;
            t = GCD(a, lcm);
            a /= t;
            lcm /= t;
            if(a%lcm)
                printf("%d/%d\n", a, lcm);
            else
                printf("%d\n", a/lcm);
        }
        else if(ch == '-')
        {
            if(a == x)
                printf("0\n");
            else if(a > x)
            {
                a -= x;
                t = GCD(a, lcm);
                a /= t;
                lcm /= t;
                if(a%lcm)
                    printf("%d/%d\n", a, lcm);
                else
                    printf("%d\n", a/lcm);
            }
            else
            {
                x -= a;
                t = GCD(x, lcm);
                x /= t;
                lcm /= t;
                if(x%lcm)
                    printf("-%d/%d\n", x, lcm);
                else
                    printf("-%d\n", x/lcm);
            }
        }
    }
}
