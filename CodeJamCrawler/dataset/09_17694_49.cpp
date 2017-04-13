#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 40 + 5;

char s[maxn];
int right[maxn], delta[maxn];
bool used[maxn];
int n;

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int tst = 1; tst <= T; ++tst)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", s);
			right[i] = -1;
			for (int j = 0; j < n; ++j)
				if (s[j] == '1') right[i] = j;
		}

		int ans = 0;
		memset(used, 0, sizeof(used));
		memset(delta, 0, sizeof(delta));
		for (int i = 0; i < n; ++i)
		{
			int k = -1, best = -1;
			for (int j = 0; j < n; ++j)
				if (!used[j] && right[j] <= i)
					if (best == -1 || abs(j + delta[j] - i) < best ||
						abs(j + delta[j] - i) == best && j + delta[j] < k + delta[k]) k = j, best = abs(j + delta[j] - i);
			used[k] = 1;
			ans += abs(k + delta[k] - i);

			for (int j = 0; j < n; ++j)
				if (!used[j] && j + delta[j] >= i && j + delta[j] < k + delta[k]) ++delta[j];
		}

		printf("Case #%d: %d\n", tst, ans);
	}

	return 0;
}
