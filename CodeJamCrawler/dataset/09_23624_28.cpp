#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>

using namespace std;

#define lint long long

#define sz size()
#define pb push_back

#define FOR(i,n) SFOR(i,0,n)
#define SFOR(i,m,n) for(i=m;i<n;i++)
#define FORD(i,n) for(i=n-1;i>=0;i--)

double X[100], Y[100], R[100];
double D[100][100];

int N;

int V[100];

bool Check(double RR) {
	int i,j,k,p,q;
	double x, y, l, d1, d2, DD, x1, y1;
	bool w;
	FOR(i,N) SFOR(j,i+1,N) if (D[i][j] < 2*RR - R[i] - R[j]) {
		DD = D[i][j]; d1 = RR - R[i]; d2 = RR - R[j];
		DD = DD*DD; d1 = d1*d1; d2 = d2*d2;
		l = sqrt((2*(DD*d1 + DD*d2 + d1*d2) - DD*DD - d1*d1 - d2*d2)/(4*DD));
		DD = sqrt(d1-l*l);
		x = X[i] + (X[j]-X[i])*DD/D[i][j];
		y = Y[i] + (Y[j]-Y[i])*DD/D[i][j];
		x += (Y[j]-Y[i])*l/D[i][j];
		y += (X[i]-X[j])*l/D[i][j];
		x1 = x - 2*(Y[j]-Y[i])*l/D[i][j];
		y1 = y - 2*(X[i]-X[j])*l/D[i][j];
		memset(V,0,sizeof(V));
		FOR(q,N) if ((X[q]-x)*(X[q]-x) + (Y[q]-y)*(Y[q]-y) < (RR-R[q])*(RR-R[q]) + 0.0000001) V[q] = 1;
		k = 0;
		FOR(q,N) if (V[i] == 0) k++;
		if (k <= 1) return true;
		w = true;
		FOR(k,i) if (V[k] == 0) break;
		if (k != i) w = false;
		if (k == i)
		SFOR(k,i+1,N) if (V[k] == 0) SFOR(p,k+1,N) if (V[p] == 0) if (D[k][p] < 2*RR-R[i]-R[j]) {
			w = false;
			DD = D[k][p]; d1 = RR - R[k]; d2 = RR - R[p];
			DD = DD*DD; d1 = d1*d1; d2 = d2*d2;
			l = sqrt((2*(DD*d1 + DD*d2 + d1*d2) - DD*DD - d1*d1 - d2*d2)/(4*DD));
			DD = sqrt(d1-l*l);
			x = X[k] + (X[p]-X[k])*DD/D[k][p];
			y = Y[k] + (Y[p]-Y[k])*DD/D[k][p];
			x += (Y[p]-Y[k])*l/D[k][p];
			y += (X[k]-X[p])*l/D[k][p];
			FOR(q,N) if (V[q] == 0) if ((X[q]-x)*(X[q]-x) + (Y[q]-y)*(Y[q]-y) > (RR-R[q])*(RR-R[q]) + 0.0000001) break;
			if (q == N) return true;
			x -= 2*(Y[p]-Y[k])*l/D[k][p];
			y -= 2*(X[k]-X[p])*l/D[k][p];
			FOR(q,N) if (V[q] == 0) if ((X[q]-x)*(X[q]-x) + (Y[q]-y)*(Y[q]-y) > (RR-R[q])*(RR-R[q]) + 0.0000001) break;
			if (q == N) return true;
		}
		if (w) return true;
		x = x1; y = y1;
		memset(V,0,sizeof(V));
		FOR(q,N) if ((X[q]-x)*(X[q]-x) + (Y[q]-y)*(Y[q]-y) < (RR-R[q])*(RR-R[q])) V[q] = 1;
		k = 0;
		FOR(q,N) if (V[i] == 0) k++;
		if (k <= 1) return true;
		w = true;
		FOR(k,i) if (V[k] == 0) break;
		if (k != i) w = false;
		if (k == i)
		SFOR(k,i+1,N) if (V[k] == 0) SFOR(p,k+1,N) if (V[p] == 0) if (D[k][p] < 2*RR-R[i]-R[j]) {
			w = false;
			DD = D[k][p]; d1 = RR - R[k]; d2 = RR - R[p];
			DD = DD*DD; d1 = d1*d1; d2 = d2*d2;
			l = sqrt((2*(DD*d1 + DD*d2 + d1*d2) - DD*DD - d1*d1 - d2*d2)/(4*DD));
			DD = sqrt(d1-l*l);
			x = X[k] + (X[p]-X[k])*DD/D[k][p];
			y = Y[k] + (Y[p]-Y[k])*DD/D[k][p];
			x += (Y[p]-Y[k])*l/D[k][p];
			y += (X[k]-X[p])*l/D[k][p];
			FOR(q,N) if (V[q] == 0) if ((X[q]-x)*(X[q]-x) + (Y[q]-y)*(Y[q]-y) > (RR-R[q])*(RR-R[q]) + 0.0000001) break;
			if (q == N) return true;
			x -= 2*(Y[p]-Y[k])*l/D[k][p];
			y -= 2*(X[k]-X[p])*l/D[k][p];
			FOR(q,N) if (V[q] == 0) if ((X[q]-x)*(X[q]-x) + (Y[q]-y)*(Y[q]-y) > (RR-R[q])*(RR-R[q]) + 0.0000001) break;
			if (q == N) return true;
		}
		if (w) return true;
	}
	return false;
}

int main() {
	FILE* fp = fopen("D.in","r");
	FILE* fout = fopen("D.out","w");
	int tt,i,t,k,j,K,ans;
	double l,r,m;
	char ch;
	fscanf(fp,"%d",&tt);
	FOR(t,tt) {
		fscanf(fp,"%d",&N);
		FOR(i,N) fscanf(fp,"%lf%lf%lf",&X[i],&Y[i],&R[i]);
		FOR(i,N) SFOR(j,i+1,N) D[i][j] = sqrt((X[i]-X[j])*(X[i]-X[j]) + (Y[i]-Y[j])*(Y[i]-Y[j]));
		l = 1;
		FOR(i,N) if (l < R[i]) l = R[i];
		r = 1000000.0;
		if (N <= 2) r = l;
		while (r - l > 0.000000001) {
			m = (l+r)/2.0;
			if (Check(m)) r = m; else l = m;
		}
		fprintf(fout,"Case #%d: %.7lf\n",t+1,l);
	}
	fclose(fp);
	fclose(fout);
	return 0;
}