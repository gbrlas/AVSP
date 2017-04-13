#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std;

int n, ans;
int g[60][60], g2[500][500], used[60][60];
int get(int x, int y) {
	if ( 0 <= x && x < n && 0 <= y && y < n) {
		used[x][y] = true; return g[x][y];
	}else return -1;
}
int neq(int a, int b) {
	return a != -1 && b != -1 && a != b;
}
bool solve(int k) {
	for (int i = 1; i <= k; ++i) {
		for (int j = 0; j < i; ++j)
			if (neq(g2[i][j], g2[i][i - 1 - j]) || neq(g2[i][j], g2[2 * k - i][j]))
				return false;
	}
	for (int i = k + 1; i < k + k; ++i) { 
		for (int j = 0; j < 2 * k - i; ++j)
			if (neq(g2[i][j], g2[i][2 * k - i - 1 - j]))
				return false;
	}/*
	for (int i = 1; i <= k; ++i) { 
		for (int j = 0; j < i; ++j)
			printf("%d ", g2[i][j]);
		printf("\n");
	}
	for (int i = k + 1; i < k + k; ++i) { 
		for (int j = 0; j < 2 * k - i; ++j)
			printf("%d ", g2[i][j]);
		printf("\n");
	}
	printf("\n");*/
	return true;
}
int main() {
//	freopen("A.in","r",stdin);
//	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out4","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin); freopen("A-small-attempt1.out2","w",stdout);
	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
//	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d", &n);
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			int sx = i - 1, sy = 0;
			for (int j = 0; j < i; ++j) {
				scanf("%d", &g[sx][sy]);
				sum += g[sx][sy];
				sx--; sy++;
			}
		}
		for (int i = n + 1; i < n + n; ++i) {
			int sx = n - 1, sy = i - n;
			for (int j = 0; j < 2 * n - i; ++j) {
				scanf("%d", &g[sx][sy]);
				sum += g[sx][sy];
				sx--; sy++;
			}
		}
		ans = INT_MAX;
		for (int len = n; ans == INT_MAX; ++len) {
			for (int x = -60; x <= 60; ++x)
				for (int y = -60; y <= 60 && ans == INT_MAX; ++y) {
					memset(used, 0, sizeof(used));
					for (int k = 1; k <= len; ++k) {
						int sx = x + k - 1, sy = y + 0;
						for (int l = 0; l < k; ++l)
							g2[k][l] = get(sx--, sy++);
					}
					for (int k = len + 1; k < len + len; ++k) {
						int sx = x + len - 1, sy = y + k - len;
						for (int l = 0; l < 2 * len - k; ++l)
							g2[k][l] = get(sx--, sy++);
					}
					int cnt = 0;
					for (int i = 0; i < n; ++i)
						cnt += count(used[i], used[i] + n, 1);
					if (cnt == n * n && solve(len)) {
						ans = len * len - n * n;
						break;
					}
				}
		}
		printf("Case #%d: %d\n", t, ans);
		cerr << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}

