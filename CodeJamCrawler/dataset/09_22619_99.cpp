#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<list>
using namespace std;
#define clr(u) memset(u, 0, sizeof u)
FILE* in; FILE* out;
int n;
int slen;
char *s = "welcome to code jam";
int len;
char str[501];
char t;
int dp[501][20];
int dfs(int m, int n) {
	if(dp[m][n] != -1)
		return dp[m][n];
	else if(n == slen - 1)
		return dp[m][n] = 1;
	int res = 0;
	for(int i = m; i < len ; i++)
		if(str[i] == s[n+1]) {
			res += dfs(i, n+1);
			res %= 10000;
		} else {
			dp[i][n+1] = 0;
		}
	return dp[m][n] = res;
}
void solve(int k) {
	len = 0;
	while(fscanf(in, "%c", &t) != EOF && t != '\n')
		str[len++] = t;
	str[len] = 0;
	memset(dp, -1, sizeof dp);
	slen = strlen(s);
	int res = 0;
	for(int i = 0; i < len; i++)
		if(str[i] == 'w') {
			res += dfs(i, 0);
			res %= 10000;
		} else {
			dp[i][0] = 0;
		}
	fprintf(out, "Case #%d: %04d\n", k, res % 10000);
}
int main() {
	in = fopen("C-large.in", "r");
	out = fopen("C-large.out", "w");
	fscanf(in, "%d", &n);
	fscanf(in, "%c", &t);
	for(int k = 1; k <= n; k++) {
		solve(k);
	}
	fclose(out);
	fclose(in);
}