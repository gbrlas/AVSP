#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <algorithm>

using namespace std;

#define FOR(i,n) for(i=0;i<n;i++)
#define SFOR(i,m,n) for(i=m;i<n;i++)
#define lint __int64

int main() {
	FILE *fp, *fp1;
	fp = fopen("B-large.in","r");
	fp1 = fopen("B-large.out","w");
	int t,tt,i,j,k,p,N,M,A;
	fscanf(fp,"%d",&tt);
	FOR(t,tt) {
		fscanf(fp,"%d%d%d",&N,&M,&A);
		FOR(i,N+1) if (i*M >= A) {
			fprintf(fp1,"Case #%d: 0 0 %d %d %d %d\n", t+1, i, M*i-A, 1, M);
			break;
		}
		if (i == N+1) fprintf(fp1,"Case #%d: IMPOSSIBLE\n",t+1);
	}
	fclose(fp);
	fclose(fp1);
}