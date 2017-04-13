#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 2000 + 10;
const int INF = 1000000000;

int x[maxn], cur[maxn], ans[maxn];
vector<int> E[maxn];
int n;

bool check() {
	for (int i = 1; i < n; ++i)
		if (x[i] <= i) return 0;
	return 1;
}

int calHeight(int x, int u, int v) {
	return (int)(ans[v] - (double)(ans[v] - ans[u]) * (v - x) / (v - u)) - 1;
}

bool gao(int l, int r, int u, int v) {
	if (l > r) return 1;

	if (E[r].empty()) {
		if (ans[r] < 0) ans[r] = 0;
		return gao(l, r - 1, u, v);
	}

	if (cur[r] > E[r].size()) return gao(l, r - 1, u, v);

	int x = E[r][cur[r] - 1];
	++cur[r];
	if (x < l || x > r) return 0;

	if (ans[x] < 0) ans[x] = calHeight(x, u, v);
	if (ans[r] < 0) ans[r] = calHeight(r, u, v);

	return gao(l, x, x, r) && gao(x, r, x, r);
}

int main() {
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("c.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) E[i].clear();
		for (int i = 1; i < n; ++i) {
			scanf("%d", &x[i]);
			E[x[i]].push_back(i);
		}

		printf("Case #%d:", nCase);
		if (!check()) {
			puts(" Impossible");
			continue;
		}

		for (int i = 1; i <= n; ++i) cur[i] = 1;

		memset(ans, -1, sizeof(ans));
		ans[0] = ans[n + 1] = INF;

		if (!gao(1, n, 0, n + 1)) puts(" Impossible");
		else {
			for (int i = 1; i <= n; ++i) printf(" %d", ans[i]);
			puts("");
		}
	}

	return 0;
}
