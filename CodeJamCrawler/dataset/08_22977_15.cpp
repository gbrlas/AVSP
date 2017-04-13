#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

#define sz size()
#define pb push_back
#define FOR(i,n) for(i=0;i<n;i++)
#define SFOR(i,m,n) for(i=m;i<n;i++)

int A[1000][1000];

int main() {
	FILE *fp = fopen("D-small.in","r");
	FILE *fp1 = fopen("D-small.out","w");
	int t,tt,i,j,k,H,W,R;
	fscanf(fp,"%d",&tt);
	FOR(t,tt) {
		fscanf(fp,"%d%d%d",&H,&W,&R);
		memset(A,0,sizeof(A));
		FOR(i,R) { fscanf(fp,"%d%d",&j,&k); A[j+1][k+1] = -1; }
		A[2][2] = 1;
		SFOR(i,2,H+2) SFOR(j,2,W+2) if (i+j != 4) if (A[i][j] == -1) A[i][j] = 0; else A[i][j] = (A[i-2][j-1] + A[i-1][j-2]) % 10007;
		fprintf(fp1,"Case #%d: %d\n",t+1,A[H+1][W+1]);
	}
	fclose(fp1);
	fclose(fp);
	return 0;
}