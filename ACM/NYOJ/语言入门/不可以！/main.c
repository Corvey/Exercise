
int main(void)
{
    int x, y;
    while(scanf("%d%d", &x, &y) != EOF)
    {
        if(x && y)
        {
            if(x * y - abs(x*y))
                printf("Signs are opposite\n");
            else
                printf("Signs are not opposot\n");
        }
        else
            printf("Signs can't be sure\n");
    }
}
