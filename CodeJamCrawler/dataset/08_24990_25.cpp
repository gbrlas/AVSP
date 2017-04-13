#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

const int MAXN = 100010;
const int INF = 1000000001;
struct SS {int type, chg;} a[MAXN];
int dp[MAXN][2];

#define MIN(a,b) ((a)<(b)?(a):(b))

int solve(int p, int vv) {
	int L0, L1, R0, R1;
	if (dp[p][vv] != -1) return dp[p][vv];
	if (a[p].chg == 2) { //leaf
		if (a[p].type == vv) return dp[p][vv] = 0;
		else return dp[p][vv] = INF;
	} else if (a[p].chg == 1) {
		L0 = solve(p*2, 0);
		L1 = solve(p*2, 1);
		R0 = solve(p*2+1, 0);
		R1 = solve(p*2+1, 1);
		if (a[p].type == 0) {	//OR
			if (vv == 0) {
				dp[p][vv] = INF;
				dp[p][vv] <?= L0 + R0;
				dp[p][vv] <?= L0 + R1 + 1;
				dp[p][vv] <?= L1 + R0 + 1;
				dp[p][vv] <?= L0 + R0 + 1;
				return dp[p][vv];
			} else {
				dp[p][vv] = INF;
				dp[p][vv] <?= L0 + R1;
				dp[p][vv] <?= L1 + R0;
				dp[p][vv] <?= L1 + R1;
				dp[p][vv] <?= L1 + R1 + 1;
				return dp[p][vv];
			}
		} else {	//AND
			if (vv == 1) {
				dp[p][vv] = MIN(INF, L1 + R1);
				dp[p][vv] <?= L0 + R1 + 1;
				dp[p][vv] <?= L1 + R0 + 1;
				dp[p][vv] <?= L1 + R1 + 1;
				return dp[p][vv];
			} else {
				dp[p][vv] = INF;
				dp[p][vv] <?= L0 + R1;
				dp[p][vv] <?= L1 + R0;
				dp[p][vv] <?= L0 + R0;
				dp[p][vv] <?= L0 + R0 + 1;
				return dp[p][vv];
			}
		}
	} else {
		L0 = solve(p*2, 0);
		L1 = solve(p*2, 1);
		R0 = solve(p*2+1, 0);
		R1 = solve(p*2+1, 1);
		if (a[p].type == 0) {	//OR
			if (vv == 0) return dp[p][vv] = MIN(INF, L0 + R0);
			else {
				dp[p][vv] = INF;
				dp[p][vv] <?= L0 + R1;
				dp[p][vv] <?= L1 + R0;
				dp[p][vv] <?= L1 + R1;
				return dp[p][vv];
			}
		} else {	//AND
			if (vv == 1) return dp[p][vv] = MIN(INF, L1 + R1);
			else {
				dp[p][vv] = INF;
				dp[p][vv] <?= L0 + R1;
				dp[p][vv] <?= L1 + R0;
				dp[p][vv] <?= L0 + R0;
				return dp[p][vv];
			}
		}
	}
}

int main() {
	//freopen("A-small-attempt0.in","r",stdin);
	//freopen("A.0.out","w",stdout);
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int T, m, v, i, ans, ca = 0;
	scanf("%d",&T);
	while (T--) {
		scanf("%d%d",&m,&v);
		for (i = 1 ; i <= (m-1) /2 ; i++) {
			scanf("%d%d",&a[i].type,&a[i].chg);
		}
		for ( ; i <= m ; i++) {
			scanf("%d",&a[i].type);
			a[i].chg = 2;
		}
		//printf("done\n");
		memset(dp, -1, sizeof(dp));
		int ans = solve(1,v);
		printf("Case #%d: ",++ca);
		if (ans >= INF) printf("IMPOSSIBLE\n");
		else printf("%d\n",ans);
	}
	return 0;
}
