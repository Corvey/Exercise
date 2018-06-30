#include <cstdio>
#include <stack>
#include <deque>
using namespace std;
struct node{
    int data, time;
}temp, ta, tb;
inline int readint(void)
{
    int ans = 0, sign = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
    {
        if(ch == '-')
            sign = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * sign;
}
inline int readorder(void)
{
    char ch = getchar();
    while(ch < 'a' || ch > 'z')
        ch = getchar();
    if(ch == 'm')
    {
        while(getchar() != '\n');
        return 1;
    }
    ch = getchar();
    return ch == 'u' ? 2 : 3;
}
inline bool readletter(void)
{
    char ch = getchar();
    while(ch < 'A' || ch > 'Z')
        ch = getchar();
    return ch - 'A';
}
void work(int n)
{
    bool tag;
    deque<node> a, b;
    stack<int> c;
    for(int i=0; i<n; ++i)
    {
        switch (readorder())
        {
        case 1: //merge
            while(!a.empty() && !b.empty())
            {
                ta = a.back();
                tb = b.back();
                if(ta.time < tb.time)
                {
                    c.push(ta.data);
                    a.pop_back();
                }
                else
                {
                    c.push(tb.data);
                    b.pop_back();
                }
            }
            if(!a.empty())
            {
                while(!a.empty())
                {
                    c.push(a.back().data);
                    a.pop_back();
                }
            }
            else
            {
                while(!b.empty())
                {
                    c.push(b.back().data);
                    b.pop_back();
                }
            }
        break;

        case 2: //push
            tag = readletter();
            temp.data = readint();
            temp.time = i;
            if(tag)
                b.push_front(temp);
            else
                a.push_front(temp);
        break;

        case 3: //pop
            tag = readletter();
            if(tag ? b.empty() : a.empty())
            {
                printf("%d\n", c.top());
                c.pop();
            }
            else
            {
                if(tag)
                {
                    printf("%d\n", b.front());
                    b.pop_front();
                }
                else
                {
                    printf("%d\n", a.front());
                    a.pop_front();
                }
            }
        break;
        }
    }
}
int main(void)
{
    int n;
    for(int T=0; ;)
    {
        scanf("%d", &n);
        if(!n)
            break;
        printf("Case #%d:\n", ++T);
        work(n);
    }
    return 0;
}
