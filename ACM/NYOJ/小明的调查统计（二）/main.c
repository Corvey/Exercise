#include <stdio.h>
struct data
{
    int Class;
    int Number;
    int Score;
};
int main(void)
{
    struct data s[100000], temp;
    int t, m, n, all, x, count;
    scanf("%d%d", &t, &m);
    all = 0;
    count = 0;
    for(int i=1; i<=t; ++i)
    {
        scanf("%d", &n);
        all += n;
        for(int j=0; j<n; ++j)
        {
            s[count].Class = i;
            s[count].Number = j+1;
            scanf("%d", &s[count].Score);
            ++count;
        }
    }
    /*
    for(int i=0; i<all; ++i)
    {
        printf("%d %d %d\n", s[i].Class, s[i].Number, s[i].Score);
    }
    */
    for(int i=0; i<all-1; ++i)
    {
        for(int j=0; j<all-1-i; ++j)
        {
            if(s[j].Score < s[j+1].Score)
            {
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
    int pre = 1;
    count = 0;
    for(int i=0; i<m; ++i)
    {
        scanf("%d", &x);
        for(int j=0; j<x-pre; ++j)
        {
            for(; ; ++count)
            {
                if(s[count].Score != s[count+1].Score)
                {
                    ++count;
                    break;
                }
            }
        }
        while(1)
        {
            printf("%d %d\n", s[count].Class, s[count].Number);
            if(s[count].Score == s[count+1].Score)
                ++count;
            else
                break;
        }
        pre = x;
    }
}
