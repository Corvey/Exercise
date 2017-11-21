const long long int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000, 121645100408832000, 2432902008176640000};
int Cantor(void)
{
    static int t, ans;
    ans = 0;
    for(int i=0; i<8; ++i)
    {
        t = 0;
        for(int j=i+1; j<8; ++j)
            if(a[i] > a[j])
                ++t;
        ans += t * fact[7 - i];
    }
    return ans;
}
int* uncantor(int x, int k)
{
    int res[21];
    int i, j, l, t;
    bool h[21] = {0};
    for (i=1; i<=k; ++i)
    {
        t = x / fact[k - i];
        x -= t * fact[k - i];
        for(j=1, l=0; l<=t; ++j)
            if(!h[j])
                l++;
        j--;
        h[j] = true;
        res[i - 1] = j;
    }
    return res;
}