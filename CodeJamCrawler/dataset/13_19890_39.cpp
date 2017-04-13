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
const int maxN = 4005;
const int Mod = 1000002013;
int n, m, k, ans, top;
struct dot
{
	int x, y;
	bool operator<(const dot &o) const
	{
		return x < o.x || (x == o.x && y > o.y);
	}
};
dot a[maxN], st[maxN];

void add(int &x, int y)
{
	x += y;
	if (x >= Mod) x -= Mod;
	if (x < 0) x += Mod;
}

int mul(int64 x, int64 y)
{
	x *= y;
	if (x >= Mod) x %= Mod;
	return x;
}

int calc(int x)
{
	int64 y;
	y = int64(2 * n + 1 - x) * x;
	y /= 2;
	return y % Mod;
}

void init()
{
	int x, y, z;
	scanf("%d%d", &n, &m);
	ans = 0; k = 0;
	rep(i, m)
	{
		scanf("%d%d%d", &x, &y, &z);
		a[++k].x = x; a[k].y = z;
		a[++k].x = y; a[k].y = -z;
		add(ans, mul(calc(y - x), z));
	}
}

void work()
{
	int d;
	sort(a + 1, a + 1 + k);
	top = 0;
	rep(i, k)
	{
		if (a[i].y > 0)
		{
			st[++top] = a[i];
			continue;
		}
		while (a[i].y < 0)
		{
			d = min(st[top].y, -a[i].y);
			st[top].y -= d;
			a[i].y += d;
			add(ans, -mul(calc(a[i].x - st[top].x), d));
			if (st[top].y == 0) --top;
		}
	}
	printf("%d\n", ans);
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int ca;
	scanf("%d", &ca);
	for (int i = 1; i <= ca; ++i)
	{
		init();
		printf("Case #%d: ", i);
		work();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
