#include "global.h"

double x[100], y[100], r[100];

double D(double x1, double y1, double x2, double y2) {
	return sqrt(sqr(x1-x2)+sqr(y1-y2));
}

int main()
{
	freopen("D-small.in", "r", stdin);
	freopen("D-small.out", "w", stdout);
	int tt;
	scanf("%d", &tt);
	double res;
	For(ttt, 0, tt)
	{
		int n; scanf("%d", &n);
		For(i, 0, n)
			scanf("%lf %lf %lf", &x[i], &y[i], &r[i]);
		if (n == 1) res = r[0];
		if (n == 2) res = max(r[0], r[1]);
		if (n == 3)	{
			res = 1e20;
			res = min(res, max(r[0], (D(x[1], y[1], x[2], y[2])+r[1]+r[2])/2.));
			res = min(res, max(r[1], (D(x[0], y[0], x[2], y[2])+r[0]+r[2]))/2.);
			res = min(res, max(r[2], (D(x[0], y[0], x[1], y[1])+r[0]+r[1]))/2.);
		}
		printf("Case #%d: %.6lf\n", ttt+1, res);
	}
	return 0;
}