#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;
const int MAXK = 25 + 5; 

int p[MAXN][MAXK];
bool a[MAXN][MAXN];
bool b[MAXN];
int c[MAXN];
int N, K;

bool check(int x, int y)
{
	for (int i = 0; i < K; ++i)
		if (p[x][i] <= p[y][i]) return 0;

	return 1;
}

bool match(int i)
{
	b[i] = 1;
	for (int j = 0; j < N; ++j)
		if (a[i][j])
			if (c[j] == -1 || !b[c[j]] && match(c[j]))
			{
				c[j] = i;
				return 1;
			}
	return 0;
}

int main()
{
	freopen("C-large.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int tst = 1; tst <= T; ++tst)
	{
		scanf("%d%d", &N, &K);
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < K; ++j)
				scanf("%d", &p[i][j]);

		memset(a, 0, sizeof(a));
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				if (check(i, j)) a[i][j] = 1;

		int ans = 0;
		memset(c, -1, sizeof(c));
		for (int i = 0; i < N; ++i)
		{
			memset(b, 0, sizeof(b));
			if (match(i)) ++ans;
		}

		printf("Case #%d: %d\n", tst, N - ans);
	}

	return 0;
}
