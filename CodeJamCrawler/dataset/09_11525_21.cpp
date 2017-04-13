#include <iostream>
#include <cmath>
using namespace std;

double d (int x0, int y0, int x1, int y1)
{
	return sqrt (1.0 * (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
}

int main ()
{
	freopen ("D-small.in", "r", stdin);
	freopen ("D-small.out", "w", stdout);
	int t, n, x[50], y[50], r[50];
	scanf("%d", &t);
	for (int ncase = 1; ncase <= t; ncase++){
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d%d", &x[i], &y[i], &r[i]);
		double ans;
		if (n == 1)
			ans = r[0];
		else if (n == 2)
			ans = max (r[0], r[1]);
		else{
			ans = 2000000000;
			ans = min (ans, max ((d (x[0], y[0], x[1], y[1]) + r[0] + r[1]) / 2, 1.0 * r[2]));
			ans = min (ans, max ((d (x[0], y[0], x[2], y[2]) + r[0] + r[2]) / 2, 1.0 * r[1]));
			ans = min (ans, max ((d (x[1], y[1], x[2], y[2]) + r[1] + r[2]) / 2, 1.0 * r[0]));
		}
		printf("Case #%d: %.6f\n", ncase, ans);
	}
}