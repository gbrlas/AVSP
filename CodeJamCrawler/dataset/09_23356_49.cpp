#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

int n;
double x[100], y[100], r[100];
double p[4], best;

double min(double a, double b) {
	return a<b?a:b;
}

double max(double a, double b) {
	return a>b?a:b;
}

double dist(double x1, double Y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (Y1 - y2) * (Y1 - y2));
}

pair<double, double> calc(double x1, double Y1, double x2, double y2) {
	int i;
	pair<double, double> ret(0, 0);
	for (i = 0; i < n; i++) {
		ret.first = max(ret.first, r[i] + min(dist(x[i], y[i], x1, Y1), dist(x[i], y[i], x2, y2)));
		ret.second += dist(x[i], y[i], x1, Y1) + dist(x[i], y[i], x2, y2);
	}
	return ret;
}

int perm[24][4], a[4];

double cp(double x1, double y1, double r1, double x2, double y2, double r2) {
	double d = dist(x1, y1, x2, y2);
	return max((d+r1+r2)/2, max(r1, r2));
}

int main() {
	int testcase;

	srand(time(0));

	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);

	int i, j = 0, k, t, change, t1, t2;
	pair<double,double> c, cc;
	double d;
	scanf("%d", &testcase);

	for (i = 0; i < 4; i++) a[i] = i;
	while(1) {
		for (i = 0; i < 4; i++) perm[j][i] = a[i];
		j++;
		if (!next_permutation(a, a + 4)) break;
	}

	for (int TT = 1; TT <= testcase; TT++) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%lf%lf%lf",&x[i], &y[i], &r[i]);
		}
		best = 1e10;
		if (n < 3) {
			best = 0;
			for (i = 0; i < n; i++) {
				best = max(best ,r[i]);
			}
		}
		else {
			best = min(best, cp(x[0],y[0],r[0],x[1],y[1],r[1]));
			best = min(best, cp(x[0],y[0],r[0],x[2],y[2],r[2]));
			best = min(best, cp(x[1],y[1],r[1],x[2],y[2],r[2]));
		}

		/*
		best = 1e10;
		for (i = 0; i < 10000; i++) {
			if (rand() % 3 == 3) {
				for (j = 0; j < 4; j++) {
					p[j] = (double)rand() / 32;
				}
			}
			else {
				for (j = 0; j < 4; j++) p[j] = 0;
				t1 = t2 = 0;
				for (int k = 0; k < n; k++) {
					if (rand() % 2) {
						p[0] += x[k];
						p[1] += y[k];
						t1++;
					}
					else {
						p[2] += x[k];
						p[3] += y[k];
						t2++;
					}
					if (t1 > 0) {
						p[0] /= t1;
						p[1] /= t1;
					}
					if (t2 > 0) {
						p[2] /= t2;
						p[3] /= t2;
					}
				}
			}
			c = calc(p[0], p[1], p[2], p[3]);
			best = min(best, c.first);
			d = 500;
			while(d > 1e-8) {
				change = 0;
				j = rand() % 24;
				k = rand() % 16;
				for (t = 0; t < 4; t++) {
					int z = perm[j][t];
					if (z <= 1) {
						if ((k>>t)&1) {
							p[z] += d;
							cc = calc(p[0], p[1], p[2], p[3]);
							best = min(best, cc.first);
							if (cc.first < c.first - 1e-9) {
								c = cc;
								break;
							}
							p[z] -= d;

							p[z] -= d;
							cc = calc(p[0], p[1], p[2], p[3]);
							best = min(best, cc.first);
							if (cc.first < c.first - 1e-9) {
								c = cc;
								break;
							}
							p[z] += d;
						}
						else {
							p[z] -= d;
							cc = calc(p[0], p[1], p[2], p[3]);
							best = min(best, cc.first);
							if (cc.first < c.first - 1e-9) {
								c = cc;
								break;
							}
							p[z] += d;

							p[z] += d;
							cc = calc(p[0], p[1], p[2], p[3]);
							best = min(best, cc.first);
							if (cc.first < c.first - 1e-9) {
								c = cc;
								break;
							}
							p[z] -= d;
						}
					}
				}
				if (t == 4) d /= 2;
			}
		}
		*/
		printf("Case #%d: %.10lf\n", TT, best);
	}
	return 0;
}
