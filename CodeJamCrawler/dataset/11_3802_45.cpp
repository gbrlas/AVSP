#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int MXN = 10001;
struct Point {
	int x, y;
};
Point a[MXN], b[MXN];
int u[MXN], d[MXN];
double x[MXN], k[MXN], s[MXN];
int W, L, U, G;

int main () {
    freopen ("A-small-attempt0.in", "r", stdin);
    freopen ("out.txt", "w", stdout);
    int cn;
    double ans;
    scanf ("%d", &cn);
    for (int ci = 0; ci < cn; ci ++) {
        printf ("Case #%d:\n", ci + 1);
		scanf ("%d%d%d%d", &W, &L, &U, &G);
		//cout << W << ' ' << L << ' ' << U << ' '<<G << endl;
		for (int i = 0; i < L; i++) {
			scanf ("%d%d", &a[i].x, &a[i].y);
			if (i > 0)
				for (int j = a[i - 1].x; j < a[i].x; j++) {
					k[j] = - ((double)(a[i].y - a[i - 1].y)) / (a[i].x - a[i - 1].x) / 2;
					x[j] = - a[i - 1].y + k[j] * (j - a[i - 1].x) * 2;
				}
		}
		for (int i = 0; i < U; i++) {
			scanf ("%d%d", &b[i].x, &b[i].y);
			if (i > 0)
				for (int j = b[i - 1].x; j < b[i].x; j++) {
					double tk = ((double)(b[i].y - b[i - 1].y)) / (b[i].x - b[i - 1].x) / 2;
					//cout << tk << endl;
					k[j] += tk;
					x[j] += b[i - 1].y + tk * (j - b[i - 1].x) * 2;
				}
		}
		s[0] = 0;
		for (int i = 1; i <= W; i++) {
			s[i] = s[i - 1] + x[i - 1] + k[i - 1];
		//	printf ("%.6lf %.6lf %.6lf \n", s[i], x[i - 1], k[i - 1] * 2);
		}
		ans = s[W] / G;
		int m = 1;
		for (int i = 1; i <= W; i++) {
			while (s[i] - ans * m >= 0) {
				double t = ans * m - s[i - 1];
				if (fabs (k[i - 1]) < 1e-7) {
					printf ("%.8lf\n", t / x[i - 1] + i - 1);
				} else {
					printf ("%.8lf\n", (sqrt (x[i - 1] * x[i - 1] + 4 * k[i - 1] * t) - x[i - 1]) / 2 / k[i - 1]+ i - 1);
				}
				m ++;
				if (m >= G)
					break;
			}
			if (m >= G)
				break;
		}
    }
    return 0;
}
