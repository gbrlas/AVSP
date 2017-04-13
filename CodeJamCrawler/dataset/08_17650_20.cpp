#include <cstdio>
#include <iostream>

using namespace std;

const int maxn = 200;
const int BASE = 10007;
const int move[2][2] = {-2, -1, -1, -2};

int g[maxn][maxn];
bool f[maxn][maxn];
int n, m, num, x, y;

int main()
{
	freopen("D-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);

	int T;
	scanf("%d", &T);
	for (int tst = 1; tst <= T; ++tst)
	{
		scanf("%d%d%d", &n, &m, &num);

		memset(f, 0, sizeof(f));
		memset(g, 0, sizeof(g));
		g[1][1] = 1;
		for (int i = 1; i <= num; ++i)
		{
			scanf("%d%d", &x, &y);
			f[x][y] = 1;
		}

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				if (!f[i][j])
				{
					for (int k = 0; k < 2; ++k)
						if (i + move[k][0] >= 1 && j + move[k][1] >= 1 && !f[i + move[k][0]][j + move[k][1]]) 
							(g[i][j] += g[i + move[k][0]][j + move[k][1]]) %= BASE;
				}

		printf("Case #%d: %d\n", tst, g[n][m]);
	}

	return 0;
}
