#include <cstdio>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e5+10, M = 2e6+10;
int u[M], v[M], w[M], first[N], Next[M];
bool vis[N] = {0};
struct cmp{
    bool operator () (int &a, int &b) const {
        return w[a] > w[b];
}};
int Prim(int n)
{
    int ans = 0, t;
    priority_queue<int, vector<int>, cmp> pq;
    for(int x=first[0]; ~x; x=Next[x])
        pq.push(x);
    vis[0] = true;
    --n;
    while(n)
    {
        t = pq.top();
        pq.pop();
        if(vis[v[t]])
            continue;
        ans += w[t];
        --n;
        vis[v[t]] = true;
        for(int x=first[v[t]]; ~x; x=Next[x])
            if(!vis[v[x]])
                pq.push(x);
    }
    return ans;
}
int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    memset(first, -1, sizeof(first));
    m <<= 1;
    for(int i=0; i<m; )
    {
        scanf("%d %d %d", u+i, v+i, w+i);
		--u[i], --v[i];
        Next[i] = first[u[i]];
        first[u[i]] = i++;

        u[i] = v[i-1], v[i] = u[i-1], w[i] = w[i-1];
        Next[i] = first[u[i]];
        first[u[i]] = i++;
    }
    printf("%d\n", Prim(n));
}
