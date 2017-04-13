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

int A[100][100];
int B[100];

int main() {
	FILE* fp = fopen("A.in","r");
	FILE* fout = fopen("A.out","w");
	int tt,i,t,k,j,N, ans;
	char ch;
	fscanf(fp,"%d",&tt);
	FOR(t,tt) {
		ans = 0;
		fscanf(fp,"%d",&N);
		FOR(i,N) FOR(j,N) { do { fscanf(fp,"%c",&ch); } while ((ch != '0') && (ch != '1')); A[i][j] = ch-'0'; }
		FOR(i,N) {
			B[i] = 0;
			FOR(j,N) if (A[i][j] == 1) B[i] = j;
		}
		FOR(i,N) {
			SFOR(j,i,N) if (B[j] <= i) break;
			for(k=j;k>i;k--) B[k] = B[k-1];
			ans += (j-i);
		}
		fprintf(fout,"Case #%d: %d\n", t+1, ans);
	}
	fclose(fp);
	fclose(fout);
	return 0;
}