#include <stdio.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <utility>

using namespace std;

#define FOR(i,n) SFOR(i,0,n)
#define SFOR(i,m,n) for(i=m;i<n;i++)
#define FORD(i,n) for(i=n-1;i>=0;i--)
#define sz size()
#define pb push_back
#define mp make_pair
#define ss stringstream

int A[2][20];
string s = "welcome to code jam";

int main() {
	FILE* fp = fopen("C.in", "r");
	FILE* fout = fopen("C.out", "w");
	int t,tt;
	fscanf(fp, "%d\n", &tt);
	int m,n,i,j,k;
	char buf[1000];
	FOR(t,tt) {
		fgets(buf, 1000, fp);
		memset(A,0,sizeof(A));
		A[0][0] = 1;
		k = 0;
		n = strlen(buf);
		FOR(i,n) {
			k = 1-k;
			FOR(j,s.sz+1) A[k][j] = A[1-k][j];
			FOR(j,s.sz) if (s[j] == buf[i]) A[k][j+1] = (A[k][j+1] + A[1-k][j]) % 10000;
		}
		fprintf(fout, "Case #%d: ", t+1);
		if (A[k][s.sz] < 1000) fprintf(fout, "0");
		if (A[k][s.sz] < 100) fprintf(fout, "0");
		if (A[k][s.sz] < 10) fprintf(fout, "0");
		fprintf(fout, "%d\n",A[k][s.sz]);
	}
	fclose(fout);
	fclose(fp);
	return 0;
}