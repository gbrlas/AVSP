#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 10;

int cnts[1 << MAXN];
int grid[MAXN];
int dp[MAXN][1 << MAXN];

inline bool check(int pre, int cur) {
	return (((pre << 1) | (pre >> 1)) & cur) == 0;
}

int main() {
	for (int mask = 0; mask < (1 << MAXN); mask++) {
		cnts[mask] = 0;
		for (int i = 0; i < MAXN; i++) {
			if (mask & (1 << i)) {
				cnts[mask]++;
			}
		}
	}
	int caseNum;
	scanf("%d", &caseNum);
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		int si, sj;
		scanf("%d%d", &si, &sj);
		for (int i = 0; i < si; i++) {
			while (getchar() != '\n');
			grid[i] = 0;
			for (int j = 0; j < sj; j++) {
				if (getchar() == 'x') {
					grid[i] |= (1 << j);
				}
			}
		}
		int size = 1 << sj;
		int ans = -1;
		for (int mask = 0; mask < size; mask++) {
			if ((mask & grid[si - 1]) == 0 && check(mask, mask)) {
				dp[si - 1][mask] = cnts[mask];
				ans = max(ans, cnts[mask]);
			} else {
				dp[si - 1][mask] = -1;
			}
		}
		for (int i = si - 2; i >= 0; i--) {
			for (int cur = 0; cur < size; cur++) {
				dp[i][cur] = -1;
				if ((cur & grid[i]) == 0 && check(cur, cur)) {
					for (int pre = 0; pre < size; pre++) {
						if (dp[i + 1][pre] >= 0 && check(pre, cur)) {
							dp[i][cur] = max(dp[i][cur], dp[i + 1][pre] + cnts[cur]);
						}
					}
					ans = max(ans, dp[i][cur]);
				}
			}
		}

		printf("Case #%d: %d\n", caseIndex, ans);
	}

	return 0;
}
