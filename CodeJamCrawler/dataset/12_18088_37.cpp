#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1000 + 10;

int L[maxn], P[maxn], idx[maxn];
int n;

bool cmp(int i, int j) {
	return P[j] * L[i] + L[j] < P[i] * L[j] + L[i] || P[j] * L[i] + L[j] == P[i] * L[j] + L[i] && i < j;
}

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &L[i]);
		for (int i = 0; i < n; ++i) scanf("%d", &P[i]);

		for (int i = 0; i < n; ++i) idx[i] = i;

		sort(idx, idx + n, cmp);

		printf("Case #%d:", nCase);
		for (int i = 0; i < n; ++i) printf(" %d", idx[i]);
		puts("");
	}

	return 0;
}
