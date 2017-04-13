#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 500000001

int t;
int v[1010], memo[MAX+1];

int f(int n, int m, int xn, int xm, int k) {
	if (k == t) {
		if (!n || !m) return 0;
		if (xn == xm) return max(n,m);
		return 0;
	}

	if (n > MAX) {
		if (memo[m] != -1) return memo[m];
		memo[m] = max(f(n-v[k],m+v[k],xn^v[k],xm^v[k],k+1), f(n,m,xn,xm,k+1));
		return memo[m];
	}

	if (memo[n] != -1) return memo[n];

	memo[n] = max(f(n-v[k],m+v[k],xn^v[k],xm^v[k],k+1), f(n,m,xn,xm,k+1));
	
	if (m<MAX) memo[m] = memo[n];	

	return memo[n];

} 

int main() {
		int n,xn,nteste=1,nt,res;
		scanf("%d",&nt);
		while (nt--) {
			scanf("%d",&t);
			n = xn = 0;
			for (int i=0; i<t; i++) { scanf("%d",&v[i]); n += v[i];	xn = xn^v[i]; }
			memset(memo,-1,sizeof(memo));
			res = f(n,0,xn,0,0);
			if (!res) printf("Case #%d: NO\n",nteste++);
			else printf("Case #%d: %d\n",nteste++,res);
		}
		return 0;
}
