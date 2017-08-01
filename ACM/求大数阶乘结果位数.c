#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.1415926535897932384626
#define E 2.718281828459 
double jiecheng(double n, double ans)
{
       if(n == 0)
           return 0;
       else if(n == 1)
           return ans;
       else
           return jiecheng(n-1, ans*n);
}
main()
{
      double n, ans;
      printf("请输入x:");
      scanf("%lf", &n);
      ans = jiecheng(n, 1);
      printf("%.0lf! = %.0lf\n", n, ans);
      printf("普通方法求得位数：%f\n", log10(ans)+1);
      ans = n*(log10(n)-log10(E))+0.5*(log10(2*pi*n)+1);
      printf("公式求的：%d\n", (int)ans);
      system("pause");
} 
