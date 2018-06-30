#include <cstdio>
#include <stack>
#include <deque>
using namespace std;
struct node{
    int data, time;
}temp, ta, tb;
char str[10];
void work(int n)
{
    int x;
    deque<node> a, b;
    stack<int> c;
    for(int i=0; i<n; ++i)
    {
        scanf("%s", str);
        if(str[0] == 'm') //merge
        {
            scanf("%*s %*s");
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
        }
        else if(str[1] == 'u')    //push
        {
            scanf("%s %d", str, &temp.data);
            temp.time = i;
            if(str[0] - 'A')
                b.push_front(temp);
            else
                a.push_front(temp);
        }
        else    //pop
        {
            scanf("%s", str);
            str[0] -= 'A';
            if(str[0] ? b.empty() : a.empty())
            {
                printf("%d\n", c.top());
                c.pop();
            }
            else
            {
                if(str[0])
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
