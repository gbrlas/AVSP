#include <cstdio>
#include <algorithm>
#include <vector>
#define N 10005
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
using namespace std;

int t, n, d[N], l[N], x, dp[N];

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-out.txt", "w", stdout);
	
	scanf("%d", &t);
	FI(z, 1, t){
		scanf("%d", &n);
		fi(i, 0, n) scanf("%d %d", &d[i], &l[i]);
		dp[0] = d[0];
		
		scanf("%d", &x);
		d[n] = x; l[n] = 1 << 30;
		FI(i, 1, n) dp[i] = -1;
		
		FI(i, 1, n){
			fi(j, 0, i) if(dp[j] + d[j] >= d[i])
				dp[i] = max(dp[i], d[i] - d[j]);
			dp[i] = min(dp[i], l[i]);
		}
		
		printf("Case #%d: %s\n", z, dp[n] < 0 ? "NO" : "YES");
	}
	
	scanf("\n");
}
