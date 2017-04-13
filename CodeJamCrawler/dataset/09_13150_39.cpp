#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int N, x[40], y[40], r[40];

double dis(int i, int j) {
	return sqrt((double)(x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

double solve() {
	if (N == 1)
		return (double)r[0];
	else if (N == 2)
		return max((double)r[0], (double)r[1]);
	else if (N == 3) {
		double f0 = max((double)r[0], (double)(r[1] + r[2] + dis(1, 2)) / 2);
		double f1 = max((double)r[1], (double)(r[0] + r[2] + dis(0, 2)) / 2);
		double f2 = max((double)r[2], (double)(r[0] + r[1] + dis(0, 1)) / 2);
		return min(f0, min(f1, f2));
	}
	 else {
		 assert(false);
		 return -1.0;
	 }
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int tId = 1; tId <= T; ++tId) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
			scanf("%d %d %d", &x[i], &y[i], &r[i]);
		printf("Case #%d: %.6lf\n", tId, solve());
	}
	return 0;
}


