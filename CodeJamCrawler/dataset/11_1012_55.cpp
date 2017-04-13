#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define FOR(i,a,b) for(int i=a,_b=b;i<=_b;i++)
#define REP(i,a) FOR(i,0,a-1)
#define FORD(i,a,b) for(int i=a,_b=b;i>=b;i--)
#define REPD(i,a) FORD(i,a-1,0)
#define ALL(x) (x).begin(),(x).end()
#define _m(a,b) memset(a,b,sizeof(a))
#define LL long long
#define st first
#define nd second

typedef pair<int,int> PII;
typedef pair<int,string> PIS;

#define MAX 102

char M[MAX][MAX];

int isWin(int i, int j) {
	return (M[i][j] != '.' ? M[i][j]-'0' : 0);
}

void run(int testcaseNumber) {
	int N; scanf("%d", &N);
	int W[MAX];  _m(W, 0);
	int NP[MAX]; _m(NP, 0);
	double WP[MAX];
	double OWP[MAX], owp, nowp;
	double OOWP[MAX], oowp, noowp;
	double RPI[MAX];

	REP(i, N) scanf("%s", &M[i]);
	REP(i, N) REP(j, N) W[i] += isWin(i,j);
	REP(i, N) REP(j, N) NP[i] += (M[i][j] != '.');

	REP(i, N) WP[i] = (double)W[i] / NP[i];

	REP(i, N) {
		owp = 0.0; nowp = 0;
		REP(j, N)
			if(M[i][j] != '.') {
				owp += (double)(W[j]-isWin(j,i)) / (NP[j]-1);
				nowp++;
			}

		OWP[i] = owp / nowp;
	}
	
	REP(i, N) {
		oowp = 0.0; noowp = 0;
		REP(j, N)
			if(M[i][j] != '.') {
				oowp += OWP[j];
				noowp++;
			}

		OOWP[i] = oowp / noowp;
	}
	
	REP(i, N) RPI[i] = 0.25 * WP[i] + 0.50 * OWP[i] + 0.25 * OOWP[i];
	
	/*
	REP(i, N) printf("%c:%lf ", 'a'+i, WP[i]); puts("");
	REP(i, N) printf("%c:%lf ", 'a'+i, OWP[i]); puts("");
	REP(i, N) printf("%c:%lf ", 'a'+i, OOWP[i]); puts("");
	*/

	printf("Case #%d:\n", testcaseNumber);
	REP(i, N) printf("%.12lf\n", RPI[i]);
}

int main(void) {
	int T; scanf("%d", &T); REP(i, T) run(i + 1);
	return 0;
}
