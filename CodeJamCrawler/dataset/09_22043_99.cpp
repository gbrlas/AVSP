#include <cstdio>
#include <string>
using namespace std;

const int MAXN = 512;
const int MOD = 10000;
const char pattn[] = "welcome to code jam";
const int LEN = 19;
char str[MAXN], in[MAXN];
int casenum, dp[MAXN][LEN+1];

int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	gets(in);
	sscanf(in, "%d", &casenum);
	for(int ca = 1; ca <= casenum; ca++){
		gets(str);
		memset(dp, 0, sizeof(dp));
		if(str[0] == 'w') dp[0][0] = 1;
		for(int i = 1; str[i]; i++){
			for(int j = 0; j < LEN; j++) {
				if(j == 0){
					if(str[i] == 'w') dp[i][0] = 1;
					else dp[i][0] = 0;
				}
				else {
					if(str[i] == pattn[j]){
						for(int k = i-1; k >= 0; k--){
							if(str[k] == pattn[j-1])
								dp[i][j] += dp[k][j-1];
						}
						dp[i][j] %= MOD;
					}
				}
			}
		}
		int ans = 0;
		for(int i = 0; str[i]; i++){
			ans = (ans + dp[i][LEN-1]) % MOD;
		}
		printf("Case #%d: %04d\n", ca, ans);
	}
	return 0;
}
