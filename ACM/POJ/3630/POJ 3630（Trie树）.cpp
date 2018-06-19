#include <cstdio>
#include <string.h>
const int MAX = 10;
int N;
struct TRIE
{
    bool isStr;
    int Next[MAX];
}trie[100000];
int EMPTY[MAX] = {0};

bool work(char* str)
{
    int t, pos = 0;
    for(int i=0; str[i]; ++i)
    {
        t = str[i] - '0';
        if(!trie[pos].Next[t])
        {
            trie[pos].Next[t] = ++N;
            memset(trie+N, 0, sizeof(TRIE));
            pos = N;
        }
        else
        {
            pos = trie[pos].Next[t];
            if(trie[pos].isStr)
                return false;
        }
    }
    trie[pos].isStr = true;
    return !memcmp(trie[pos].Next, EMPTY, sizeof(int)*MAX);
}

int main(void)
{
    char str[11];
    bool ans;
    int kase, n;
    scanf("%d\n", &kase);
    while(kase--)
    {
        scanf("%d\n", &n);
        memset(trie, 0 ,sizeof(TRIE));
        N = 0;
        ans = true;
        for(int i=0; i<n; ++i)
        {
            gets(str);
            if(!work(str))
            {
                for(++i; i<n; ++i)
                    gets(str);
                ans = false;
                break;
            }
        }
        printf("%s\n", ans ? "YES" : "NO");
    }
    return 0;
}
