#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	freopen("C-large.in", "r", stdin);
	freopen("c.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase)
	{
		int n, ans = 0, tot = 0, min = 100000000;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			int x;
			scanf("%d", &x);
			if (x < min) min = x;
			tot += x;
			ans ^= x;
		}

		printf("Case #%d: ", nCase);
		if (ans) printf("NO\n");
		else printf("%d\n", tot - min);
	}

	return 0;
}
