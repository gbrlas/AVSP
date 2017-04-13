#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cctype>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#define FILE_IN  "A-small-attempt0.in"
#define FILE_OUT "A-small-attempt0.out"

#define E 1e-7

int x[3], y[3], xx[3], yy[3];
double e[3], ee[3];

void solve() {
	for (int i = 0; i < 3; ++i)
		scanf("%d%d", &x[i], &y[i]);
	for (int i = 0; i < 3; ++i)
		scanf("%d%d", &xx[i], &yy[i]);
	e[0] = hypot(x[0]-x[1], y[0]-y[1]);
	e[1] = hypot(x[1]-x[2], y[1]-y[2]);
	e[2] = hypot(x[2]-x[0], y[2]-y[0]);
	ee[0] = hypot(xx[0]-xx[1], yy[0]-yy[1]);
	ee[1] = hypot(xx[1]-xx[2], yy[1]-yy[2]);
	ee[2] = hypot(xx[2]-xx[0], yy[2]-yy[0]);
	int mi = max_element(e, e+3) - e;
	int mii = max_element(ee, ee+3) - ee;
	double me = e[mi];
	double mee = ee[mii];
	double S = mee / me;
	double ang = atan2(y[(mi+1)%3] - y[mi], x[(mi+1)%3] - x[mi]);
	double aang = atan2(yy[(mii+1)%3] - yy[mii], xx[(mii+1)%3] - xx[mii]);
	double A = aang - ang;

	double q11 = -S * cos(A) + 1;
	double q12 = S * sin(A);
	double w1 = xx[0] - x[0] * S * cos(A) + y[0] * S * sin(A);
	double q21 = -S * sin(A);
	double q22 = -S * cos(A) + 1;
	double w2 = yy[0] - x[0] * S * sin(A) - y[0] * S * cos(A);

	double dx, dy;
	if (fabs(q11) < E) {
		dy = w1 / q12;
		dx = (w2 - q22 * dy) / q21;
	} else {
		double qq = q21 / q11;
		q21 = 0;
		q22 -= q12 * qq;
		w2 -= w1 * qq;
		dy = w2 / q22;
		dx = (w1 - q12 * dy) / q11;
	}
	printf("%.6lf %.6lf\n", dx, dy);
}

int main() {
	freopen(FILE_IN, "r", stdin);
	freopen(FILE_OUT, "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
