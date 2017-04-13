#include <cstdio>
#include <algorithm>
#define N 105
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int tc, p, q, n, h[N], g[N], P[N], t[N], dp[N][10005][2], ans;

int hit(int x, int y){
	if(x % y == 0) return x / y;
	return x / y + 1;
}

void solve(){
	scanf("%d %d %d", &p, &q, &n);
	FI(i, 1, n){
		scanf("%d %d", &h[i], &g[i]);
		P[i] = hit((h[i] - 1) % q + 1, p);
		t[i] = hit(h[i], q);
	}
	
	FI(i, 0, n) FI(j, 0, 1000) dp[i][j][0] = dp[i][j][1] = -1e9;
	
	int ap = 0;
	dp[0][0][0] = 0;
	FI(i, 1, n){
		FI(j, 0, ap)
			dp[i][j + t[i]][0] = dp[i - 1][j][0];
		
		FI(j, 0, ap) if(j + t[i] > 0)
			dp[i][j + t[i] - 1][0] = max(dp[i][j + t[i] - 1][0], dp[i - 1][j][1]);
		
		FI(j, 0, ap) if(j + t[i] - P[i] >= 0)
			dp[i][j + t[i] - P[i]][1] = dp[i - 1][j][0] + g[i];
		
		FI(j, 0, ap) if(j + t[i] - P[i] > 0)
			dp[i][j + t[i] - P[i] - 1][1] = max(dp[i][j + t[i] - P[i] - 1][1], dp[i - 1][j][1] + g[i]);

		ap += t[i];
		
		//FI(j, 0, ap) printf("%d %d %d %d\n", i, j, dp[i][j][0], dp[i][j][1]);
	}
	
	ans = 0;
	FI(i, 0, ap) ans = max(ans, dp[n][i][0]);
	FI(i, 0, ap) ans = max(ans, dp[n][i][1]);
	
	printf("%d\n", ans);
}

int main(){
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);
	scanf("%d", &tc);
	FI(z, 1, tc){
		printf("Case #%d: ", z);
		solve();
	}
	scanf("\n");
}
