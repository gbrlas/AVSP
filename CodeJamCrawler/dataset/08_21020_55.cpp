#include <cstdio>

void solve() {
	int n, m, a;
	scanf("%d%d%d", &n, &m, &a);
	for (int x1 = 0; x1 <= n; ++x1)
		for (int y1 = 0; y1 <= m; ++y1)
			for (int x2 = 0; x2 <= n; ++x2)
				for (int y2 = 0; y2 <= m; ++y2)
					if (x1 * y2 - y1 * x2 == a) {
						printf("0 0 %d %d %d %d\n", x1, y1, x2, y2);
						return;
					}
	printf("IMPOSSIBLE\n");
 }

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int c;
	scanf("%d", &c);
	for (int i = 1; i <= c; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
