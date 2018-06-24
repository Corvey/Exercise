#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 20, M = 200;
int pailie[10], u[M], v[M], Next[M], first[N], match[N];
bool vis[N] = {0}, ban[N][N];
void AddEdge(int from, int to, int t)
{
    u[t] = from, v[t] = to;
    Next[t] = first[from];
    first[from] = t;
}
bool Find(int from)
{
    for(int x=first[from]; ~x; x=Next[x])
    {
        if(!vis[v[x]])
        {
            vis[v[x]] = true;
            if(!~match[v[x]] || Find(match[v[x]]))
            {
                match[v[x]] = from;
                match[from] = v[x];
                return true;
            }
        }
    }
    return false;
}
int main(void)
{
    int n, m, a, b, pipei, ans;
    while(~scanf("%d %d", &n, &m))
    {
        for(int i=0; i<m; ++i)
        {
            scanf("%d %d", &a, &b);
            ban[a-1][b-1] = true;
        }
        //初始化阴宝石排列
        for(int i=0; i<n; ++i)
            pailie[i] = i;
        pailie[n] = 0;
        //由于是环排列，所以可以固定1不动，只排后面的n-1个数，最后在末尾添上1方便操作
        ans = 9;   //初试化ans为极大值
        do
        {
            memset(first, -1, sizeof(first));
            for(int i=0, t=0; i<n; ++i) //阴宝石的各个位置
            {
                a = pailie[i];
                b = pailie[i+1];
                for(int j=0; j<n; ++j)  //尝试在阴宝石的各个位置中放入阳宝石
                {
                    //ban[x][y] = true表示阳宝石x不能和阴宝石y放在一起
                    if(!ban[j][a] && !ban[j][b])    //若能放则建边
                    {
                        AddEdge(a+n, j, t++);   //小于n的结点表示阳宝石，大于n的表示阴宝石
                        AddEdge(j, a+n, t++);
                    }
                }
            }
            //匈牙利算法求最大匹配
            pipei = 0;
            memset(match, -1, sizeof(match));
            for(int i=0; i<n; ++i)
            {
                if(!~match[i])
                    pipei += Find(i);
                memset(vis, 0, sizeof(vis));
            }
            pipei = n - pipei;
            ans = pipei < ans ? pipei : ans;

        } while (ans && next_permutation(pailie+1, pailie+n));  //ans = 0时跳出循环这个剪枝在数据庞大时重要
        printf("%d\n", ans);
        memset(ban, 0, sizeof(ban));
    }
    return 0;
}
