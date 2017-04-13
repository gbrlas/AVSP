#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100 + 10;

int a[maxn];
int f[maxn][256];
int D, I, m, n;

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("b.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase)
	{
		scanf("%d%d%d%d", &D, &I, &m, &n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

		int ans = -1;
		memset(f, -1, sizeof(f));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < 256; ++j)
			{
				f[i][j] = i * D + abs(j - a[i]);

				int tmp = abs(j - a[i]);
				for (int x = 0; x < i; ++x)
					for (int y = 0; y < 256; ++y)
						if (f[x][y] != -1)
						{
							if (m != 0)
							{
								int num = abs(y - j) / m;
								if (abs(y - j) % m) ++num;
								if (num) --num;
								if (f[x][y] + tmp + D * (i - x - 1) + I * num < f[i][j]) f[i][j] = f[x][y] + tmp + D * (i - x - 1) + I * num;
							}
							else
								if (y == j && f[x][y] + tmp + D * (i - x - 1) < f[i][j]) f[i][j] = f[x][y] + tmp + D * (i - x - 1);
						}

				if (i == n - 1)
					if (ans == -1 || f[i][j] < ans) ans = f[i][j];
			}

		printf("Case #%d: %d\n", nCase, ans);
	}

	return 0;
}
