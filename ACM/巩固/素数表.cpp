int prime[N], nop;
bool IsPrime[N];
int work(int n)
{
    int t;
    memset(IsPrime, 1, sizeof(IsPrime));
    nop = 0;
    for(int i=2; i<n; ++i)
    {
        if(IsPrime[i])
            prime[nop++] = i;
        for(int j=0; j<nop; ++j)
        {
            t = i * prime[j];
            if(t > N)
                break;
            IsPrime[t] = false;
            if(!(i % prime[j]))
                break;
        }
    }
    return nop;
}