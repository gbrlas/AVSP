#include <cstdio>
#include <cstring>

using namespace std;

const int maxk = 5 + 5;
const int maxl = 1000 + 10;

int n, k, l;
bool used[maxk];
int list[maxk];
char s[maxl], t[maxl];
int ans;

void check()
{
	for (int i = 0; i < l; i += k)
		for (int j = i; j < i + k; ++j)	t[j] = s[i + list[j - i]];

	int res = 0;
	for (int i = 0; i < l; ++i)
		if (!i || t[i - 1] != t[i]) ++res;
	ans <?= res;
}

void DFS(int step)
{
	if (step == k)
	{
		check();
		return;
	}

	for (int i = 0; i < k; ++i)
		if (!used[i])
		{
			used[i] = 1;
			list[step] = i;
			DFS(step + 1);
			used[i] = 0;
		}
}

int main()
{
	freopen("d-small-attempt0.in", "r", stdin);
	freopen("D.out", "w", stdout);

	scanf("%d", &n);
	for (int tst = 1; tst <= n; ++tst)
	{
		scanf("%d", &k);
		scanf("%s", s);
		l = strlen(s);

		ans = l;
		memset(used, 0, sizeof(used));
		DFS(0);

		printf("Case #%d: %d\n", tst, ans);
	}

	return 0;
}
