#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <math.h>
#include <algorithm>
#include <utility>

using namespace std;

#define lint __int64
#define ss stringstream
#define sz size()
#define pb push_back
#define FOR(i,n) for(i=0;i<n;i++)
#define SFOR(i,m,n) for(i=0;i<n;i++)
#define FORD(i,n) for(i=n-1;i>=0;i--)

int A[10000], B[10000], C[10000];

int main() {
	int t,tt;
	FILE *fp = fopen("A-small.in","r");
	FILE *fp1 = fopen("A-small.out","w");
	fscanf(fp,"%d",&tt);
	FOR(t,tt) {
		int i,j,k,N,q,c,ans = 0;
		fscanf(fp,"%d",&N);
		FOR(i,N) fscanf(fp,"%d%d%d",&A[i],&B[i],&C[i]);
		FOR(i,N) FOR(j,N-1) if (A[j] > A[j+1]) { swap(A[j],A[j+1]); swap(B[j],B[j+1]); swap(C[j],C[j+1]); }
		FOR(k,N) {
			FOR(j,k+1) {
				c = 10000-A[k]-B[j];
				q = 0;
				FOR(i,k+1) if ((B[i] <= B[j]) && (C[i] <= c)) q++;
				if (ans < q) ans = q;
			}
		}
		printf("Case #%d: %d\n", t+1, ans);
		fprintf(fp1,"Case #%d: %d\n", t+1, ans);
	}
	fclose(fp1);
	fclose(fp);
	return 0;
}