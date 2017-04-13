#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std;

int P, M[1 << 10], c[10][1 << 10];
int f[10][1 << 10][11];

int solve(int lvl, int x, int used) {
	if (f[lvl][x][used] != -1)
		return f[lvl][x][used];
	if (lvl == 0) {
		if (P - M[x * 2] <= used && P - M[x * 2 + 1] <= used)
			return f[lvl][x][used] = 0;
		else if (P - M[x * 2] <= used + 1 && P - M[x * 2 + 1] <= used + 1)
			return f[lvl][x][used] = c[lvl][x];
		else
			return f[lvl][x][used] = INT_MAX;
	} else {
		int ans = INT_MAX, left, right;
		left = solve(lvl - 1, x * 2, used);
		right = solve(lvl - 1, x * 2 + 1, used);
		if (left != INT_MAX && right != INT_MAX)
			ans = min(ans, left + right);
		left = solve(lvl - 1, x * 2, used + 1);
		right = solve(lvl - 1, x * 2 + 1, used + 1);
		if (left != INT_MAX && right != INT_MAX)
			ans = min(ans, left + right + c[lvl][x]);
		return f[lvl][x][used] = ans;
	}
}

int main() {
//	freopen("B.in","r",stdin);
//	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
//	freopen("B-small-attempt1.in","r",stdin);freopen("B-small-attempt1.out","w",stdout);
//	freopen("B-small-attempt2.in","r",stdin);freopen("B-small-attempt2.out","w",stdout);
	freopen("B-large.in","r",stdin); freopen("B-large.out","w",stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d", &P);
		for (int i = 0; i < (1 << P); ++i)
			scanf("%d", &M[i]);
		for (int i = 0; i < P; ++i) {
			for (int j = 0; j < 1 << (P - i - 1); ++j)
				scanf("%d", &c[i][j]);
		}
		for (int j = 0; j < P; ++j)
			for (int i = 0; i < (1 << P); ++i)
				for (int k = 0; k <= P; ++k)
					f[j][i][k] = -1;
		printf("Case #%d: %d\n", t, solve(P - 1, 0, 0));
	}
	return 0;
}


