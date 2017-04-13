#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10000 + 10;

int d[maxn], l[maxn], f[maxn];
int n, D;

bool check() {
	memset(f, -1, sizeof(f));
	f[0] = d[0] + min(d[0], l[0]);
	for (int j = 1, i = 0; i < n && f[i] != -1; ++i) {
		if (f[i] >= D) return 1;
		while (j < n && f[i] >= d[j]) {
			f[j] = d[j] + min(d[j] - d[i], l[j]);
			++j;
		}
	}
	return 0;
}

int main() {
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d%d", &d[i], &l[i]);
		scanf("%d", &D);

		printf("Case #%d: %s\n", nCase, check() ? "YES" : "NO");
	}

	return 0;
}
