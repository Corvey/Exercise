#include <cstdio>
#include <string.h>
int a[9][9];
bool cHang[9][10] = {0}, cLie[9][10] = {0}, cGong[9][10] = {0}, flag = false;
void dfs(int hang, int lie)
{
	if(flag)
		return ;
	if(lie == 9)
	{
		if(hang < 8)
			dfs(hang+1, 0);
		else
		{
			for(int i=0; i<9; ++i)
			{
				for(int j=0; j<9; ++j)
					printf("%d ", a[i][j]);
				printf("\n");
			}
			flag = true;
			return ;
		}
	}
	else if(a[hang][lie])
		dfs(hang, lie+1);
	else
	{
		for(int x=1; x<=9; ++x)
		{
			if(!cHang[hang][x] && !cLie[lie][x] && !cGong[hang/3*3+lie/3][x])
			{
				a[hang][lie] = x;
				cHang[hang][x] = true;
				cLie[lie][x] = true;
				cGong[hang/3*3+lie/3][x] = true;
				dfs(hang, lie+1);
				a[hang][lie] = 0;
				cHang[hang][x] = false;
				cLie[lie][x] = false;
				cGong[hang/3*3+lie/3][x] = false;
				
			}
		}
	}
}
int main(void)
{
	int n, x;
	scanf("%d", &n);
	while(n--)
	{
		for(int i=0; i<9; ++i)
		{
			for(int j=0; j<9; ++j)
			{
				scanf("%d", &x);
				a[i][j] = x;
				cHang[i][x] = true;
				cLie[j][x] = true;
				cGong[i/3*3+j/3][x] = true;
			}
		}
		dfs(0, 0);
		flag = false;
		memset(cHang, 0, sizeof(cHang));
		memset(cLie, 0, sizeof(cLie));
		memset(cGong, 0, sizeof(cGong));
	}
}