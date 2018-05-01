#include <cstdio>
#include <string.h>
const int N = 5, M = 6, dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
int a[N*M][N*M], b[N*M], temp[N*M], sum;
void pf(void)
{
    printf("\n");
    for(int i=0; i<N*M; ++i)
    {
        for(int j=0; j<N*M; ++j)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\n");
}
void init(void)
{
    int x, y;
    memset(a, 0, sizeof(a));
    for(int i=0, t=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j, ++t)
        {
            a[t][i*M+j] = 1;
            for(int k=0; k<4; ++k)
            {
                x = i + dx[k];
                y = j + dy[k];
                if(x >= 0 && x < N && y >= 0 && y < M)
                    a[t][x*M+y] = 1;
            }
        }
    }
    sum = 0;
}
void SwapRow(int x, int y)
{
    memcpy(temp, a[x], sizeof(temp));
    memcpy(a[x], a[y], sizeof(temp));
    memcpy(a[y], temp, sizeof(temp));
    temp[0] = b[x];
    b[x] = b[y];
    b[y] = temp[0];
}
void TransformRow(int Dst, int Src)
{
    for(int i=0; i<N*M; ++i)
        a[Dst][i] ^= a[Src][i];
    b[Dst] ^= b[Src];
}
bool judge(int x)
{
    for(int i=0; i<N*M; ++i)
        if(a[x][i] != 0)
            return true;
    return false;
}
int Gauss(void)
{
    bool flag, msflag = false;
    for(int i=0; i<N*M; ++i)
    {
        flag = false;
        for(int j=i; j<N*M; ++j)
        {
            if(a[j][i])
            {
                flag = true;
                if(i == j)
                    break;
                SwapRow(i, j);
                break;
            }
        }
        if(!flag)
        {
            msflag = true;
            break;
        }
        for(int j=i+1; j<N*M; ++j)
        {
            if(!a[j][i])
                continue;
            TransformRow(j, i);
        }
    }
    for(int i=0; i<N*M; ++i)
        if(!judge(i) && b[i])
            return 0;
    if(msflag)
        return -1;
    for(int i=N*M-1; i; --i)
    {
        for(int j=i-1; ~j; --j)
            if(a[j][i])
                TransformRow(j, i);
        if(b[i])
            ++sum;
    }
    sum += b[0];
    return 1;
}
int main(void)
{
    for(int i=0, t=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j, ++t)
            b[t] = getchar() == '0' ? 1 : 0;
        getchar();
    }
    init();
    Gauss();
    printf("%d\n", sum);
    for(int i=0; i<N*M; ++i)
        if(b[i])
            printf("%d %d\n", i/M+1, i%M+1);
    return 0;
}
