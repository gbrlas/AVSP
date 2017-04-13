#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;


void solve(int tcase) {
	int n, q;
	char buff[1000];
	gets(buff);
	sscanf(buff, "%d", &n);
	map<string, int> M;
	int cnt=0;
	for(int i=0; i<n; i++) {
		gets(buff);
		string s = buff;
		M[s]=cnt++;
	}
	gets(buff);
	sscanf(buff, "%d", &q);
	vector<int> qs;
	for(int i=0; i<q; i++) {
		gets(buff);
		string s=  buff;
		int idx = M[s];
		qs.push_back(idx);
	}
	int best = q+  3;
	int dp[q+1][n+1];
	memset(dp, 63, sizeof(dp));
	for(int i=0; i<n; i++) dp[0][i] = 0;
	for(int j=0; j<q; j++) for(int i=0; i<n; i++) {
		if(qs[j] == i) {
			for(int k=0; k<n; k++) if(k!=i)
				dp[j+1][k] = min(dp[j+1][k], dp[j][i] + 1);
		}
		else dp[j+1][i] = min(dp[j+1][i], dp[j][i]);
	}
	for(int i=0; i<n; i++) best = min(best, dp[q][i]);
	printf("Case #%d: %d\n", tcase, best);

}



int main() {
	int t, c=0;
	scanf("%d ", &t);
	while(t--) {
		solve(++c);
	}
}
