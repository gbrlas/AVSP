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
const int maxN = 1500;
int t, n, p;

int64 getbest(int64 p)
{
	int64 s = 0, x, y;
	x = p; y = (1LL << n) - p - 1;
	rep(i, n)
	{
		if (y > 0)
		{
			s = s << 1;
			--y;
			if ((y & 1))
			{
				--y; ++x;
			}
			x /= 2; y /= 2;
		}
		else s = (s << 1) + 1;
	}
	return s + 1;
}

int64 getbad(int64 p)
{
	int64 s = 0, x, y;
	x = p; y = (1LL << n) - p - 1;
	rep(i, n)
	{
		if (x > 0)
		{
			s = (s << 1) + 1;
			--x;
			if (x & 1)
			{
				x = x / 2;
				y = y / 2 + 1;
			}
			else
			{
				x = x / 2;
				y = y / 2;
			}
		}
		else s = s << 1;
	}
	return s + 1;
}

void work()
{
	int64 l, r, mid;
	l = 0; r = (1LL << n) - 1;
	while (l <= r)
	{
		mid = l + r >> 1;
		if (getbad(mid) <= p) l = mid + 1;
			else r = mid - 1;
	}
	cout << l - 1 << ' ';
	
	l = 0; r = (1LL << n) - 1;
	while (l <= r)
	{
		mid = l + r >> 1;
		if (getbest(mid) <= p) l = mid + 1;
			else r = mid - 1;
	}
	cout << l - 1 << endl;
}

int main()
{
	freopen("B-small-attempt0(2).in", "r", stdin);
	freopen("B-small-attempt0(2).out", "w", stdout);
	scanf("%d", &t);
	rep(ca, t)
	{
		scanf("%d%d", &n, &p);
		printf("Case #%d: ", ca);
		work();
	}
	return 0;
}
