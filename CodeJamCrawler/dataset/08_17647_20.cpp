#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 13;

int f[maxn][1<<11], g[maxn];
int n, m, bit[maxn];
char s[100];

inline bool cal(int mask, int i)
{
	return (mask & bit[i]) == 1;
}

bool check(int mask)
{
	for (int i = 0; i < m-1; ++i)
		if (cal(mask, i) && cal(mask, i+1)) return 0;
	return 1;
}

bool check2(int mask1, int mask2)
{
	for (int i = 0; i < m; +i)
	{
	   if (i < m-1 && cal(mask1, i) && cal(mask2, i + 1)) return 0;
	   if (i > 0 && cal(mask1, i) && cal(mask2, i - 1)) return 0;
	}
	return 1;
}

void work()
{
	memset(f, 0, sizeof(f));
	for (int mask = 0; mask < (1 << m); ++mask)
		if (!(mask & g[1]) && check(mask)) f[1][mask] = __builtin_popcount(mask);

	for (int i = 2; i <= n; ++i)
		for (int mask = 0; mask < (1 << m); ++mask)
			if (!(mask & g[i]) && check(mask)) 
				for (int mask2 = 0; mask2 < (1 << m); ++mask2)
					if (!(mask2&g[i-1]) && check(mask2) && check2(mask, mask2))
						f[i][mask] >?= f[i-1][mask2]+__builtin_popcount(mask);
}

int main()
{
	//freopen("C-small-attempt1.in","r",stdin);
	freopen("c.in", "r", stdin);
//	freopen("a.out","w",stdout);

	int T;

    bit[0] = 1;
	for (int i=1; i<=11; i++) bit[i] = bit[i-1] << 1;

	scanf("%d", &T);
	for (int tst= 1; tst <= T; ++tst)
	{
		scanf("%d%d", &n, &m);
		memset(g, 0, sizeof(g));
		for (int i = 1; i <= n; ++i)
		{
			scanf("%s", s);
			printf("%s\n", s);
			for (int j = 0; j < m; ++j)
			{
				g[i] = g[i] << 1;
				if (s[j] == 'x') g[i] += 1;
			}
		}

		work();

		int ans = 0;
		for (int mask = 0; mask < (1 << m); ++mask) ans >?= f[n][mask];
		printf("Case #%d: %d\n", tst, ans);
	}

	return 0;
}
