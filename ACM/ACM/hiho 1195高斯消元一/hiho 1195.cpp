#include <cstdio>
#include <string.h>
#include <math.h>
const double eps = 1e-6;
const int N = 510, M = 1050;
int n, m, SIZE;
double a[M][N], b[M], temp[N];
void SwapRow(int x, int y)  //��������
{
    memcpy(temp, a[x], SIZE);
    memcpy(a[x], a[y], SIZE);
    memcpy(a[y], temp, SIZE);
    temp[0] = b[x];
    b[x] = b[y];
    b[y] = temp[0];
}
void TransformRow(int Dst, int Src, int col)    //��ȥ
{
    double k = a[Src][col] / a[Dst][col];
    for(int i=0; i<n; ++i)
        a[Dst][i] = a[Dst][i] * k - a[Src][i];
    b[Dst] = b[Dst] * k - b[Src];
}
bool judge(int Dst) //�ж�ĳ���Ƿ�ȫΪ0
{
    for(int i=0; i<n; ++i)
        if(fabs(a[Dst][i]) >= eps)
            return true;
    return false;
}
int Gauss(void) //��˹��Ԫ������0���޽⣬����-1�����⣬����1��Ψһ��
{
    bool flag, msflag = false;
    for(int i=0; i<n; ++i)  //���Խ�ԭ����任Ϊ�����Ǿ���
    {
        flag = false;   //��ǵ�i���Ƿ����ҵ���Ϊ0����
        for(int j=i; j<m; ++j)  //�ӵ�i�п�ʼѰ��ʹ��a[i][i]��Ϊ0����
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
        if(!flag)   //�Ҳ��������ж����
        {
            msflag = true;
            continue;
        }
        for(int j=i+1; j<m; ++j)    //�ӵ�i+1������ȥ��i��
        {
            if(fabs(a[j][i]) <= eps)
                continue;
            TransformRow(j, i, i);
        }
    }
    for(int i=0; i<m; ++i)  //�ж��Ƿ��޽�
        if(!judge(i) && fabs(b[i]) >= eps)
            return 0;
    if(msflag)  //�Ƿ���ڶ����
        return -1;
    //��Ψһ��
    for(int i=n-1; i; --i)  //�������Ǿ���任Ϊ�ԽǾ���
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
