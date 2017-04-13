#include <cstdio>
#include <algorithm>
#define N 1000005
#define LL long long
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define fd(a, b, c) for(int a = (b); a > (c); a--)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
#define FD(a, b, c) for(int a = (b); a >= (c); a--)
#define fe(a, b, c) for(int a = (b); a; a = c[a])
using namespace std;

int t, n, p, q, r, s;
LL a[N];
double ans;

void solve(){
	scanf("%d %d %d %d %d", &n, &p, &q, &r, &s);
	FI(i, 1, n){
		a[i] = ((LL) (i - 1) * p + q) % r + s;
		a[i] += a[i - 1];
	}
	
	ans = 0;
	FI(i, 1, n) FI(j, i, n){
		LL take = max(a[i - 1], a[j] - a[i - 1]);
		take = max(take, a[n] - a[j]);
		
		ans = max(ans, (double) (a[n] - take) / a[n]);
	}
	
	printf("%.10lf\n", ans);
}

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	scanf("%d", &t);
	FI(z, 1, t){
		printf("Case #%d: ", z);
		solve();
	}
	scanf("\n");
}
