#include <cstdio>
#include <cmath>

const double PI = atan2(0.0, -1.0);
const double EPS = 1e-9;

inline double squDiff(double c, double a) {
	return sqrt(c*c - a*a);
}

inline double dis(double x1, double y1, double x2, double y2) {
	double dx = x1 - x2;
	double dy = y1 - y2;
	return sqrt(dx*dx + dy*dy);
}

inline double bowArea(double R, double x0, double y0, double x1, double y1) {
	double chord = dis(x0, y0, x1, y1);
	double halfAngle = asin(chord / 2.0 / R);
	double sector = R * R * halfAngle;
	return sector - chord * chord / tan(halfAngle) / 4.0;
}

int main() {
	int caseNum;
	scanf("%d", &caseNum);
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		double f, R, t, r, g;
		scanf("%lf%lf%lf%lf%lf", &f, &R, &t, &r, &g);
		if (f * 2 > g - EPS) {
			printf("Case #%d: 1.000000\n", caseIndex);
			continue;
		}
		double total = PI * R * R / 8.0;
		g -= 2 * f;
		R -= t + f;
		r += f;
		double miss = 0.0;
		const double len = R / sqrt(2.0);
		for (int i = 0; (2 * r + g) * i + r < len; i++) {
			const double low = (2 * r + g) * i + r;
			const double high = low + g;
			const double xb = squDiff(R, low);
			const double xt = squDiff(R, high);
			double y0;
			if (high <= R && xt >= high) {
				miss += g*g / 2.0;
				double left;
				for (left = high + 2 * r; left + g <= xt; left += 2 * r + g) {
					miss += g*g;
				}
				if (left < xt) {
					miss += g * (xt - left);
				} else {
					if (left >= R) {
						continue;
					}
					y0 = squDiff(R, left);
				}
				y0 = high;
			} else {
				y0 = len;
				miss += (y0 - low) * (y0 - low) / 2.0;
			}
			while (y0 > low + EPS) {
				double x0 = squDiff(R, y0);
				int j = (int) floor((x0 + r) / (2 * r + g) + EPS) + 1;
				double x1 = (2 * r + g) * j - r;
				if (x1 > R || squDiff(R, x1) < low) {
					double triangle = (xb - x0) * (y0 - low) / 2.0;
					miss += triangle + bowArea(R, x0, y0, xb, low);
					break;
				}
				double y1 = squDiff(R, x1);
				if (y0 > y1 + EPS) {
					double trapezoid = (y1 - low + y0 - low) * (x1 - x0) / 2.0;
					miss += trapezoid + bowArea(R, x0, y0, x1, y1);
				}
				y0 = squDiff(R, x1 + 2 * r);
			}
		}
		printf("Case #%d: %.7lf\n", caseIndex, 1.0 - miss / total);
	}
	
	return 0;
}
