#include <cstdio>

double c, f, x;

bool check(double v) {
	return (x - c)*(v + f) > v*x;
}

int main() {
	int cas; scanf("%d", &cas);
	for (int ca = 1; ca <= cas; ca++) {
		scanf("%lf%lf%lf", &c, &f, &x);
		printf("Case #%d: ", ca);
		if (x <= c) {
			printf("%.7f\n", x/2);
		} else {
			double v = 2, t = c/v;
			while (check(v)) {
				v += f;
				t += c/v;
			}
			t += (x - c)/v;
			printf("%.7f\n", t);
		}
	}
	return 0;
}
