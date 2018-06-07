#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
const char n2c[10][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
struct TRIE
{
    int chr, freq, father, Next[26];
}trie[100000];
int AMOUNT;
queue<int> q;
void Insert(char* str, int time)
{
    int t, pos = 0;
    for(int i=0; str[i]; ++i)
    {
        t = str[i] - 'a';
        trie[pos].freq += time;
        if(!trie[pos].Next[t])
        {
            trie[pos].Next[t] = ++AMOUNT;
            memset(trie+AMOUNT, 0, sizeof(TRIE));
            trie[AMOUNT].father = pos;
            pos = AMOUNT;
            trie[pos].chr = str[i];
        }
        else
            pos = trie[pos].Next[t];
    }
    trie[pos].freq += time;
}
void PrintStr(int x)
{
    if(x)
    {
        PrintStr(trie[x].father);
        printf("%c", trie[x].chr);
    }
}
void Query(char* str)
{
    int MAX, MAXTAG, t, num, pos;
    q.push(0);
    for(int i=0; str[i]!='1'; ++i)
    {
        t = str[i] - '0';
        num = q.size();
        MAX = MAXTAG = 0;
        for(int j=0; j<num; ++j)
        {
            for(int k=0; n2c[t][k]; ++k)
            {
                pos = trie[q.front()].Next[ n2c[t][k] - 'a' ];
                if(pos)
                {
                    q.push(pos);
                    if(trie[pos].freq > MAX)
                        MAX = trie[pos].freq, MAXTAG = pos;
                }
            }
            q.pop();
        }
        if(MAXTAG)
        {
            PrintStr(MAXTAG);
            printf("\n");
        }
        else
        {
            for(; str[i] != '1'; ++i)
                printf("MANUALLY\n");
            break;
        }
    }
    num = q.size();
    while(num--)
        q.pop();
    printf("\n");
}
int main(void)
{
    char str[105];
    int kase, n, time;
    scanf("%d", &kase);
    for(int i=0; i<kase; )
    {
        scanf("%d", &n);
        AMOUNT = 0;
        memset(trie, 0, sizeof(TRIE));
        for(int j=0; j<n; ++j)
        {
            scanf("%s %d", str, &time);
            Insert(str, time);
        }
        printf("Scenario #%d:\n", ++i);
        scanf("%d", &n);
        for(int j=0; j<n; ++j)
        {
            scanf("%s", str);
            Query(str);
        }
        printf("\n");
    }
    return 0;
}
