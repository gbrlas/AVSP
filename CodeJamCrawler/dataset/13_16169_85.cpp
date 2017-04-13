#include <cstdio>

const unsigned MAXN = 11;

int lw[MAXN][MAXN];
int n, m;

bool tryMawnRow(int r)
{
	for(int c = 0; c < m; c++)
	{
		if(lw[r][c] == 2)
			return false;
	}

	for(int c = 0; c < m; c++)
		lw[r][c] = 0;


	return true;
};

bool tryMawnCol(int c)
{
	for(int r = 0; r < n; r++)
	{
		if(lw[r][c] == 2)
			return false;
	}

	for(int r = 0; r < n; r++)
		lw[r][c] = 0;


	return true;
};

bool solve()
{
	for(int r=0; r<n; r++)
	{
		for(int c=0; c<m; c++)
		{
			if(lw[r][c] != 1)
				continue;
			if(tryMawnRow(r))
				continue;
			else if(tryMawnCol(c))
				continue;
			else
				return false;
		}
	}

	return true;
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d\n", &T);

	for(int t = 1; t <= T; t++)
	{
		scanf("%d%d", &n, &m);
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
				scanf("%d", &lw[i][j]);
		}

		//for(int i=0; i<n; i++)
		//{
		//	for(int j=0; j<m; j++)
		//		printf("%d ", lw[i][j]);
		//	printf("\n");
		//}



		bool ans = solve();
		printf("Case #%d: %s\n", t, ans ? "YES" : "NO");

	}

	return 0;
}