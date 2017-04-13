#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

#define MAXI(a,b) ((a)>(b)?(a):(b))
#define MINI(a,b) ((a)<(b)?(a):(b))

#define MAX 128

int mat[MAX][MAX];
int resp[MAX][MAX];

int vai(int a, int b)
{
	if (a <= 0)
		return 0;
	if (b <= 0)
		return 0;
	if (mat[a][b])
		return 0;

	return resp[a][b];
}

int main()
{
	int casos, cas;

	scanf("%d",&casos);

	int m, n;

	for (cas = 1; cas <= casos; cas++)
	{
		scanf("%d %d",&m, &n);
		int i, j;
		for (i=0; i<=m; i++)
		{
			for (j=0; j<=n; j++)
			{
				mat[i][j] = 0;
			}
		}
		int r, a, b;
		scanf("%d",&r);
		for (i=0; i<r; i++)
		{
			scanf("%d %d", &a, &b);
			mat[a][b] = 1;
		
		}

		for (i=1; i<=3; i++)
		{
			for (j=1; j<=3; j++)
			{
				resp[i][j] = 0;
			}
		}

		resp[1][1] = 1;
		

		for (i=1; i<=m; i++)
		{
			for (j=1; j<=n; j++)
			{
				if (i==1 && j==1)
					continue;
				resp[i][j] = (vai(i-1, j-2) + vai(i-2, j-1))%10007;
			}
		}
		for (i=1; i<=m; i++)
		{
			for (j=1; j<=n; j++)
			{
			}
		}
		printf("Case #%d: %d\n", cas, resp[m][n]);
	}

	return 0;
}

