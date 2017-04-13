#include <stdio.h>
#include <string.h>
int dp[555][22];
const char* ws = "welcome to code jam";

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	char s[1111];
	int tn, i, j, prob = 0;
	for (scanf("%d", &tn), gets(s); tn--; ) {
		memset(dp, 0, sizeof(dp));
		gets(s);
		if (s[0] == 'w') dp[0][0] = 1;		
		for (i = 1; s[i]; i++) {
			dp[i][0] = dp[i-1][0];
			if (s[i] == ws[0]) dp[i][0] = (dp[i][0] + 1) % 10000;
			for (j = 1; j < 19; j++) {
				dp[i][j] = dp[i-1][j];
				if (s[i] == ws[j]) {
					dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % 10000;
				}				
			}		
		}		
		printf("Case #%d: %04d\n", ++prob, dp[i - 1][18]);
	}
	return 0;
}
