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
	fp = fopen("B-small.in","r");
	fp1 = fopen("B-small.out","w");
	int t,tt,i,j,k,p,N,M,A;
	fscanf(fp,"%d",&tt);
	FOR(t,tt) {
		fscanf(fp,"%d%d%d",&N,&M,&A);
		FOR(i,N+1) FOR(j,M+1) FOR(k,N+1) FOR(p,M+1) if (i*p - j*k == A) {
			fprintf(fp1,"Case #%d: 0 0 %d %d %d %d\n",t+1,i,j,k,p);
			i = j = k = p = 1000;
		}
		if (i != 1001) fprintf(fp1,"Case #%d: IMPOSSIBLE\n",t+1);
	}
	fclose(fp);
	fclose(fp1);
}