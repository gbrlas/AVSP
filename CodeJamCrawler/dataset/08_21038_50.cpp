#include <cstdio>
#include <algorithm>

using namespace std;

#define MOD 10007
#define MAXW 105

int cc[MAXW][MAXW];

int main() {
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		printf("Case #%d: ", i);
		fill(cc[0], cc[MAXW], 0);
		cc[0][1] = 1;
		int H, W, R;
		scanf("%d%d%d", &H, &W, &R);
		++H, ++W;
		for (int j = 0, r, c; j < R; ++j) {
			scanf("%d%d", &r, &c);
			cc[r+1][c+1] = -1;
		}
		for (int r = 2; r <= H; ++r)
			for (int c = 2; c <= W; ++c)
				if (cc[r][c] >= 0)
					cc[r][c] = (cc[r-1][c-2] + cc[r-2][c-1]) % MOD;
				else
					cc[r][c] = 0;
		printf("%d\n", cc[H][W]);
	}
	return 0;
}
