#include <cstdio>
#include <string.h>
const int N = 5, M = 6, NM = N*M, dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
int a[NM], sum;
bool b[NM];
void init(void)
{
    int x, y;
    for(int i=0, t=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j, ++t)
        {
            a[t] = 1 << (NM - 1 - i * M - j);
            for(int k=0; k<4; ++k)
            {
                x = i + dx[k];
                y = j + dy[k];
                if(x >= 0 && x < N && y >= 0 && y < M)
                    a[t] |= 1 << (NM - 1 - x * M - y);
            }
        }
    }
    sum = 0;
}
int Gauss(void)
{
    bool flag, msflag = false;
    int temp, tar;
    for(int i=0; i<NM; ++i)
    {
        tar = 1 << (NM - 1 - i);
        for(int j=i; j<NM; ++j)
        {
            flag = false;
            if( (a[j] & tar) == tar )
            {
                flag = true;
                if(i == j)
                    break;
                temp = a[i], a[i] = a[j] , a[j] = temp;
                temp = b[i], b[i] = b[j], b[j] = temp;
                break;
            }
        }
        if(!flag)
        {
            msflag = true;
            break;
        }
        for(int j=i+1; j<NM; ++j)
            if( (a[j] & tar) == tar )
                a[j] ^= a[i], b[j] ^= b[i];
    }
    for(int i=0; i<NM; ++i)
        if(!a[i] && b[i])
            return 0;
    if(msflag)
        return -1;
    for(int i=NM-1; i; --i)
    {
        for(int j=i-1; ~j; --j)
            if( (a[j] & a[i]) == a[i] )
                a[j] ^= a[i], b[j] ^= b[i];
        sum += b[i];
    }
    sum += b[0];
    return 0;
}
int main(void)
{
    init();
    for(int i=0, t=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j, ++t)
            b[t] = getchar() == '0' ? 1 : 0;
        getchar();
    }
    Gauss();
    printf("%d\n", sum);
    for(int i=0; i<NM; ++i)
        if(b[i])
            printf("%d %d\n", i/M+1, i%M+1);
    return 0;
}
