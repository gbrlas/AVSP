#include <stdio.h>
#include <math.h>
struct Cir {
	int x, y, r;
}c[3];

double getlen(int a, int b) {
	double ret = (c[a].x - c[b].x) * (c[a].x - c[b].x) + 
				 (c[a].y - c[b].y) * (c[a].y - c[b].y);
	ret = sqrt(ret);
	ret += c[a].r + c[b].r;
	return ret;
}

int main() {
	int tn, i, prob = 0, n;
	double ans, len, now;
	freopen("D-small-attempt1.in", "r", stdin);
	freopen("D-small-attempt1.out", "w", stdout);
	for (scanf("%d", &tn); tn--; ) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d%d%d", &c[i].x, &c[i].y, &c[i].r);
		}
		if (n == 1) {
			printf("Case #%d: %.8lf\n", ++prob, 1.0 * c[0].r);
			continue;
		}
		if (n == 2) {
			printf("Case #%d: %.8lf\n", ++prob, 1.0 * (c[0].r > c[1].r ? c[0].r : c[1].r));
			continue;
		}
		ans = 1e9;
		for (i = 0; i < n; i++) {
			len = getlen((i + 1) % 3, (i + 2) % 3);
			now = len / 2;
			if (now < c[i].r) now = c[i].r;
			if (now < ans) ans = now;
		}
		printf("Case #%d: %.8lf\n", ++prob, ans);
	}
	return 0;
}
