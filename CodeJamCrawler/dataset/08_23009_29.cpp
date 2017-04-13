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
#define SFOR(i,m,n) for(i=m;i<n;i++)
#define FORD(i,n) for(i=n-1;i>=0;i--)

char C[20][20];
int FF[20][100000];

int m,n;

int S[100000], S3[100000], V[20][100000];
int AA[20][100000], sAA[20];

int F(int q, int w) {
	if (FF[q][w] == -1) {
		if (q == m) { FF[q][w] = 0; return 0; }
		int i,j,k;
		FOR(i,sAA[q]) {
			k = AA[q][i];
			j = 4*S[k] - 2*S[w&k] - 2*S3[k];
			if (FF[q][w] < j + F(q+1,k)) FF[q][w] = j + F(q+1,k);
		}
	}
	return FF[q][w];
}

int main() {
	int t,tt;
	FILE *fp = fopen("E-small.in","r");
	FILE *fp1 = fopen("E-small.out","w");
	fscanf(fp,"%d",&tt);
	FOR(t,tt) {
		int ans = 0;
		fscanf(fp,"%d%d",&m,&n);
		int i,j;
		FOR(i,20) FOR(j,20) C[i][j] = '.';
		FOR(i,m) FOR(j,n) {
			do {
				fscanf(fp,"%c",&C[i][j]);
			} while ((C[i][j] != '.') && (C[i][j] != '#') && (C[i][j] != '?'));
		}

		if (m < n) {
			FOR(i,n) SFOR(j,i+1,n) swap(C[i][j],C[j][i]);
			swap(n,m);
		}

		int k;

		FOR(j,m) sAA[j] = 0;

		FOR(j,m) FOR(k,(1<<n)) {
			V[j][k] = 1;
			FOR(i,n) if ((k & (1<<i)) != 0) {
				if (C[j][i] == '.') V[j][k] = 0;
			} else if (C[j][i] == '#') V[j][k] = 0;
			FOR(i,n-2) if (((k & (7<<i)) == (7<<i)) && (C[j][i+1] == '?')) V[j][k] = 0;
			if (V[j][k] == 1) { AA[j][sAA[j]] = k; sAA[j]++; }
		}

		FOR(k,(1<<n)) {
			S[k] = 0;
			FOR(i,n) if ((k & (1<<i)) != 0) S[k]++;
			S3[k] = 0;
			FOR(i,n-1) if ((k & (3<<i)) == (3<<i)) S3[k]++;
		}

		memset(FF,0xFF,sizeof(FF));

		ans = F(0,0);

		printf("Case #%d: %d\n", t+1, ans);
		fprintf(fp1,"Case #%d: %d\n", t+1, ans);
	}
	fclose(fp1);
	fclose(fp);
	return 0;
}