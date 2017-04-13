#include <stdio.h>

void solveCase()
{
	char picture[50][50];
	int R, C;
	int i,j;
	
	scanf("%d %d", &R, &C);
	
	for (i=0; i<R; i++)
	{
		for (j=0; j<C; j++)
		{
			scanf(" %c", &picture[i][j]);
		}
	}
	
	for (i=0; i<R; i++)
	{
		for (j=0; j<C; j++)
		{
			if (picture[i][j] != '#')
				continue;
			
			if (i == R-1 || j == C-1 || picture[i+1][j] != '#' || picture[i+1][j+1] != '#' || picture[i][j+1] != '#')
			{
				printf("Impossible\n");
				return;
			}
			
			picture[i][j] = '/';
			picture[i+1][j+1] = '/';
			picture[i+1][j] = picture[i][j+1] = '\\';
		}
	}
	
	for (i=0; i<R; i++)
	{
		for (j=0; j<C; j++)
		{
			printf("%c", picture[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int T, i;
	
	scanf("%d", &T);
	
	for (i=0; i<T; i++)
	{
		printf("Case #%d:\n", i+1);
		solveCase();
	}
	
	return 0;
}
