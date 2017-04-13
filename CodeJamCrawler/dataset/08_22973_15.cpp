#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

#define sz size()
#define pb push_back
#define FOR(i,n) for(i=0;i<n;i++)
#define SFOR(i,m,n) for(i=m;i<n;i++)

int A[100][100];
int FF[20][2000];

int n,m;

int F(int q, int w) {
	if (q == -1) return 0;
	if (FF[q][w] == -1) {
		int i,j,k,ans = 0;
		FOR(k,(1<<n)) {
			i = 0;
			FOR(j,n-1) if ((k & (1<<j)) != 0) {
				if ((k & (1<<(j+1))) != 0) break;
				if ((w & (1<<(j+1))) != 0) break;
			}
			if (j != n-1) continue;
			SFOR(j,1,n) if ((k & (1<<j)) != 0) {
				if ((k & (1<<(j-1))) != 0) break;
				if ((w & (1<<(j-1))) != 0) break;
			}
			if (j != n) continue;
			FOR(j,n) if ((k & (1<<j)) != 0) {
				if (A[q][j] == 0) break;
				i++;
			}
			if (j != n) continue;
			if (ans < i + F(q-1,k)) ans = i + F(q-1,k);
		}
		FF[q][w] = ans;
	}
	return FF[q][w];
}

int main() {
	FILE *fp = fopen("C-small.in","r");
	FILE *fp1 = fopen("C-small.out","w");
	int t,tt,i,j,k;
	char ch;
	fscanf(fp,"%d",&tt);
	FOR(t,tt) {
		fscanf(fp,"%d%d",&m,&n);
		FOR(i,m) FOR(j,n) {
			do { fscanf(fp,"%c",&ch); } while ((ch != 'x') && (ch != '.'));
			if (ch == '.') A[i][j] = 1; else A[i][j] = 0;
		}
		memset(FF,0xFF,sizeof(FF));
		fprintf(fp1,"Case #%d: %d\n",t+1,F(m-1,0));
	}
	fclose(fp1);
	fclose(fp);
	return 0;
}