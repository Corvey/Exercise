int PrimeList[N], nop, phi[N];
bool IsPrime[N];
void work(void)
{
    int temp;
    memset(IsPrime, 1, sizeof(IsPrime);
    nop = 0;
    for(int i=2; i<N; ++i)
    {
        if(IsPrime[i])
        {
            PrimeList[nop++] = i;
            phi[i] = i - 1;
        }
        for(int j=0; j<nop; ++j)
        {
            temp = i * PrimeList[j];
            if(temp > N)
                break;
            IsPrime[temp] = false;
            if(i % PrimeList[j] == 0)
            {
                phi[temp] = phi[i] * PrimeList[j];
                break;
            }
            else
                phi[temp] = phi[i] * (PrimeList[j] - 1);
        }
    }
}