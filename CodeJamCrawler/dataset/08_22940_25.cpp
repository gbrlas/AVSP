#include <stdio.h>
#include <memory.h>

#define FOR(i,n) for(i=0;i<n;i++)
#define SFOR(i,m,n) for(i=m;i<n;i++)

int X[100010], Y[100010], G[100010];

int main() {
	FILE *fp, *fp1;
	fp = fopen("A-large.in","r");
	fp1 = fopen("A-large.out","w");
	__int64 t,tt,n,A,B,C,D,x0,y0,M,i;
	fscanf(fp,"%I64d",&tt);
	FOR(t,tt) {
		fscanf(fp,"%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&n,&A,&B,&C,&D,&x0,&y0,&M);
		X[0] = x0; Y[0] = y0;
		SFOR(i,1,n) {
			X[i] = (A * X[i-1] + B) % M;
			Y[i] = (C * Y[i-1] + D) % M;
		}
		__int64 K[9];
		memset(K,0,sizeof(K));
		FOR(i,n) K[(X[i]%3)*3 + (Y[i]%3)]++;
		__int64 ans = K[0]*K[4]*K[8] + K[0]*K[5]*K[7] + K[1]*K[3]*K[8] + K[1]*K[5]*K[6] + K[2]*K[3]*K[7] + K[2]*K[4]*K[6];
		ans += K[0]*K[1]*K[2] + K[3]*K[4]*K[5] + K[6]*K[7]*K[8] + K[0]*K[3]*K[6] + K[1]*K[4]*K[7] + K[2]*K[5]*K[8];
		FOR(i,9) ans += (K[i]*(K[i]-1)*(K[i]-2))/6;
		fprintf(fp1,"Case #%I64d: %I64d\n",t+1,ans);
	}
	fclose(fp);
	fclose(fp1);
	return 0;
}