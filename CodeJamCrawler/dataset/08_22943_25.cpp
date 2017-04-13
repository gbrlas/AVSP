#include <stdio.h>
#include <memory.h>

#define FOR(i,n) for(i=0;i<n;i++)
#define SFOR(i,m,n) for(i=m;i<n;i++)
#define lint __int64

int P[1000010];
int S[1000010];
int BB[1000010];

int main() {
	FILE *fp, *fp1;
	fp = fopen("B-small.in","r");
	fp1 = fopen("B-small.out","w");
	int PP,t,tt,sp = 1,j,KK;
	P[0] = 2;
	lint A, B, i;
	SFOR(i,2,1000010) {
		FOR(j,sp) { if (i % P[j] == 0) break; if (i < P[j]*P[j]) { P[sp] = i; sp++; break; } }
	}
	fscanf(fp,"%d",&tt);
	FOR(t,tt) {
		fscanf(fp,"%I64d%I64d%d",&A,&B,&PP);
		FOR(i,B-A+1) S[i] = i;
		int K = B-A+1;
		FOR(j,sp) if ((P[j] >= PP) && (P[j] <= B-A+1)) {
			memset(BB,0,sizeof(BB));
			int f = 0;
			for(i=(A/P[j])*P[j];i <= (B/P[j]+1)*P[j]; i += P[j]) if ((i >= A) && (i <= B)) {
				if (BB[S[i-A]] == 0) { f++; BB[S[i-A]] = 1; KK = S[i-A]; }
			}
			if (f > 1) {
				K -= f - 1;
				FOR(i,B-A+1) if (BB[S[i]] == 1) S[i] = KK;
			}
		}
		fprintf(fp1,"Case #%d: %d\n",t+1,K);
	}
	fclose(fp);
	fclose(fp1);
}