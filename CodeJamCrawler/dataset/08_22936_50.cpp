#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

#define sz size()
#define pb push_back
#define FOR(i,n) for(i=0;i<n;i++)

int main() {
	FILE *fp = fopen("B-large.in","r");
	FILE *fp1 = fopen("B-large.out","w");
	int t,tt,i,j;
	fscanf(fp,"%d\n",&tt);
	FOR(t,tt) {
		int T, NA, NB;
		fscanf(fp,"%d%d%d",&T,&NA,&NB);
		vector<int> Q,W;
		FOR(i,NA) {
			char b0[20],b1[20];
			fscanf(fp,"%s%s",b0,b1);
			int a = (b0[0]-'0')*600+(b0[1]-'0')*60+(b0[3]-'0')*10+(b0[4]-'0');
			int b = (b1[0]-'0')*600+(b1[1]-'0')*60+(b1[3]-'0')*10+(b1[4]-'0') + T;
			Q.pb(a); W.pb(0); Q.pb(b); W.pb(1);
		}
		FOR(i,NB) {
			char b0[20],b1[20];
			fscanf(fp,"%s%s",b0,b1);
			int a = (b0[0]-'0')*600+(b0[1]-'0')*60+(b0[3]-'0')*10+(b0[4]-'0');
			int b = (b1[0]-'0')*600+(b1[1]-'0')*60+(b1[3]-'0')*10+(b1[4]-'0') + T;
			Q.pb(a); W.pb(2); Q.pb(b); W.pb(3);
		}
		FOR(i,Q.sz) FOR(j,Q.sz-1) if ((Q[j] > Q[j+1]) || ((Q[j] == Q[j+1]) && (W[j+1]%2 == 1))) {
			swap(Q[j],Q[j+1]);
			swap(W[j],W[j+1]);
		}
		int A = 0, B = 0, QA = 0, QB = 0;
		FOR(i,Q.sz) {
			if (W[i] == 0) { QA--; if (QA < 0) { A++; QA++; } }
			if (W[i] == 1) QB++;
			if (W[i] == 2) { QB--; if (QB < 0) { B++; QB++; } }
			if (W[i] == 3) QA++;
		}
		fprintf(fp1,"Case #%d: %d %d\n",t+1,A,B);
	}
	fclose(fp1);
	fclose(fp);
	return 0;
}