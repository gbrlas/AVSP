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

int A[200][200], B[200][200];

int N;

int V[100];

bool Check(int k) {
	int i,j;
	FOR(i,N) FOR(j,N) if (((k & (1<<i)) != 0) && ((k & (1<<j)) != 0) && (B[i][j] == 0)) return false;
	return true;
}

int main() {
	FILE* fp = fopen("C.in","r");
	FILE* fout = fopen("C.out","w");
	int tt,i,t,k,j,K,ans;
	fscanf(fp,"%d",&tt);
	FOR(t,tt) {
		fscanf(fp,"%d%d",&N,&K);
		FOR(i,N) FOR(j,K) fscanf(fp,"%d",&A[i][j]);
		memset(B,0,sizeof(B));
		FOR(i,N) FOR(j,N) FOR(k,K-1) if (((A[i][k] >= A[j][k]) && (A[i][k+1] <= A[j][k+1])) || ((A[i][k] <= A[j][k]) && (A[i][k+1] >= A[j][k+1]))) { B[i][j] = 1; if (i + j == 1) printf("%d\n",k); }
		ans = 0;
		FOR(k,(1<<N)) {
			if (Check(k)) {
				j = 0;
				FOR(i,N) if ((k & (1<<i)) != 0) j++;
				if (j > ans) ans = j;
			}
		}
		fprintf(fout,"Case #%d: %d\n",t+1,ans);
	}
	fclose(fp);
	fclose(fout);
	return 0;
}