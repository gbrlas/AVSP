#include <iostream>
using namespace std;

int main ()
{
	//freopen ("D:\\Users\\Lee\\Desktop\\A-small-attempt0.in", "r", stdin);
	//freopen ("D:\\Users\\Lee\\Desktop\\A-small-attempt0.out", "w", stdout);
	freopen ("D:\\Users\\Lee\\Desktop\\A-large.in", "r", stdin);
	freopen ("D:\\Users\\Lee\\Desktop\\A-large.out", "w", stdout);
	int t, n, k;
	char gx[60][60], g[60][60];
	scanf("%d", &t);
	for (int ncase = 1; ncase <= t; ncase++)
	{
		bool red = false, blue = false;
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", gx[i]);
			for (int j = 0; j < n; j++)
				g[i][j] = '.';
		}
		for (int i = n - 1; i >= 0; i--)
			for (int ii = n, j = n - 1; j >= 0; j--)
				if (gx[i][j] != '.')
					g[--ii][n - 1 - i] = gx[i][j];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (red && blue)
					break;
				if (g[i][j] == '.')
					continue;
				int c[4];
				c[0] = c[1] = c[2] = c[3] = 1;
				for (int jj = j - 1; jj >= 0; jj--)
				{
					if (g[i][jj] == g[i][j])
						c[0]++;
					else
						break;
				}
				for (int jj = j + 1; jj < n; jj++)
				{
					if (g[i][jj] == g[i][j])
						c[0]++;
					else
						break;
				}
				for (int ii = i - 1; ii >= 0; ii --)
				{
					if (g[ii][j] == g[i][j])
						c[1]++;
					else
						break;
				}
				for (int ii = i + 1; ii < n; ii ++)
				{
					if (g[ii][j] == g[i][j])
						c[1]++;
					else
						break;
				}
				for (int ii = i - 1, jj = j - 1; ii >= 0 && jj >= 0; ii--, jj--)
				{
					if (g[ii][jj] == g[i][j])
						c[2]++;
					else
						break;
				}
				for (int ii = i + 1, jj = j + 1; ii < n && jj < n; ii++, jj++)
				{
					if (g[ii][jj] == g[i][j])
						c[2]++;
					else
						break;
				}
				for (int ii = i - 1, jj = j + 1; ii >= 0 && jj < n; ii--, jj++)
				{
					if (g[ii][jj] == g[i][j])
						c[3]++;
					else
						break;
				}
				for (int ii = i + 1, jj = j - 1; ii < n && jj >= 0; ii++, jj--)
				{
					if (g[ii][jj] == g[i][j])
						c[3]++;
					else
						break;
				}
				for (int kk = 0; kk < 4; kk++)
					if (c[kk] >= k)
					{
						if (g[i][j] == 'R')
							red = true;
						if (g[i][j] == 'B')
							blue = true;
					}
			}
			printf("Case #%d: ", ncase);
			if (red && blue)
				printf("Both");
			if (red && !blue)
				printf("Red");
			if (!red && blue)
				printf("Blue");
			if (!red && !blue)
				printf("Neither");
			printf("\n");
	}
}