#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxm = 10000 + 10;
const int maxnum = 2000000;

int f[2][maxm];
int g[maxm], c[maxm];
int n, m, v;

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	scanf("%d", &n);
	for (int tst = 1; tst <= n; ++tst)
	{
		scanf("%d%d", &m, &v);
		for (int i = 1; i <= m; ++i) f[0][i] = f[1][i] = maxnum;

		for (int i = 1; i <= (m - 1) / 2; ++i) scanf("%d%d", &g[i], &c[i]);
		for (int i = (m - 1) / 2 + 1; i <= m; ++i)
		{
			int l;
			scanf("%d", &l);
			f[l][i] = 0;
		}

		for (int i = (m - 1) / 2; i > 0; --i)
			if (g[i])
			{
				f[0][i] <?= f[0][i * 2] + f[0][i * 2 + 1];
				f[0][i] <?= f[0][i * 2] + f[1][i * 2 + 1];
				f[0][i] <?= f[1][i * 2] + f[0][i * 2 + 1];

				f[1][i] <?= f[1][i * 2] + f[1][i * 2 + 1];

				if (c[i])
				{
					f[1][i] <?= f[0][i * 2] + f[1][i * 2 + 1] + 1;
					f[1][i] <?= f[1][i * 2] + f[0][i * 2 + 1] + 1;
					f[1][i] <?= f[1][i * 2] + f[1][i * 2 + 1] + 1;

					f[0][i] <?= f[0][i * 2] + f[0][i * 2 + 1] + 1;
				}
			}
			else
			{
				f[1][i] <?= f[0][i * 2] + f[1][i * 2 + 1];
				f[1][i] <?= f[1][i * 2] + f[0][i * 2 + 1];
				f[1][i] <?= f[1][i * 2] + f[1][i * 2 + 1];

				f[0][i] <?= f[0][i * 2] + f[0][i * 2 + 1];

				if (c[i])
				{
					f[0][i] <?= f[0][i * 2] + f[0][i * 2 + 1] + 1;
					f[0][i] <?= f[0][i * 2] + f[1][i * 2 + 1] + 1;
					f[0][i] <?= f[1][i * 2] + f[0][i * 2 + 1] + 1;

					f[1][i] <?= f[1][i * 2] + f[1][i * 2 + 1] + 1;
				}
			}

		printf("Case #%d: ", tst);
		if (f[v][1] < maxnum) printf("%d\n", f[v][1]);
		else printf("IMPOSSIBLE\n");
	}

	return 0;
}
