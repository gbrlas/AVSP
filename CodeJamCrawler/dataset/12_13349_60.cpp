#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 111
int n, s, p, low, hig;
int a[MAXN];

bool check(int x)
{
	if (x <= 1 || x >= 29)
		return false;
	if (x >= low && x <= hig)
		return true;
	return false;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i)
	{
		scanf("%d%d%d", &n, &s, &p);
		for (int j = 0; j < n; ++j)
			scanf("%d", &a[j]);
		sort(a, a + n);
		int t = 0, k = 0;
		int ans = 0;
		low = p * 3 - 4;
		if (low < 0) low = 0;
		hig = p * 3 - 2;
		if (hig < 0) hig = 0;
//		cout << low << ' ' << hig << endl;
		if (s > 0)
			for (int j = 0; j < n; ++j)
				if (check(a[j]))
				{
					++t;
					++ans;
					k = j + 1;
					if (s == t)
						break;
				}
		for (int j = k; j < n; ++j)
			if (((a[j] + 2) / 3) >= p) ++ans;
		printf("Case #%d: %d\n", i, ans);
	}
	return 0;
}