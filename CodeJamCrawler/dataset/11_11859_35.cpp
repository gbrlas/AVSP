#include <iostream>
#include <cassert>
using namespace std;

#define MAX_N 1000
#define MAX_ITERS 100

long double tmax(long double x, long double y) {return (x >= y ? x : y);}

bool ispossible(int n, long double * x, long double * dp, long double * dn, long double y) {
	//x[0] moves to x[0] - y
	//x[i] moves to max(x[i]-y, x[i-1]+dp[i-1]+dn[i])
	//possible if x[i] moves no further than x[i] + y.
	long double tmp = x[0] - y;
	for (int i = 1; i < n; i++) {
		//tmp = new position of x[i-1]
		tmp = tmax(x[i]-y, tmp+dp[i-1]+dn[i]);
		//tmp = new position of x[i]
		if (tmp > x[i] + y) return false;
	}
	return true;
} 

long double smallestpossible(int n, long double * x, long double * dp, long double * dn) {
	if (ispossible(n, x, dp, dn, 0)) return 0;
	long double yinf = 0, ymax = 1;
	for (int i = 0; i < n; i++) ymax += dp[i] + dn[i];
	assert(ispossible(n, x, dp, dn, ymax));
	for (int i = 0; i < MAX_ITERS; i++) {
		long double ymed = (yinf + ymax) / 2;
		if (ispossible(n, x, dp, dn, ymed)) 
			ymax = ymed;
		else
			yinf = ymed;
	}
	return ymax;
}

long double xx[MAX_N], dp[MAX_N], dn[MAX_N];

int main() {
	int t;
	cin >> t;
	for (int cas = 1; cas <= t; cas++) {
		int c; long double d;
		cin >> c >> d;
		for (int i = 0; i < c; i++) {
			long double p, v;
			cin >> p >> v;
			xx[2*i] = xx[2*i+1] = p;
			assert(i == 0 || xx[i] >= xx[i-1]);
			dp[2*i] = dn[2*i+1] = d * (v-1) / 2;
			dn[2*i] = dp[2*i+1] = d / 2;
		}
		long double ans = smallestpossible(2 * c, xx, dp, dn);
		cout << "Case #" << cas << ": " << ans << endl;
	}
	return 0;
}

