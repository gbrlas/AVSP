#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxp = 10 + 2;

int f[maxp][maxp][1 << maxp];
int a[maxp][1 << maxp];
int M[1 << maxp];
int p;

void solve(int x)
{
	if (x == p - 1)
	{
		for (int i = 0; i < (1 << x); ++i)
		{
			int y = p - M[i << 1];
			if (p - M[(i << 1) + 1] > y) y = p - M[(i << 1) + 1];
			f[x][y][i] = 0;
			for (int j = 0; j < p; ++j)
				if (f[x][j][i] != -1)
					if (f[x][j + 1][i] == -1 || f[x][j][i] < f[x][j + 1][i]) f[x][j + 1][i] = f[x][j][i];
		}
		return;
	}

	solve(x + 1);
	for (int i = 0; i < (1 << x); ++i)
	{
		for (int j = 0; j < p; ++j)
		{
			int res = f[x + 1][j][i << 1];
			if (f[x + 1][j + 1][i << 1] != -1)
				if (res == -1 || f[x + 1][j + 1][i << 1] + a[x + 1][i << 1] < res) res = f[x + 1][j + 1][i << 1] + a[x + 1][i << 1];
			if (res == -1) continue;

			int tmp = f[x + 1][j][(i << 1) + 1];
			if (f[x + 1][j + 1][(i << 1) + 1] != -1)
				if (tmp == -1 || f[x + 1][j + 1][(i << 1) + 1] + a[x + 1][(i << 1) + 1] < tmp) tmp = f[x + 1][j + 1][(i << 1) + 1] + a[x + 1][(i << 1) + 1];
			if (tmp == -1) continue;

			if (f[x][j][i] == -1 || res + tmp < f[x][j][i]) f[x][j][i] = res + tmp;
		}
		for (int j = 0; j < p; ++j)
			if (f[x][j][i] != -1)
				if (f[x][j + 1][i] == -1 || f[x][j][i] < f[x][j + 1][i]) f[x][j + 1][i] = f[x][j][i];
	}
}

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("b.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase)
	{
		scanf("%d", &p);
		int n = 1 << p;
		for (int i = 0; i < n; ++i) scanf("%d", &M[i]);
		for (int i = p - 1; i >= 0; --i)
			for (int j = 0; j < (1 << i); ++j)
				scanf("%d", &a[i][j]);
		
		memset(f, -1, sizeof(f));
		solve(0);

		int ans = f[0][0][0];
		if (f[0][1][0] != -1)
			if (ans == -1 || f[0][1][0] + a[0][0] < ans) ans = f[0][1][0] + a[0][0];

		printf("Case #%d: %d\n", nCase, ans);
	}

	return 0;
}
