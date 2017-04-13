#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

#define ss stringstream
#define lint __int64
#define sz size()
#define pb push_back
#define FOR(i,n) for(i=0;i<n;i++)
#define SFOR(i,m,n) for(i=m;i<n;i++)
#define FORD(i,n) for(i=n-1;i>=0;i--)

string S[500];
int X[500], Y[500], TX[500], TY[500], C[500]; 
int A[500];

int ans;
int K;

void F() {
	int i,j,k;
	FOR(i,K) {
		if (X[i] == 1) A[i] = 1; else A[i] = 100000000;
		FOR(j,i) if (Y[j] >= X[i]-1) A[i] = min(A[i],A[j]+1);
	}
	FOR(i,K) if (Y[i] == 10000) ans = min(ans,A[i]);
}

int main() {
	FILE *fp = fopen("B-large.in","r");
	FILE *fp1 = fopen("B-large.out","w");
	int t,tt;
	int i;
	char buf[1000];
	int j,k;
	int N;
	fscanf(fp,"%d\n",&tt);
	FOR(t,tt) {
		fscanf(fp,"%d\n",&N);
		FOR(i,N) { fscanf(fp,"%s%d%d\n",buf,&TX[i],&TY[i]); S[i] = string(buf); }
		FOR(i,N) FOR(j,N-1) if (TX[j] > TX[j+1]) { swap(TX[j],TX[j+1]); swap(TY[j],TY[j+1]); swap(S[j],S[j+1]); }
		FOR(i,N) {
			FOR(j,N) if (S[i] == S[j]) break;
			C[i] = j;
		}
		ans = 1000000;
		K = -1;
		FOR(i,N) if (C[i] == i) SFOR(j,i+1,N) if (C[j] == j) SFOR(k,j+1,N) if (C[k] == k) {
			K = 0;
			int q;
			FOR(q,N) if ((C[q] == i) || (C[q] == j) || (C[q] ==  k)) { X[K] = TX[q]; Y[K] = TY[q]; K++; }
			F(); 
		}
		if (K == -1) {
			int q;
			K = 0;
			FOR(q,N) { X[K] = TX[q]; Y[K] = TY[q]; K++; }
			F(); 
		}
		fprintf(fp1,"Case #%d: ",t+1);
		if (ans == 1000000) fprintf(fp1,"IMPOSSIBLE\n"); else fprintf(fp1,"%d\n",ans);
		printf("Case #%d: ",t+1);
		if (ans == 1000000) printf("IMPOSSIBLE\n"); else printf("%d\n",ans);
	}
	fclose(fp);
	fclose(fp1);
	return 0;
}