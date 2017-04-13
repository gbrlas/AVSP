#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXS 1010
#define LOTS 0x3fffffff

int rle(char *c) {
	if (!c || !c[0])
		return 0;
	char last = 0;
	int count = 0;
	for (int i = 0; c[i]; ++i) {
		if (c[i] != last) {
			last = c[i];
			++count;
		}
	}
	return count;
}

void perm(char *src, char *dst, int p[], int k) {
	int o;
	for (o = 0; src[o]; o += k) {
		for (int i = 0; i < k; ++i) {
			dst[o+i] = src[o+p[i]];
		}
	}
	dst[o] = 0;
}

int solve() {
	int k;
	char A[MAXS], B[MAXS];
	scanf("%d %s", &k, A);
	int p[5];
	for (int i = 0; i < k; ++i)
		p[i] = i;
	int best = LOTS;
	do {
		perm(A, B, p, k);
		best = min(best, rle(B));
	} while (next_permutation(p, p+k));
	return best;
}

int main() {
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		printf("Case #%d: %d\n", i, solve());
	}
	return 0;
}
