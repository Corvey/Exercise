#include <stdio.h>
#include <string.h>
struct stu
{
    char name[21];
    int a;
    int b;
    char c;
    char d;
    int e;
};
int main(void)
{
    int n, t, all, max, money;
    char maxname[21];
    struct stu s;
    scanf("%d", &n);
    getchar();
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &t);
        getchar();
        max = 0;
        all = 0;
        for(int j=0; j<t; ++j)
        {
            money = 0;
            scanf("%s %d %d %c %c %d", s.name, &s.a, &s.b, &s.c, &s.d, &s.e);
            getchar();
            if(s.a>80 && s.e>0)//院士奖学金
                money += 8000;
            if(s.a>85 && s.b>80)//五四奖学金
                money += 4000;
            if(s.a>90)//成绩优秀奖
                money += 2000;
            if(s.a>85 && s.d == 'Y')//西部奖学金
                money += 1000;
            if(s.b>80 && s.c == 'Y')//班级贡献奖
                money += 850;

            all += money;
            if(money > max)
            {
                max = money;
                strcpy(maxname, s.name);
            }
        }
        printf("%s\n%d\n%d\n", maxname, max, all);
    }
}
