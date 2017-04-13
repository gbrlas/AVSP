#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 40 + 10;

struct point
{
	int x, y, r;
};

point a[maxn];
int n;

inline double cal(point a, point b)
{
	return (sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)) + a.r + b.r) / 2.0;
}

int main()
{
	freopen("D-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);

	int T;
	scanf("%d", &T);
	for (int tst = 1; tst <= T; ++tst)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].r);

		double ans;
		if (n == 1) ans = a[0].r;
		else
			if (n==2) ans = max(a[0].r, a[1].r);
			else
			{
				ans = max((double)a[2].r, cal(a[0], a[1]));
				ans = min(ans, max((double)a[1].r, cal(a[0], a[2])));
				ans = min(ans, max((double)a[0].r, cal(a[1], a[2])));
			}

		printf("Case #%d: %lf\n", tst, ans);
	}

	return 0;
}
