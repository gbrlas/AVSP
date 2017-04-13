#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 20 + 5;
const int maxk = 5 + 2;
const int maxl = 50 + 5;
const int mod = 10009;

char p[maxl];
int num[maxn][26];
int ans[maxk];
int n, k, l;

void DFS(int step, int sum[26])
{
	if (step)
	{
		int res = 0;
		for (int last = 0, i = 0; i < l; ++i)
			if (p[i] == '+')
			{
				int tmp = 1;
				for (int j = last; j < i; ++j) tmp = (tmp * sum[p[j] - 'a']) % mod;
				res += tmp; last = i + 1;
			}
		ans[step] = (ans[step] + res) % mod;
	}
	if (step == k) return;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 26; ++j) sum[j] += num[i][j];
		DFS(step + 1, sum);
		for (int j = 0; j < 26; ++j) sum[j] -= num[i][j];
	}

}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int tst = 1; tst <= T; ++tst)
	{
		scanf("%s%d", p, &k);
		l = strlen(p);
		p[l++] = '+'; p[l] = 0;

		scanf("%d", &n);
		memset(num, 0, sizeof(num));
		for (int i = 0; i < n; ++i)
		{
			char s[maxl];
			scanf("%s", s);
			int l = strlen(s);
			for (int j = 0; j < l; ++j) ++num[i][s[j] - 'a'];
		}

		memset(ans, 0, sizeof(ans));
		DFS(0, num[n]);

		printf("Case #%d:", tst);
		for (int i = 1; i <= k; ++i) printf(" %d", ans[i]);
		printf("\n");
	}

	return 0;
}
