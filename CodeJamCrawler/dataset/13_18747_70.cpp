#include <stdio.h>
#include <string.h>

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; ++tt) {
		int n, m;
		scanf("%d%d", &n, &m);
		int a[100][100], x[100], y[100];
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				scanf("%d", &a[i][j]);
				if (a[i][j] > x[i])
					x[i] = a[i][j];
				if (a[i][j] > y[j])
					y[j] = a[i][j];
			}
		bool p = true;
		for (int i = 0; i < n && p; ++i)
			for (int j = 0; j < m && p; ++j)
				p = (a[i][j] >= x[i] || a[i][j] >= y[j]);
		printf("Case #%d: %s\n", tt, p ? "YES" : "NO");
	}
}
