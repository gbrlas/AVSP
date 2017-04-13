#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define sz size()
#define pb push_back
#define FOR(i,n) for(i=0;i<n;i++)
#define SFOR(i,m,n) for(i=m;i<n;i++)
#define lint __int64

int X[100000], Y[100000], Z[100000], P[100000], T[100000], N;

double ans;

void F() {
	int i;
	double l = 0, h = 1E10, m;
	l = 0;
	h = 1E10;
	while (h > l + 0.00000001) {
		m = (l + h)/2;
		double __l = -10000000, __h = 10000000;
		FOR(i,N) __l = max(__l,T[i] - m*P[i]);
		FOR(i,N) __h = min(__h,T[i] + m*P[i]);
		if (__l >= __h) l = m; else h = m;
	}
	if (ans < m) ans = m;
}

int main() {
	FILE *fp, *fp1;
	fp = fopen("C-large.in","r");
	fp1 = fopen("C-large.out","w");
	int t,tt,i;
	fscanf(fp,"%d",&tt);
	FOR(t,tt) {
		fscanf(fp,"%d",&N);
		FOR(i,N) fscanf(fp,"%d%d%d%d",&X[i],&Y[i],&Z[i],&P[i]);
		ans = 0;
		FOR(i,N) T[i] = X[i] + Y[i] + Z[i]; F();
		FOR(i,N) T[i] = X[i] + Y[i] - Z[i]; F();
		FOR(i,N) T[i] = X[i] - Y[i] + Z[i]; F();
		FOR(i,N) T[i] = X[i] - Y[i] - Z[i]; F();
		FOR(i,N) T[i] = - X[i] + Y[i] + Z[i]; F();
		FOR(i,N) T[i] = - X[i] + Y[i] - Z[i]; F();
		FOR(i,N) T[i] = - X[i] - Y[i] + Z[i]; F();
		FOR(i,N) T[i] = - X[i] - Y[i] - Z[i]; F();
		fprintf(fp1,"Case #%d: %.7lf\n",t+1,ans);
	}
	fclose(fp);
	fclose(fp1);
}