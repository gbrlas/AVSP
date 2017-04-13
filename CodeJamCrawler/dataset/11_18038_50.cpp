#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10000 + 5;
const int maxm = 100 + 5;

char w[maxn][12];
int len[maxn], idx[maxn];
char s[30];
int mask[maxn][30];
int n, m, l, ans, best;

int cal(int cur, char c)
{
	int ret = 0;
	for (int i = 0;i < len[cur]; ++i)
		if (w[cur][i] == c) ret |= 1 << i;
	return ret;
}

bool cmp(int x, int y)
{
	if (len[x] != len[y]) return len[x] < len[y];
	for (int i = 0; i < 26; ++i)
		if (mask[x][s[i] - 'a'] != mask[y][s[i] - 'a']) return mask[x][s[i] - 'a'] < mask[y][s[i] - 'a'];
	return 1;
}

void work(int l, int r, int p, int res)
{
	if (l == r - 1)
	{
		if (res < ans || res == ans && idx[l] < best)
		{
			ans = res;
			best = idx[l];
		}
		return;
	}

	int key = s[p] - 'a';
	bool flag = 0;
	for (int i = l; i < r; ++i)
		if (mask[idx[i]][key])
		{
			flag = 1;
			break;
		}
	if (!flag) work(l, r, p + 1, res);
	else
		for (int j, i = l; i < r; i = j)
		{
			j = i;
			while (j < r && mask[idx[j]][key] == mask[idx[i]][key]) ++j;
			if (flag && !mask[idx[i]][key]) work(i, j, p + 1, res - 1);
			else work(i, j, p + 1, res);
		}
}

int main()
{
	freopen("B-large.in", "r", stdin);
	//freopen("b.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", w[i]);
			len[i] = strlen(w[i]); idx[i] = i;
			for (int j = 0; j < 26; ++j) mask[i][j] = cal(i, j + 'a');
		}

		printf("Case #%d:", nCase);
		for (int i = 0; i < m; ++i)
		{
			scanf("%s", s);
			l = strlen(s);

			sort(idx, idx + n, cmp);

			ans = 2000000000;
			for (int j = 0; j < n; ++j)
			{
				int k = j;
				while (k < n && len[idx[j]] == len[idx[k]]) ++k;
				work(j, k, 0, 0);
			}
			printf(" %s", w[best]);
		}
		printf("\n");
	}

	return 0;
}
