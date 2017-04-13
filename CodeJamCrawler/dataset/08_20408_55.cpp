#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

const int MAXS = 100;
const int MAXQ = 1000;
const int INF = 0x7f7f7f7f;

int dp[2][MAXS];

int main() {
	int caseNum;
	char str[128];
	scanf("%d", &caseNum);
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		int s, q;
		scanf("%d", &s);
		while (getchar() != '\n');
		map<string, int> nameMap;
		for (int i = 0; i < s; i++) {
			gets(str);
			nameMap[str] = i;
		}
		memset(dp[0], 0, sizeof(int) * s);
		int cur = 0;
		scanf("%d", &q);
		while (getchar() != '\n');
		for (int i = 0; i < q; i++) {
			gets(str);
			int pos = nameMap[str];
			int next = !cur;
			memset(dp[next], 0x7f, sizeof(int) * s);
			for (int j = 0; j < s; j++) {
				if (dp[cur][j] < INF) {
					if (j != pos) {
						dp[next][j] = min(dp[next][j], dp[cur][j]);
					}
					for (int k = 0; k < s; k++) {
						if (k != pos && k != j) {
							dp[next][k] = min(dp[next][k], dp[cur][j] + 1);
						}
					}
				}
			}

			cur = next;
		}
		int ans = INF;
		for (int i = 0; i < s; i++) {
			ans = min(ans, dp[cur][i]);
		}
		printf("Case #%d: %d\n", caseIndex, ans);
	}
	
	return 0;
}
