#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1000 + 10;

int r[maxn], idx[maxn], ansx[maxn], ansy[maxn];
int n, w, l;

bool cmp(int i, int j) {
	return r[i] > r[j];
}

bool check() {
	int x = -r[idx[0]], i = 0;
	for (int j; i < n; i = j) {
		if (x > w) break;
		x += r[idx[i]];
		j = i;
		int y = -r[idx[i]];
		while (j < n && y + r[idx[j]] <= l) {
			ansx[idx[j]] = x; ansy[idx[j]] = y + r[idx[j]];
			y += 2 * r[idx[j]];
			++j;
		}
		x += r[idx[i]];
	}
	return i >= n;
}

bool check2() {
	int x = -r[idx[0]], i = 0;
	for (int j; i < n; i = j) {
		if (x > w) break;
		x += r[idx[i]];
		j = i;
		int y = -r[idx[i]];
		while (j < n && y + r[idx[j]] <= l) {
			ansx[idx[j]] = x; ansy[idx[j]] = y + r[idx[j]];
			y += 2 * r[idx[j]];
			++j;
		}
		x += r[idx[i]];
	}
	return i >= n;
}

int main() {
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("b.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase) {
		scanf("%d%d%d", &n, &w, &l);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &r[i]);
			idx[i] = i;
		}

		sort(idx, idx + n, cmp);

		if (!check()) check2();
		printf("Case #%d:", nCase);
		for (int i = 0; i < n; ++i) printf(" %d %d", ansx[i], ansy[i]);
		puts("");
	}

	return 0;
}
