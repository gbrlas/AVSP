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

char A[10000][20];
bool B[20][300];

int main() {
	FILE* fp = fopen("A.in", "r");
	FILE* fout = fopen("A.out", "w");
	int i,j,k,L,D,N,t;
	char buf[1000];
	fscanf(fp, "%d%d%d", &L, &D, &N);
	FOR(i,D) { fscanf(fp, "%s", buf); FOR(j,L) A[i][j] = buf[j]; }
	FOR(t,N) {
		fscanf(fp,"%s",buf);
		j = 0;
		k = 0;
		memset(B,0,sizeof(B));
		while (k != L) {
			if (buf[j] == '(') {
				j++;
				while (buf[j] != ')') {
					B[k][buf[j]] = true;
					j++;
				}
			} else {
				B[k][buf[j]] = true;
			}
			k++;
			j++;
		}
		k = 0;
		FOR(i,D) {
			FOR(j,L) if (!B[j][A[i][j]]) break;
			if (j == L) k++;
		}
		fprintf(fout, "Case #%d: %d\n",t+1,k);
	}
	fclose(fout);
	fclose(fp);
	return 0;
}