#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int64;
#define rep(x, n) for (int x = 1; x <= n; ++x)
#define zrp(x, n) for (int x = n; x; --x)
#define FOR(x, l, r) for (int x = l; x <= r; ++x)
#define foredge(i, x) for (int i = start[x]; i; i = e[i].l)
struct edge{int a, l;};
const int maxN = 10005;
bool del[maxN];

int a[maxN];

int main()
{
	int ca, n, x;
	scanf("%d", &ca);
	rep(t, ca)
	{
		scanf("%d", &n);
		scanf("%d", &x);
		rep(i, n) scanf("%d", a + i);
		int ans = 0;
		sort(a + 1, a + 1 + n);
		rep(i, n) del[i] = 0;
		zrp(i, n) if (!del[i])
		{
			int j = i - 1;
			for (; j > 0; --j) if (!del[j] && a[i] + a[j] <= x)
				break;
			if (j != 0) del[j] = 1;
			++ans;
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
