#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define rep(x, n) for (int x = 1; x <= n; ++x)
#define zrp(x, n) for (int x = n; x; --x)
#define FOR(x, l, r) for (int x = l; x <= r; ++x)
#define foredge(i, x) for (int i = start[x]; i; i = e[i].l)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define abs(a) ((a) > 0 ? (a) : (-(a)))
typedef long long int64;
const int maxN = 105;
int n, m, a[maxN][maxN];
int h[maxN], z[maxN];

void init()
{
	scanf("%d%d", &n, &m);
	rep(i, n) rep(j, m) scanf("%d", &a[i][j]);
	rep(i, n)
	{
		h[i] = -1;
		rep(j, m) h[i] = max(h[i], a[i][j]);
	}
	rep(j, m)
	{
		z[j] = -1;
		rep(i, n) z[j] = max(z[j], a[i][j]);
	}
}

bool okay()
{
	rep(i, n) rep(j, m)
		if (h[i] != a[i][j] && z[j] != a[i][j])
			return 0;
	return 1;
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int ca;
	scanf("%d", &ca);
	rep(t, ca)
	{
		init();
		printf("Case #%d: ", t);
		if (okay()) puts("YES");
			else puts("NO");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
