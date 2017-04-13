#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 100 + 10;

int sg[maxn][maxn];
int used[maxn];
int n;

int main()
{
	freopen("C-large.in", "r", stdin);
	freopen("c.out", "w", stdout);

/*
	int col = 0;
	for (int i = 0; i < maxn; ++i) sg[0][i] = sg[i][0] = 1;
	sg[0][0] = 0;
	for (int i = 1; i < maxn; ++i)
	{
		for (int j = 1; j < maxn; ++j)
		{
			++col;
			for (int k = i - j; k >= 0; k -= j) used[sg[k][j]] = col;
			for (int k = j - i; k >= 0; k -= i) used[sg[i][k]] = col;
			sg[i][j] = 0;
			while (used[sg[i][j]] == col) ++sg[i][j];
		}
		int l = 0, r = maxn - 1;
		while (sg[i][l]) ++l;
		while (sg[i][r]) --r;
		printf("%d, %d %d\n", i, l, r);
	}
*/
	
	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase)
	{
		int a1, a2, b1, b2;
		scanf("%d%d%d%d", &a1, &a2, &b1, &b2);

		long long ans = 0;
		for (int i = a1; i <= a2; ++i)
		{
			int l = (int)ceil(i / ((1 + sqrt(5)) / 2)), r = (int)floor(i * ((1 + sqrt(5)) / 2));
			if (b2 < l || b1 > r) ans += b2 - b1 + 1;
			else
			{
				if (b1 < l) ans += l - b1;
				if (r < b2) ans += b2 - r;
			}
		}

		printf("Case #%d: %I64d\n", nCase, ans);
	}

	return 0;
}
