#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100 + 10;

int f[maxn][maxn];
int t[maxn];
int n, s, p;

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("b.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase) {
		scanf("%d%d%d", &n, &s, &p);
		for (int i = 0; i < n; ++i) scanf("%d", &t[i]);

		memset(f, -1, sizeof(f));
		f[0][0] = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j <= i && j <= s; ++j)
				if (f[i][j] != -1) {
					int x = t[i] / 3;
					if (t[i] % 3) ++x;
					if (f[i][j] + (x >= p) > f[i + 1][j]) f[i + 1][j] = f[i][j] + (x >= p);
					if (j < s)
						switch (t[i] % 3) {
							case 0:
								if (t[i] / 3 > 0 && f[i][j] + (x + 1 >= p) > f[i + 1][j + 1]) f[i + 1][j + 1] = f[i][j] + (x + 1 >= p);
								break;

							case 1:
								if (t[i] / 3 > 0 && f[i][j] + (x >= p) > f[i + 1][j + 1]) f[i + 1][j + 1] = f[i][j] + (x >= p);
								break;

							case 2:
								if (x > 0 && f[i][j] + (x + 1 >= p) > f[i + 1][j + 1]) f[i + 1][j + 1] = f[i][j] + (x + 1 >= p);
								break;
						}
				}

		printf("Case #%d: %d\n", nCase, f[n][s]);
	}

	return 0;
}
