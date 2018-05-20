#include <stdio.h>
int main(void)
{
    char s[20];
    int t, max, maxtag;
    while(~scanf("%s %d", s, &t))
    {
        //getchar();
        if(!t)
        {
            puts(s);
            continue;
        }
        for(int i=0; s[i]; ++i)
        {
            if(s[i] == '9')
                continue;
            max = s[i];
            maxtag = i;
            for(int j=i+1; j-i <= t && s[j]; ++j)
            {
                if(s[j] > max)
                {
                    max = s[j];
                    maxtag = j;
                }
            }
            if(max == s[i])
                continue;
            else
            {
                for(int j=maxtag; j>=i+1; --j)
                    s[j] ^= s[j-1], s[j-1] ^= s[j], s[j] ^= s[j-1];
                t -= maxtag - i;
            }
            if(!t)
                break;
        }
        puts(s);
    }
}
