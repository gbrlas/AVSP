#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <map>
//#include <math.h>
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

int dx[9] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
int dy[9] = {1, -1, 0, 1, -1, 0, 1, -1, 0};

int A[10][10], B[10][10];

int main() {
	int t,tt;
	FILE *fp = fopen("C-small.in","r");
	FILE *fp1 = fopen("C-small.out","w");
	fscanf(fp,"%d",&tt);
	FOR(t,tt) {
		int m,n,i,j,k,p,q,ans = 0;
		fscanf(fp,"%d%d",&m,&n);
		FOR(i,m) FOR(j,n) fscanf(fp,"%d",&A[i+1][j+1]);
		memset(B,0,sizeof(B));
		FOR(k,(1<<(m*n))) {
			FOR(i,m) FOR(j,n) if ((k & (1<<(i*n+j))) != 0) B[i+1][j+1] = 1; else B[i+1][j+1] = 0;
			FOR(i,m) { FOR(j,n) {
				q = 0;
				FOR(p,9) q += B[i+1+dx[p]][j+1+dy[p]];
				if (q != A[i+1][j+1]) break;
			} if (j != n) break; }
			if (i == m) {
				q = 0;
				FOR(j,n) q += B[1+m/2][j+1];
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