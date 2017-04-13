#include <cstdio>
#include <algorithm>

#define n 4
#define p1 'X'
#define p2 'O'

char board[n][n];

bool won_row(int col, char c)
{
	for (int i=0; i<n; i++)
		if (board[i][col]==c||board[i][col]=='.')
			return false;
	return true;
}

bool won_col(int row, char c)
{
	for (int i=0; i<n; i++)
		if (board[row][i]==c||board[row][i]=='.')
			return false;
	return true;
}

bool won_d1(char c)
{
	for (int i=0; i<n; i++)
		if (board[i][i]==c||board[i][i]=='.')
			return false;
	return true;
}

bool won_d2(char c)
{
	for (int i=n-1; i>=0; i--)
		if (board[n-i-1][i]==c||board[n-i-1][i]=='.')
			return false;
	return true;
}

int t;

bool try_won(char c)
{
	for (int i=0; i<n; i++)
		if (won_row(i,c)||won_col(i,c))
			return true;
	return (won_d1(c)||won_d2(c));
}

int main()
{
	scanf("%d", &t);
	char buf[n+1];
	bool full;
	for (int i=0; i<t; i++)
	{
		full=true;
		for (int j=0; j<n; j++)
		{
			scanf("%s", buf);
			for (int k=0; k<n; k++)
			{
				board[j][k]=buf[k];
				if (board[j][k]=='.') full=false;
			}
		}
		
		printf("Case #%d: ", i+1);

		if (try_won(p2))
			printf("X won\n");
		else if (try_won(p1))
			printf("O won\n");
		else if (full)
			printf("Draw\n");
		else
			printf("Game has not completed\n");
		
	}
	return 0;
}
