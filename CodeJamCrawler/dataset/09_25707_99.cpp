#include <cstdio>
#include <string>
using namespace std;

const char str[] = "welcome to code jam";
const int MOD = 10000;
int dp[512][20];
char buf[512];

int main() {
	freopen("c-large.in","r",stdin);
	freopen("c-large.out","w",stdout);
	int T, ca, i, j, k;
	scanf("%d",&T);
	gets(buf);
	for (ca = 1 ; ca <= T ; ca++) {
		gets(buf);
		memset(dp, 0, sizeof(dp));
		for (i = 0 ; buf[i] ; i++)
			if (buf[i] == 'w') dp[i][0] = 1;
		for (i = 0 ; buf[i] ; i++)
			for (j = 0 ; j < 18 ; j++) {
				if (dp[i][j] == 0) continue;
				for (k = i + 1 ; buf[k] ; k++)
					if (buf[k] == str[j+1]) {
						dp[k][j+1] += dp[i][j];
						dp[k][j+1] %= MOD;
					}
			}
		int ans = 0;
		for (i = 0 ; buf[i] ; i++) {
			ans += dp[i][18];
			ans %= MOD;
		}
		printf("Case #%d: %04d\n",ca,ans);
	}
	return 0;
}
