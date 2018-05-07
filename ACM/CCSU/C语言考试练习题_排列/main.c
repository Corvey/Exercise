main()
{
    int a[4], t, x, p, b[6]={1,2,2,1,1,2};
    while(~scanf("%d%d%d%d",a,a+1,a+2,a+3))
    {
        p = 0;
        for(int i=3; i>=0; --i)
        {
            int j=0;
            for(int m=0; m<3; ++m, ++j)
            {
                if(j==i)
                    j=(j+1)%4;
                for(int k=0; k<2; ++k)
                {
                    x = b[p];
                    printf("%d ", a[j]);
                    t = j;
                    for(int n=x; n>0; --n)
                    {
                        t = (t+1)%4;
                        if(t==i)
                            ++n;
                    }
                    printf("%d ", a[t]);
                    for(int n=x; n>0; --n)
                    {
                        t = (t+1)%4;
                        if(t==i)
                            ++n;
                    }
                    printf("%d\n", a[t]);
                    p = (p+1)%6;
                }
            }
        }
    }
}
