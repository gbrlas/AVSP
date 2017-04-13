#include <cstdio>

#define MAXN 1005
#define E 1e-8

int N;
int X[MAXN], Y[MAXN], Z[MAXN];
int P[MAXN];

int abs(int x) { return x < 0 ? -x : x; }

bool check(double tp) {
	for (int i = 0; i < N; ++i)
		for (int j = i + 1; j < N; ++j) {
			int dst = abs(X[i]-X[j]) + abs(Y[i]-Y[j]) + abs(Z[i]-Z[j]);
			if ((P[i] + P[j]) * tp < dst)
				return false;
		}
	return true;
}

double get() {
	double low = 0, high = 1e7;
	while (high - low >= E) {
		double mid = (low + high) / 2;
		(check(mid) ? high : low) = mid;
	}
	return low;
}

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i) {
		scanf("%d", &N);
		for (int j = 0; j < N; ++j) {
			scanf("%d%d%d%d", &X[j], &Y[j], &Z[j], &P[j]);
		}
		printf("Case #%d: %.6lf\n", i, get());
	}
	return 0;
}
