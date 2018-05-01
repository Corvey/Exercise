#include <cstdio>
#include <string.h>
#include <math.h>
const double eps = 1e-6;
const int N = 510, M = 1050;
int n, m, SIZE;
double a[M][N], b[M], temp[N];
void SwapRow(int x, int y)  //交换两行
{
    memcpy(temp, a[x], SIZE);
    memcpy(a[x], a[y], SIZE);
    memcpy(a[y], temp, SIZE);
    temp[0] = b[x];
    b[x] = b[y];
    b[y] = temp[0];
}
void TransformRow(int Dst, int Src, int col)    //消去
{
    double k = a[Src][col] / a[Dst][col];
    for(int i=0; i<n; ++i)
        a[Dst][i] = a[Dst][i] * k - a[Src][i];
    b[Dst] = b[Dst] * k - b[Src];
}
bool judge(int Dst) //判断某行是否全为0
{
    for(int i=0; i<n; ++i)
        if(fabs(a[Dst][i]) >= eps)
            return true;
    return false;
}
int Gauss(void) //高斯消元，返回0则无解，返回-1则多个解，返回1则唯一解
{
    bool flag, msflag = false;
    for(int i=0; i<n; ++i)  //尝试将原矩阵变换为上三角矩阵
    {
        flag = false;   //标记第i列是否能找到不为0的行
        for(int j=i; j<m; ++j)  //从第i行开始寻找使得a[i][i]不为0的行
        {
            if(fabs(a[j][i]) >= eps)
            {
                flag = true;
                if(j == i)
                    break;
                SwapRow(i, j);
                break;
            }
        }
        if(!flag)   //找不到，即有多个解
        {
            msflag = true;
            continue;
        }
        for(int j=i+1; j<m; ++j)    //从第i+1行起消去第i列
        {
            if(fabs(a[j][i]) <= eps)
                continue;
            TransformRow(j, i, i);
        }
    }
    for(int i=0; i<m; ++i)  //判断是否无解
        if(!judge(i) && fabs(b[i]) >= eps)
            return 0;
    if(msflag)  //是否存在多个解
        return -1;
    //有唯一解
    for(int i=n-1; i; --i)  //将上三角矩阵变换为对角矩阵
    {
        for(int j=i-1; ~j; --j)
        {
            if(fabs(a[j][i]) <= eps)
                continue;
            TransformRow(j, i, i);
        }
    }
    return 1;
}
int main(void)
{
    int ans;
    while(~scanf("%d %d", &n, &m))
    {
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
                scanf("%lf", a[i]+j);
            scanf("%lf", b+i);
        }
        SIZE = n * sizeof(double);
        ans = Gauss();
        if(!ans)
            printf("No solutions\n");
        else if(ans == -1)
            printf("Many solutions\n");
        else
            for(int i=0; i<n; ++i)
                printf("%d\n", (int)(b[i] / a[i][i] + 0.5));
    }
}
