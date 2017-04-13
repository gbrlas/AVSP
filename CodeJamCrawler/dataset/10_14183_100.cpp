#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std;

int N, D, I, M, best;
int a[110];
// min cost s.t. till i, cur is y;
int f[110][256];

int calc(int p, int cur) {
	if (f[p][cur] != -1)
		return f[p][cur];

	int ans = p * D + abs(a[p] - cur);
	for (int i = 0; i < p; ++i)
		for (int j = 0; j < 256; ++j) {
			if (M > 0) {
				int cost = calc(i, j) + (max(0, (abs(j - cur) + M - 1) / M - 1)) * I + (p - i - 1) * D;
				ans <?= cost + abs(a[p] - cur);
			} else if (j == cur)
				ans <?= calc(i, j) + (p - i - 1) * D + abs(a[p] - cur);
		}
	f[p][cur] = ans;
	return ans;
}

int main() {
//	freopen("B.in","r",stdin);
//	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
	freopen("B-small-attempt1.in","r",stdin);freopen("B-small-attempt1.out","w",stdout);
//	freopen("B-small-attempt2.in","r",stdin);freopen("B-small-attempt2.out","w",stdout);
//	freopen("B-large.in","r",stdin);freopen("B-large.out","w",stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d %d %d %d", &D, &I, &M, &N);
		for (int i = 0; i < N; ++i)
			scanf("%d", &a[i]);
		best = (N - 1) * D;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < 256; ++j)
				f[i][j] = -1;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < 256; ++j) {
				best <?= calc(i, j) + D * (N - 1 - i);
			}
		printf("Case #%d: %d\n", t, best);
	}
	return 0;
}


