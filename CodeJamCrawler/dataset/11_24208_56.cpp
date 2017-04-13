#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
	freopen("B-small.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	rep(tc, t) {
		int r, c, d;
		scanf("%d %d %d", &r, &c, &d);
		char w[500][501];
		rep(i, r) {
			scanf("%s", w[i]);
		}
		int mx = 0, mn = min(r, c);
		for (int k = 3; k <= mn; ++k) {
			rep(i, r - k + 1) rep(j, c - k + 1) {
				int v = 0, h = 0;
				rep(l, k) rep(m, k) {
					if (l == 0 && m == 0 || l == 0 && m == k - 1 || l == k - 1 && m == 0 || l == k - 1 && m == k - 1)
						continue;
					h += w[i + l][j + m] * (m * 2 - (k - 1));
					v += w[i + m][j + l] * (m * 2 - (k - 1));
				}
				if (v == 0 && h == 0) {
					mx = k;
					j = c;
					i = r;
				}
			}
		}
		if (mx != 0)
			printf("Case #%d: %d\n", tc + 1, mx);
		else
			printf("Case #%d: IMPOSSIBLE\n", tc + 1);
	}
}