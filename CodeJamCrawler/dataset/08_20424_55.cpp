#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 10000;
const int INF = 1000000;

int n;
bool value[MAXN];
bool isAnd[MAXN];
bool canChange[MAXN];
int dp[MAXN][2];

void doDp(int r) {
	if (2 * r > n) {
		dp[r][value[r]] = 0;
		dp[r][!value[r]] = INF;
	} else {
		int left = 2 * r;
		int right = 2 * r + 1;
		doDp(left);
		doDp(right);
		dp[r][0] = dp[r][1] = INF;
		if (isAnd[r] || canChange[r]) {
			int inc = (isAnd[r] ? 0 : 1);
			dp[r][1] = min(dp[r][1], inc + dp[left][1] + dp[right][1]);
			dp[r][0] = min(dp[r][0], inc + min(dp[left][0] + dp[right][0], min(dp[left][0] + dp[right][1], dp[left][1] + dp[right][0])));
		}
		if (!isAnd[r] || canChange[r]) {
			int inc = (isAnd[r] ? 1 : 0);
			dp[r][0] = min(dp[r][0], inc + dp[left][0] + dp[right][0]);
			dp[r][1] = min(dp[r][1], inc + min(dp[left][1] + dp[right][1], min(dp[left][0] + dp[right][1], dp[left][1] + dp[right][0])));
		}
	}
}

int main() {
	int caseNum;
	scanf("%d", &caseNum);
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		int aim;
		scanf("%d%d", &n, &aim);
		for (int i = 1; i * 2 <= n; i++) {
			int t1, t2;
			scanf("%d%d", &t1, &t2);
			isAnd[i] = (t1 == 1);
			canChange[i] = (t2 == 1);
		}
		for (int i = (n + 1) / 2; i <= n; i++) {
			int t;
			scanf("%d", &t);
			value[i] = (t == 1);
		}
		doDp(1);
		printf("Case #%d: ", caseIndex);
		if (dp[1][aim] < INF) {
			printf("%d\n", dp[1][aim]);
		} else {
			puts("IMPOSSIBLE");
		}
	}
	
	return 0;
}
