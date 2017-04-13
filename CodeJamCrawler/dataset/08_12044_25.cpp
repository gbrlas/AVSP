#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 1000 + 10;

int k, n, ans;
char s[MAX_N], s0[MAX_N];
bool used[6];

void search(int cur)
{
	if (cur == k)
	{
		int tot = 1;
		for (int i = 1; i < n; ++i)
			if (s0[i] != s0[i - 1])
				++tot;
		if (tot < ans)
			ans = tot;
		return;
		// check
	}
	for (int i = 0; i < k; ++i)
		if (!used[i])
		{
			used[i] = true;
			for (int j = 0; j < n; j += k)
				s0[j + cur] = s[j + i];
			search(cur + 1);
			used[i] = false;
		}
}

int main()
{
	int cases;
	scanf("%d", &cases);
	for (int caseNo = 0; caseNo < cases; ++caseNo)
	{
		scanf("%d %s", &k, s);
		n = strlen(s);
		ans = n;
		fill(used, used + 5, 0);
		search(0);
		printf("Case #%d: %d\n", caseNo + 1, ans);
	}
	return 0;
}

