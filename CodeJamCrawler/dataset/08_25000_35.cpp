#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>

#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define CLEAR(a,v) memset((a), (v), sizeof(x))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;
const double eps = 1e-9;
const int INF = 1000000000;
const LL LLINF = (LL)INF * INF;
const double PI = 2 * acos(.0);

char buf[16][16];
int dp[16][1<<12];
int cnt_dig[1<<12], can[1<<12];
int n, m;

int fit(int mk, char *buf) {
	for (int i = 0 ; i < m ; i++)
		if ((mk&(1<<i)) && buf[i] == 'x') return 0;
	return 1;
}

int fit2(int mk, int mk2) {
	int i;
	for (i = 0 ; i < m ; i++) {
		if (mk2&(1<<i)) {
			if (i && (mk&(1<<(i-1)))) return 0;
			if (i < m - 1 && (mk&(1<<(i+1)))) return 0;

		}
	}
	return 1;
}

int main() {
	freopen("C-small.in","r",stdin);
	freopen("C-small.out","w",stdout);
	int T, i, mk, tmk, pre, ca = 0;
	for (mk = 0 ; mk < (1<<10) ; mk++) {
		for (i = 0 ; i < 10 ; i++)
			if (mk&(1<<i)) ++cnt_dig[mk];
		can[mk] = 1;
		for (i = 0 , pre = 0 ; i < 10 ; i++) {
			if (mk&(1<<i)) {
				if (pre) {can[mk] = 0; break;}
			}
			pre = (mk&(1<<i));
		}
	}

	//for (i = 0 ; i < 32 ; i++)
	//	printf("cnt[%d]:%d can[%d]:%d\n",i,cnt_dig[i],i,can[i]);

	scanf("%d",&T);
	while (T--) {
		scanf("%d%d",&n,&m);
		for (i = 0 ; i < n ; i++)
			scanf("%s",buf[i]);
		memset(dp, -1, sizeof(dp));
		for (mk = 0 ; mk < (1<<m) ; mk++) {
			if (fit(mk, buf[0]) == 0 || !can[mk]) continue;
			dp[0][mk] = cnt_dig[mk];
		}
		//printf("__%d\n",dp[0][7]);
		for (i = 0 ; i < n - 1 ; i++) {
			for (mk = 0 ; mk < (1<<m) ; mk++) {
				if (dp[i][mk] == -1) continue;
				for (tmk = 0 ; tmk < (1<<m) ; tmk++) {
					if (fit(tmk, buf[i+1]) == 0 || !can[tmk]) continue;
					if (fit2(mk, tmk) == 0) continue;
					dp[i+1][tmk] >?= dp[i][mk] + cnt_dig[tmk];
				}
			}
		}
		/*
		for (i = 0 ; i <= n ; i++)
			for (mk = 0 ; mk < (1<<m) ; mk++)
				printf("dp[%d][%d]:%d\n",i,mk,dp[i][mk]);
		*/int ans = 0;
		for (i = 0 ; i < n ; i++)
		for (mk = 0 ; mk < (1<<m) ; mk++) {
			ans >?= dp[i][mk];
			//printf("mk:%d dp:%d\n",mk,dp[n][mk]);
		}
		printf("Case #%d: %d\n",++ca, ans);
	}
	return 0;
}
