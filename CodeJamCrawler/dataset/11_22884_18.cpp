#include <cstdio>

int T,R,C;
char table[50][50];

void init()
{
	scanf("%d%d\n",&R,&C);
	for (int i = 0; i < R; i++)
		gets(table[i]);
}
bool work()
{
	int i,j;
	
	for (i = 0; i < R; i++)
		for (j = 0; j < C; j++)
		{
			if (table[i][j] == '#')
			{
				if (i + 1 == R || j + 1 == C)
					return false;
				if (table[i+1][j] == '#' && table[i][j+1] == '#' && table[i+1][j+1] == '#')
				{
					table[i][j] = table[i+1][j+1]= '/';
					table[i+1][j] = table[i][j+1]= '\\';
				}
				else
					return false;
			}
		}
	return true;
}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&T);
	for (int i = 1; i <= T; i++)
	{
		init();		
		printf("Case #%d:\n", i);
		if (work())
		{
			for (int j = 0; j < R; j++)
				printf("%s\n",table[j]);
		}
		else
			printf("Impossible\n");		
	}

	return 0;
}