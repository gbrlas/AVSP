#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <complex>

const double EPS = 1e-8;

using namespace std;
typedef complex<double> Point;

int n, m;
Point p[2];
Point q[10];

int main() {
//	freopen("D.in","r",stdin);
	freopen("D-small-attempt0.in","r",stdin);freopen("D-small-attempt0.out","w",stdout);
//	freopen("D-small-attempt1.in","r",stdin);freopen("D-small-attempt1.out","w",stdout);
//	freopen("D-small-attempt2.in","r",stdin);freopen("D-small-attempt2.out","w",stdout);
//	freopen("D-large.in","r",stdin);freopen("D-large.out","w",stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i) {
			double x, y;
			scanf("%lf %lf", &x, &y);
			p[i] = Point(x, y);
		}
		printf("Case #%d:", t);
		for (int i = 0; i < m; ++i) {
			double x, y;
			scanf("%lf %lf", &x, &y);
			q[i] = Point(x, y);

			double ans = 0.0;
			double PI = 2.0 * acos(0.0);
			double l0 = abs(p[0] - q[i]), l1 = abs(p[1] - q[i]), l2 = abs(p[0] - p[1]);
			// printf("%.3lf %.3lf %.3lf\n", l0, l1, l2);
			double alpha = acos((l0 * l0 + l2 * l2 - l1 * l1) / (2.0 * l0 * l2));
			ans += 2.0 * PI * l0 * l0 * alpha / (2.0 * PI) - cos(alpha) * sin(alpha) * l0 * l0;
			double beta = acos((l1 * l1 + l2 * l2 - l0 * l0) / (2.0 * l2 * l1));
			ans += 2.0 * PI * l1 * l1 * beta / (2.0 * PI) - cos(beta) * sin(beta) * l1 * l1;
 			printf(" %.8lf", ans);
		}
		printf("\n");
	}
	return 0;
}



