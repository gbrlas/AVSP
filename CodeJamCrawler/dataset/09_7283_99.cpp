#include <stdio.h>
#include <string.h>

char *t = "welcome to code jam";

char s[1000];

int n, dp[30];

int solve() {
	n = strlen(s);
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i = 0; i < n; ++i) {
		for(int j = 18; j >= 0; --j) {
			if(s[i] == t[j] && dp[j] != 0) {
				dp[j + 1] += dp[j];
				dp[j + 1] %= 10000;
				dp[j + 1] += 10000;
			}
		}
	}
	return dp[19] % 10000;
}

int main() {
	int t;
	freopen("cout.txt", "w", stdout);
	scanf("%d", &t);
	gets(s);
	for(int tt = 1; tt <= t; ++tt) {
		printf("Case #%d: ", tt);
		gets(s);
		printf("%04d\n", solve() % 10000);
	}
	return 0;
}
