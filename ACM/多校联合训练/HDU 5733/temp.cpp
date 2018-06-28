#include <cstdio>
#include <math.h>
const double eps = 1e-6;
const int t[4][3] = {0,1,3,0,2,4,2,1,5,4,5,3};
double x[5], y[5], z[5], pm[4], len[6], c[4], s[5], r, temp;
int main(void)
{
    while(~scanf("%lf %lf %lf", x, y, z))
    {
        scanf("%lf %lf %lf", x+1, y+1, z+1);
        scanf("%lf %lf %lf", x+2, y+2, z+2);
        scanf("%lf %lf %lf", x+3, y+3, z+3);
        pm[0] = (y[1] - y[0]) * (z[2] - z[0]) - (z[1] - z[0]) * (y[2] - y[0]);
        pm[1] = (z[1] - z[0]) * (x[2] - x[0]) - (z[2] - z[0]) * (x[1] - x[0]);
        pm[2] = (x[1] - x[0]) * (y[2] - y[0]) - (y[1] - y[0]) * (x[2] - x[0]);
        pm[3] = 0 - pm[0] * x[0] - pm[1] * y[0] - pm[2] * z[0];
        r = fabs( pm[0] * x[3] + pm[1] * y[3] + pm[2] * z[3] + pm[3] );
        if(r < eps)
            printf("O O O O\n");
        else
        {
            for(int i=0, n=0; i<4; ++i)
                for(int j=i+1; j<4; ++j)
                    len[n++] = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) + (z[i]-z[j])*(z[i]-z[j]));
            x[4] = y[4] = z[4] = s[4] = 0;
            for(int i=0; i<4; ++i)
            {
                c[i] = 0;
                for(int j=0; j<3; ++j)
                    c[i] += len[t[i][j]];
                c[i] /= 2;
                temp = c[i];
                for(int j=0; j<3; ++j)
                    temp *= c[i] - len[t[i][j]];
                s[i] = sqrt(temp);
                x[4] += s[i] * x[3-i];
                y[4] += s[i] * y[3-i];
                z[4] += s[i] * z[3-i];
                s[4] += s[i];
            }
            r = s[0] / s[4] * r / sqrt( pm[0]*pm[0] + pm[1]*pm[1] + pm[2]*pm[2] );
            printf("%.4lf %.4lf %.4lf %.4lf\n", x[4]/s[4], y[4]/s[4], z[4]/s[4], r);
        }
    }
    return 0;
}
