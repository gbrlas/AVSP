#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const char * AIM = "welcome to code jam";
const int LEN = 19;
const int MODULO = 10000;

int main() {
	int caseNum;
	scanf("%d", &caseNum);
	while (getchar() != '\n');
	for (int caseIndex = 1; caseIndex <= caseNum; caseIndex++) {
		int dp[LEN + 1];
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		char ch;
		while ((ch = getchar()) != '\n') {
			for (int i = LEN - 1; i >= 0; i--) {
				if (AIM[i] == ch && dp[i]) {
					dp[i + 1] += dp[i];
					if (dp[i + 1] >= MODULO) {
						dp[i + 1] -= MODULO;
					}
				}
			}
		}
		cout << "Case #" << caseIndex << ": ";
		cout.fill('0');
		cout.width(4);
		cout << right << dp[LEN] << endl;
	}
	
	return 0;
}
