#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 10 + 5;

char a[maxn][maxn];
int r, c, d;

bool check(int x, int y, int k) {
	int rx = 0, ry = 0, res = 0;
	for (int i = x; i < x + k; ++i)
		for (int j = y; j < y + k; ++j)
			if (!(i == x && j == y || i == x && j == y + k - 1 || i == x + k - 1 && j == y || i == x + k - 1 && j == y + k - 1)) {
				rx += i * (d + a[i][j] - '0');
				ry += j * (d + a[i][j] - '0');
				res += d + a[i][j] - '0';
			}
	return 2 * rx == res * (2 * x + k - 1) && 2 * ry == res * (2 * y + k - 1);
}

bool check(int k) {
	for (int i = 0; i + k <= r; ++i)
		for (int j = 0; j + k <= c; ++j)
			if (check(i, j, k)) return 1;
	return 0;
}

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("b.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase) {
		scanf("%d%d%d", &r, &c, &d);
		for (int i = 0; i < r; ++i) scanf("%s", a[i]);

		int k = min(r, c);
		while (k >= 3) {
			if (check(k)) break;
			--k;
		}

		if (k < 3) printf("Case #%d: IMPOSSIBLE\n", nCase);
		else printf("Case #%d: %d\n", nCase, k);
	}

	return 0;
}
