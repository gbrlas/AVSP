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

vector<int> X, Y;
int A[200][200], V[200][200];
char ans[200][200];

pair<int, int> D(int q, int w) {
	if (A[q][w] == 1000000000) return mp(q,w);
	int e = min(min(A[q-1][w], A[q][w-1]), min(A[q+1][w], A[q][w+1]));
	if (e >= A[q][w]) return mp(q,w);
	if (A[q-1][w] == e) return mp(q-1,w);
	if (A[q][w-1] == e) return mp(q,w-1);
	if (A[q][w+1] == e) return mp(q,w+1);
	if (A[q+1][w] == e) return mp(q+1,w);
}

int main() {
	FILE* fp = fopen("B.in", "r");
	FILE* fout = fopen("B.out", "w");
	int t,tt;
	fscanf(fp, "%d", &tt);
	int m,n,i,j,k;
	pair<int,int> q;
	FOR(t,tt) {
		char z = 'a';
		fscanf(fp, "%d%d", &m, &n);
		FOR(i,m+2) FOR(j,n+2) A[i][j] = 1000000000;
		memset(V,0,sizeof(V));
		FOR(i,m) FOR(j,n) fscanf(fp,"%d",&A[i+1][j+1]);
		SFOR(i,1,m+1) SFOR(j,1,n+1) if (V[i][j] == 0) {
			X.clear();
			Y.clear();
			X.pb(i); Y.pb(j);
			V[i][j] = 1;
			FOR(k,X.sz) {
				q = D(X[k],Y[k]);
				if (V[q.first][q.second] == 0) { X.pb(q.first); Y.pb(q.second); V[X[X.sz-1]][Y[X.sz-1]] = 1; }
				q = mp(X[k],Y[k]);
				if (D(X[k]-1,Y[k]) == q) { X.pb(X[k]-1); Y.pb(Y[k]); V[X[X.sz-1]][Y[X.sz-1]] = 1; }
				if (D(X[k]+1,Y[k]) == q) { X.pb(X[k]+1); Y.pb(Y[k]); V[X[X.sz-1]][Y[X.sz-1]] = 1; }
				if (D(X[k],Y[k]-1) == q) { X.pb(X[k]); Y.pb(Y[k]-1); V[X[X.sz-1]][Y[X.sz-1]] = 1; }
				if (D(X[k],Y[k]+1) == q) { X.pb(X[k]); Y.pb(Y[k]+1); V[X[X.sz-1]][Y[X.sz-1]] = 1; }
			}
			FOR(k,X.sz) ans[X[k]-1][Y[k]-1] = z;
			z++;
		}
		fprintf(fout, "Case #%d:\n", t+1);
		FOR(i,m) { FOR(j,n) fprintf(fout, "%c ", ans[i][j]); fprintf(fout, "\n"); }
	}
	fclose(fout);
	fclose(fp);
	return 0;
}