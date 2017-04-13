#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define openfile {freopen("B-large.in","r",stdin);freopen("a.out","w",stdout);}
#define debug 01

int n, s, p, te, t[105];
int f[105][105];

void init() {
	memset(f,0,sizeof(f[0][0])*105*105);
	f[0][1] = -999999999;
}

int analyze1(int x) {
	x--;
	int res = 0, k;
	for (int i=0;i<=10;i++) {
		for (int j=i-1;j<=i+1;j++) {
			if (j<0) continue;
			k = t[x]-i-j;
			if (k<0) continue;
			if (abs(k-i)<2&&abs(k-j)<2) 
				res = max(res,max(i,max(j,k)));
		}
	}
	return res;
}

int analyze2(int x) {
	x--;
	int res = 0, k, cnt;
	for (int i=0;i<=10;i++) {
		for (int j=i-2;j<=i+2;j++) {
			if (j<0) continue;
	 		k = t[x]-i-j;
	 		if (k<0) continue;
	 		cnt = 0;
	 		if (abs(k-i)>2) cnt++;
	 		if (abs(k-j)>2) cnt++;
	 		if (abs(i-j)>2) cnt++;
	 		if (cnt==0)
	 			res = max(res,max(i,max(j,k)));	
		}
	}
	return res;
}

void solve() {
	int x;
	for (int i=1;i<=n;i++)
	for (int j=0;j<=min(i,s);j++) {
		//th1
		if (f[i-1][j]>=0) {
			x = analyze1(i);
			if (x>=p) f[i][j] = max(f[i][j],f[i-1][j]+1);
			else f[i][j] = max(f[i][j],f[i-1][j]);
		}
		/******/
		//th2
		if (j==0) continue;
		x = analyze2(i);
		if (x>=p) f[i][j] = max(f[i][j],f[i-1][j-1]+1);
		else f[i][j] = max(f[i][j],f[i-1][j-1]);
	}
}

int main() {
	if (debug) openfile;
	scanf("%d",&te);
	for (int i=0;i<te;i++) {
		scanf("%d%d%d",&n,&s,&p);
		for (int j=0;j<n;j++) scanf("%d",&t[j]);
		init();
		solve();
		printf("Case #%d: %d\n",i+1,f[n][s]);
	}
}
