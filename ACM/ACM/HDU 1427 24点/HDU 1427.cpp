#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
int a[4];
char fuhao[64][3];
bool jisuan(int a, int b, char ch, int& ans)
{
    switch (ch)
    {
    case 0:
        ans = a + b;
        return true;
    case 1:
        ans = a - b;
        return true;
    case 2:
        ans = a * b;
        return true;
    case 3:
        if(!b || a%b)
            return false;
        ans = a / b;
        return true;
    }
}
bool work(void)
{
    int ans1, ans2;
    do
    {
        for(int i=0; i<64; ++i)
        {
            ans1 = ans2 = 0;
            if(jisuan(a[0], a[1], fuhao[i][0], ans1) && jisuan(ans1, a[2], fuhao[i][1], ans1) &&
               jisuan(ans1, a[3], fuhao[i][2], ans1) && (ans1 == 24 || ans1 == -24))
                return true;
            if(jisuan(a[0], a[1], fuhao[i][0], ans1) && jisuan(a[2], a[3], fuhao[i][2], ans2) &&
               jisuan(ans1, ans2, fuhao[i][1], ans2) && (ans2 == 24 || ans2 == -24))
                return true;
        }
    } while (next_permutation(a, a+4));
    return false;
}
int main(void)
{
    int n = 0;
    for(int i=0; i<4; ++i)
        for(int j=0; j<4; ++j)
            for(int k=0; k<4; ++k)
                fuhao[n][0] = i, fuhao[n][1] = j, fuhao[n++][2] = k;
    char str[4][3];
    while(~scanf("%s%s%s%s", str[0], str[1], str[2], str[3]))
    {
        for(int i=0; i<4; ++i)
        {
            if(!strcmp(str[i], "A"))
                a[i] = 1;
            else if(!strcmp(str[i], "J"))
                a[i] = 11;
            else if(!strcmp(str[i], "Q"))
                a[i] = 12;
            else if(!strcmp(str[i], "K"))
                a[i] = 13;
            else
                a[i] = atoi(str[i]);
        }
        sort(a, a+4);
        printf("%s\n", work() ? "Yes" : "No");
    }
}
