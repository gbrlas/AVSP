#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 100 + 10;
const double EPS = 1E-8;

int lx[maxn], ly[maxn], ux[maxn], uy[maxn];
int w, l, u, g;

inline double cross(double X1, double Y1, double X2, double Y2) {
	return X1 * Y2 - X2 * Y1;
}

double cal_area()
{
	double ret = cross(lx[0], ly[0], ux[0], uy[0]);
	for (int i = 0; i + 1 < u; ++i) ret += cross(ux[i], uy[i], ux[i + 1], uy[i + 1]);
	ret += cross(ux[u - 1], uy[u - 1], lx[l - 1], ly[l - 1]);
	for (int i = l - 1; i > 0; --i) ret += cross(lx[i], ly[i], lx[i - 1], ly[i - 1]);
	return fabs(ret);
}

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase) {
		scanf("%d%d%d%d", &w, &l, &u, &g);
		for (int i = 0; i < l; ++i) scanf("%d%d", &lx[i], &ly[i]);
		for (int i = 0; i < u; ++i) scanf("%d%d", &ux[i], &uy[i]);

		double area = cal_area();

		printf("Case #%d:\n", nCase);
		for (int i = 1; i < g; ++i) {
			double left = 0, right = (double)w;
			while (fabs(left - right) > EPS) {
				double mid = (left + right) / 2.0;
				
				double y1, y2;
				double res = cross(lx[0], ly[0], ux[0], uy[0]);

				for (int j = 0; j + 1 < u; ++j)
					if (ux[j + 1] < mid) res += cross(ux[j], uy[j], ux[j + 1], uy[j + 1]);
					else {
						y2 = (uy[j + 1] - uy[j]) * (mid - ux[j]) / (ux[j + 1] - ux[j]) + uy[j];
						res += cross(ux[j], uy[j], mid, y2);
						break;
					}

				for (int j = 0; j + 1 < l; ++j)
					if (lx[j + 1] < mid) res += cross(lx[j + 1], ly[j + 1], lx[j], ly[j]);
					else {
						y1 = (ly[j + 1] - ly[j]) * (mid - lx[j]) / (lx[j + 1] - lx[j]) + ly[j];
						res += cross(mid, y1, lx[j], ly[j]);
						break;
					}

				res += cross(mid, y2, mid, y1);

				res = fabs(res);
				if (res < area / g * i) left = mid;
				else right = mid;
			}

			printf("%.10lf\n", left);
		}

	}
	return 0;
}
