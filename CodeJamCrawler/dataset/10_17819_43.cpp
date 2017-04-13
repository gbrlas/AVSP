#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10000;

int M[maxn];
bool a[maxn];
int p;

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("b.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase)
	{
		scanf("%d", &p);
		int n = 1 << p, m = 2 * n - 1;

		memset(a, 0, sizeof(a));
		for (int i = n; i <= m; ++i)
		{
			scanf("%d", &M[i]);
			int tmp = i >> 1;
			for (int j = 0; j < M[i]; ++j) tmp >>= 1;
			for ( ; tmp; tmp >>= 1) a[tmp] = 1;
		}

		int ans = 0;
		for (int i = 1; i < n; ++i)
		{
			int x;
			scanf("%d", &x);
			if (a[i]) ++ans;
		}

		printf("Case #%d: %d\n", nCase, ans);
	}

	return 0;
}
