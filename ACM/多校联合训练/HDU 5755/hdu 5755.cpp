#include <cstdio>
#include <string.h>
const int N = 910, dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
int n, m, nm, a[N][N], b[N], temp[N], ans;
void init(void) //初始化矩阵
{
    int x, y;
    memset(a, 0, sizeof(a));
    for(int i=0, t=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j, ++t)
        {
            a[t][i*m+j] = 2;
            for(int k=0; k<4; ++k)
            {
                x = i + dy[k];
                y = j + dx[k];
                if(x >= 0 && x < n && y >= 0 && y < m)
                    a[t][x*m+y] = 1;
            }
        }
    }
    ans = 0;
    nm = n * m; 
}
inline void exchange(int x, int y) //位置变换
{
    memcpy(temp, a[x], sizeof(temp));
    memcpy(a[x], a[y], sizeof(temp));
    memcpy(a[y], temp, sizeof(temp));
    temp[0] = b[x];
    b[x] = b[y];
    b[y] = temp[0];
}
inline void elimination(int dst, int src, int col) //倍法+消法变换
{
    if(a[dst][col] > a[src][col])
    {
        for(int i=0; i<nm; ++i)
            a[dst][i] = (a[dst][i] + 6 - 2 * a[src][i]) % 3;
        b[dst] = (b[dst] + 6 - 2 * b[src]) % 3;
    }
    else if(a[dst][col] < a[src][col])
    {
        for(int i=0; i<nm; ++i)
            a[dst][i] = (2 * a[dst][i] + 6 - a[src][i]) % 3;
        b[dst] = (2 * b[dst] + 6 - b[src]) % 3;
    }
    else
    {
        for(int i=0; i<nm; ++i)
            a[dst][i] = (a[dst][i] + 3 - a[src][i]) % 3;
        b[dst] = (b[dst] + 3 - b[src]) % 3;
    }
}
bool judge(int dst) //判断是否有解
{
    for(int i=0; i<nm; ++i)
        if(a[dst][i])
            return true;
    return false;
}
void work(int r)
{
    printf("%d\n", ans);
    int x, y;
    for(int i=0; i<r; ++i)
    {
        if(b[i])
        {
            x = i / m + 1;
            y = i % m + 1;
            if(a[i][i] != b[i])
                printf("%d %d\n", x, y);
            else
                printf("%d %d\n%d %d\n", x, y, x, y);
        }
    }
}
int gauss(void) //高斯消元
{
    int r = 0;
    bool tag;
    for(int i=0, col=0; col<nm; ++col, ++i) //将矩阵转换成上三角
    {
        if(!a[i][col])  //将第col列不为0的行变换到当前行
        {
            tag = true;
            for(int j=i+1; j<nm; ++j)
            {
                if(a[j][col])
                {
                    tag = false;
                    exchange(i, j);
                    break;
                }
            }
            if(tag) //找不到第col列不为0的行
            {
                --i;
                continue;
            }
        }
        ++r;
        for(int j=i+1; j<nm; ++j)   //消去其他行的第col列
            if(a[j][col])
                elimination(j, i, col);
    }
    for(int i=0; i<nm; ++i)
        if(!judge(i) && b[i])   //无解
            return 0;
    for(int i=r-1; i>=0; --i)    //将上三角矩阵转换为对角矩阵
    {
        if(b[i])
            ans += a[i][i] == b[i] ? 2 : 1;
        for(int j=i-1; j>=0; --j)
            if(a[j][i])
                elimination(j, i, i);
    }
    work(r);
}
int main(void)
{
    int kase;
    scanf("%d", &kase);
    while(kase--)
    {
        scanf("%d %d", &n, &m);
        init();
        for(int i=0, t=0; i<n; ++i)
            for(int j=0; j<m; ++j, ++t)
                scanf("%d", b+t);
        gauss();
    }
}
