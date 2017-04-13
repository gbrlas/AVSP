#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 101;

bool a[maxn][maxn], b[maxn][maxn];
int r;

bool find(int x, int y)
{
	if (x < 0 || x > 100 || y < 0 || y > 100) return 0;
	return a[x][y];
}

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("c.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase)
	{
		scanf("%d", &r);
		memset(a, 0, sizeof(a));
		for (int i = 0; i < r; ++i)
		{
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			for (int j = x1; j <= x2; ++j)
				for (int k = y1; k <= y2; ++k)
					a[j][k] = 1;
		}

		int ans = 0;
		while (1)
		{
			bool flag = 0;
			memset(b, 0, sizeof(b));
			for (int i = 0; i <= 100; ++i)
				for (int j = 0; j <= 100; ++j)
					if (a[i][j])
					{
						flag = 1;
						if (!find(i - 1, j) && !find(i, j - 1)) b[i][j] = 0;
						else b[i][j] = 1;
					}
					else
					{
						if (find(i - 1, j) && find(i, j - 1)) b[i][j] = 1;
						else b[i][j] = 0;
					}
			if (!flag) break;
			++ans;
			memcpy(a, b, sizeof(b));
		}

		printf("Case #%d: %d\n", nCase, ans);
	}

	return 0;
}
