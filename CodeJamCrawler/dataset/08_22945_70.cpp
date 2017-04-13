#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <algorithm>

using namespace std;

#define FOR(i,n) for(i=0;i<n;i++)
#define SFOR(i,m,n) for(i=m;i<n;i++)
#define lint __int64

int G[10010], C[10010], V[10010];
int A[2][10010];

int F(int q, int w) {
	if (A[q][w] == -1) {
		if (V[w] == 1-q) { A[q][w] = -2; return -2; }
		if (V[w] == q) { A[q][w] = 0; return 0; }
		int ans = -2, t, t1, t2;
		if ((G[w] == 0) || (C[w] == 1)) {
			if (q == 1) {
				t1 = F(1,2*w+1);
				t2 = F(1,2*w);
				if (t1 == -2) t = t2; else if (t2 == -2) t = t1; else t = min(t1,t2);
			}
			if (q == 0) {
				t1 = F(0,2*w+1);
				t2 = F(0,2*w);
				if ((t1 == -2) || (t2 == -2)) t = -2; else t = t1 + t2;
			}
			if ((G[w] == 1) && (t != -2)) t++;
			if ((t != -2) && ((ans == -2) || (ans > t))) ans = t;
		}
		if ((G[w] == 1) || (C[w] == 1)) {
			if (q == 0) {
				t1 = F(0,2*w+1);
				t2 = F(0,2*w);
				if (t1 == -2) t = t2; else if (t2 == -2) t = t1; else t = min(t1,t2);
			}
			if (q == 1) {
				t1 = F(1,2*w+1);
				t2 = F(1,2*w);
				if ((t1 == -2) || (t2 == -2)) t = -2; else t = t1 + t2;
			}
			if ((G[w] == 0) && (t != -2)) t++;
			if ((t != -2) && ((ans == -2) || (ans > t))) ans = t;
		}
		A[q][w] = ans;
	}
	return A[q][w];
}

int main() {
	FILE *fp, *fp1;
	fp = fopen("A-small.in","r");
	fp1 = fopen("A-small.out","w");
	int t,tt,M,VV,i;
	fscanf(fp,"%d",&tt);
	FOR(t,tt) {
		memset(V,0xFF,sizeof(V));
		memset(G,0,sizeof(G));
		memset(C,0,sizeof(C));
		fscanf(fp,"%d%d%",&M,&VV);
		FOR(i,(M-1)/2) fscanf(fp,"%d%d",&G[i+1],&C[i+1]);
		SFOR(i,(M-1)/2,M) fscanf(fp,"%d",&V[i+1]);
		memset(A,0xFF,sizeof(A));
		F(VV,1);
		if (A[VV][1] == -2) fprintf(fp1,"Case #%d: IMPOSSIBLE\n",t+1); else fprintf(fp1,"Case #%d: %d\n",t+1,A[VV][1]);
	}
	fclose(fp);
	fclose(fp1);
}