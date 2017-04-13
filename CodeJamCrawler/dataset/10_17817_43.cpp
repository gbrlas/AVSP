#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxk = 51 + 10;

char a[maxk * 2][maxk * 2];
char s[maxk * 2];
int k;

int cal(int x)
{
	return (1 + x) * x / 2 + x * (x - 1) / 2;
}

int check(int x, int y)
{
	int K = k + abs(x - (k - 1)) + abs(y - (k - 1));
	for (int i = 0; i < k * 2 - 1; ++i)
	{
		int l = y, r = y, len = strlen(a[i]);
		while (l >= 0 && r < k * 2 - 1)
		{
			if (a[i][l] != ' ' && a[i][r] != ' ' && a[i][l] != a[i][r]) return -1;
			--l; ++r;
		}

		l = x, r = x;
		while (l >= 0 && r < k * 2 - 1)
		{
			if (a[l][i] != ' ' && a[r][i] != ' ' && a[l][i] != a[r][i]) return -1;
			--l; ++r;
		}
	}

	return cal(K) - cal(k);
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase)
	{
		scanf("%d", &k);
		gets(s);
		for (int i = 0; i < k * 2 - 1; ++i)
		{
			gets(a[i]);
			int l = strlen(a[i]);
			for (int j = l; j < k * 2 - 1; ++j) a[i][j] = ' ';
			a[i][k * 2 - 1] = 0;
		}

		int ans = -1;
		for (int i = 0; i < k * 2 - 1; ++i)
			for (int j = 0; j < k * 2 - 1; ++j)
			{
				int res = check(i, j);
				if (res != -1)
					if (ans == -1 || res < ans) ans = res;
			}

		printf("Case #%d: %d\n", nCase, ans);
	}

	return 0;
}
