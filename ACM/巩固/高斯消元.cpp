double a[M][N], b[M];
inline void eliminate(int dst, int src, int col)	//消元
{
    static double k;
    k = a[src][col] / a[dst][col];
    for(int i=0; i<n; ++i)
        a[dst][i] = a[dst][i] * k - a[src][i];
    b[dst] = b[dst] * k - b[src];
}
int gauss(void)
{
    bool mstag, tag;
    mstag = false;
    for(int row=0, col=0; col<n; ++col)
    {
        if(fabs(a[row][col]) <= eps)
        {
            tag = true;
            for(int j=row+1; j<m; ++j)
            {
                if(fabs(a[j][col]) > eps)
                {
                    SWAP(row, j);
                    tag = false;
                    break;
                }
            }
            if(tag)
            {
                mstag = true;
                continue;
            }
        }
        for(int j=row+1; j<m; ++j)
            if(fabs(a[j][col]) > eps)
                eliminate(j, row, col);
        ++row;
    }
    for(int i=0; i<m; ++i)
        if(judge(i))
            return 0;   //无解
    if(mstag)
        return -1;  //多解
    for(int i=n-1; i; --i)
        for(int j=i-1; ~j; --j)
            if(fabs(a[j][i]) > eps)
                eliminate(j, i, i);
    return 1;	//唯一解
}