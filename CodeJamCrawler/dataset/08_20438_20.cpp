#include <cstdio>
#include <cstring>

const int MAXN = 100;
const int MODULO = 10007;

bool grid[MAXN][MAXN];
int dp[MAXN][MAXN];

int main() {
	int caseNum;
	scanf("%d", &caseNum);
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		int si, sj, r;
		scanf("%d%d%d", &si, &sj, &r);
		for (int i = 0; i < si; i++) {
			memset(grid[i], false, sizeof(bool) * sj);
			memset(dp[i], 0, sizeof(int) * sj);
		}
		while (r-- > 0) {
			int i, j;
			scanf("%d%d", &i, &j);
			grid[i - 1][j - 1] = true;
		}
		dp[0][0] = 1;
		for (int i = 1; i < si; i++) {
			for (int j = 1; j < sj; j++) {
				if (!grid[i][j]) {
					if (i >= 2) {
						dp[i][j] += dp[i - 2][j - 1];
					}
					if (j >= 2) {
						dp[i][j] += dp[i - 1][j - 2];
					}
					dp[i][j] %= MODULO;
				}
			}
		}

		printf("Case #%d: %d\n", caseIndex, dp[si - 1][sj - 1]);
	}

	return 0;
}
