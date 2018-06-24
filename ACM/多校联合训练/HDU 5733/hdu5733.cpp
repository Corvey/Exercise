#include <cstdio>
#include <math.h>
const double eps = 1e-6;
struct point{
    double x, y, z;
}A, B, C, D;
double pm[4], d, AB, AC, AD, BC, BD, CD, cABC, cABD, cACD, cBCD, sABC, sABD, sACD, sBCD, sSum, r, ansx, ansy, ansz;
bool judge(void)    //�ж��ĵ��Ƿ���
{
    double temp[6];
    temp[0] = B.x - A.x;
    temp[1] = B.y - A.y;
    temp[2] = B.z - A.z;
    temp[3] = C.x - A.x;
    temp[4] = C.y - A.y;
    temp[5] = C.z - A.z;

    //��ƽ��ABC��ƽ�淽��
    pm[0] = temp[1] * temp[5] - temp[2] * temp[4];
    pm[1] = temp[2] * temp[3] - temp[5] * temp[0];
    pm[2] = temp[0] * temp[4] - temp[1] * temp[3];
    pm[3] = 0 - pm[0] * A.x - pm[1] * A.y - pm[2] * A.z;

    //�ѵ�D���뵽ƽ�淽��
    d = fabs( pm[0] * D.x + pm[1] * D.y + pm[2] * D.z + pm[3] );
    return d < eps;
}
void work(void)
{
    //���߱߳�
    AB = sqrt( (A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y) + (A.z - B.z)*(A.z - B.z) );
    AC = sqrt( (A.x - C.x)*(A.x - C.x) + (A.y - C.y)*(A.y - C.y) + (A.z - C.z)*(A.z - C.z) );
    AD = sqrt( (A.x - D.x)*(A.x - D.x) + (A.y - D.y)*(A.y - D.y) + (A.z - D.z)*(A.z - D.z) );
    BC = sqrt( (C.x - B.x)*(C.x - B.x) + (C.y - B.y)*(C.y - B.y) + (C.z - B.z)*(C.z - B.z) );
    BD = sqrt( (D.x - B.x)*(D.x - B.x) + (D.y - B.y)*(D.y - B.y) + (D.z - B.z)*(D.z - B.z) );
    CD = sqrt( (C.x - D.x)*(C.x - D.x) + (C.y - D.y)*(C.y - D.y) + (C.z - D.z)*(C.z - D.z) );
    
    //�������
    cABC = (AB + AC + BC) / 2;
    sABC = sqrt( cABC * (cABC - AB) * (cABC - AC) * (cABC - BC));

    cABD = (AB + AD + BD) / 2;
    sABD = sqrt( cABD * (cABD - AB) * (cABD - AD) * (cABD - BD));

    cACD = (AD + AC + CD) / 2;
    sACD = sqrt( cACD * (cACD - AD) * (cACD - AC) * (cACD - CD));

    cBCD = (BD + CD + BC) / 2;
    sBCD = sqrt( cBCD * (cBCD - BD) * (cBCD - CD) * (cBCD - BC));

    //���D��ƽ��ABC�ľ���
    d /= sqrt( pm[0]*pm[0] + pm[1]*pm[1] + pm[2]*pm[2] );
    
    sSum = sABC + sABD + sACD + sBCD;
    //������������������������������뾶
    r = sABC / (sSum) * d;
    
    //������������������
    ansx = (sABC * D.x + sABD * C.x + sACD * B.x + sBCD * A.x) / sSum;
    ansy = (sABC * D.y + sABD * C.y + sACD * B.y + sBCD * A.y) / sSum;
    ansz = (sABC * D.z + sABD * C.z + sACD * B.z + sBCD * A.z) / sSum;
    printf("%.4lf %.4lf %.4lf %.4lf\n", ansx, ansy, ansz, r);
}
int main(void)
{
    while(~scanf("%lf %lf %lf", &A.x, &A. y, &A.z))
    {
        scanf("%lf %lf %lf", &B.x, &B. y, &B.z);
        scanf("%lf %lf %lf", &C.x, &C. y, &C.z);
        scanf("%lf %lf %lf", &D.x, &D. y, &D.z);
        if(judge())
            printf("O O O O\n");
        else
            work();
    }
    return 0;
}
