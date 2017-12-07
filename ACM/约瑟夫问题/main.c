#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int die = 0, time = 0;
    int people[41] = {0};
    for(int i=0; die<39; i++)
    {
        i %= 41;
        if(people[i])
            continue;
        time++;
        if(time==3)
        {
            time = 0;
            printf("%d->", i+1);
            people[i] = 1;
            ++die;
        }
    }
    return 0;
}
