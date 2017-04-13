#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1000 + 10;

int a[maxn * 2];
int next[maxn], used[maxn];
long long sum[maxn];
int r, k, n;

int main()
{
	freopen("C-small-attempt3.in", "r", stdin);
	freopen("c.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase)
	{
		scanf("%d%d%d", &r, &k, &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
			a[n + i] = a[i];
		}

		for (int i = 0; i < n; ++i)
		{
			int j = i;
			sum[i] = 0;
			while (j < i + n && sum[i] + a[j] <= k) sum[i] += a[j++];
			next[i] = j % n;
//			printf("%d %d\n", i, next[i]);
		}

		long long ans = 0;
		memset(used, -1, sizeof(used));
		for (int i = 0, cnt = 0; cnt < r; ++cnt)
		{
//			printf("%d\n", i);
			if (used[i] != -1)
			{
				long long tot = 0;
				int j = i;
				do
				{
					tot += sum[j]; j = next[j];
				} while (j != i);
				ans += tot * ((r - cnt) / (cnt - used[i]));
				r = (r - cnt) % (cnt - used[i]);
				cnt = 0;
				for (int j = i; cnt < r; j = next[j], ++cnt) ans += sum[j];
				break;
			}
			ans += sum[i];
			used[i] = cnt; i = next[i];
		}
		printf("Case #%d: %I64d\n", nCase, ans);
	}

	return 0;
}
