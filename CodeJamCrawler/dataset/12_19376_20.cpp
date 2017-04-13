#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;


/* Prewritten code begins */
#define LL          long long
#define REP(i,n)    for(int i=0; i<(n); ++i)
/* Prewritten code ends */

const int maxN = 10;
int r[maxN];
LL SQ[maxN][maxN];
double x[maxN], y[maxN];
inline double rnd(int LIM) {
	return 1.*rand()/RAND_MAX*LIM;
}
inline double sq(double x) {
	return x*x;
}
inline double dist(int a, int b) {
	double t1 = sq(x[a]-x[b]);
	double t2 = sq(y[a]-y[b]);
	return t1+t2 <= SQ[a][b];
}
int main() {
	srand(unsigned(time(NULL)));
	int T, N, W, L;
	cin >> T;
	REP(cs,T) {
		cin >> N >> W >> L;
		REP(i,N) cin >> r[i];
		REP(i,N) REP(j,N) SQ[i][j] = (LL)(r[i]+r[j])*(r[i]+r[j]);
		while(1) {
			int flag = 1;
			REP(i,N) {
				x[i]=rnd(W), y[i] = rnd(L);
				REP(j,i) if(dist(i,j)) {
					flag = 0;
					break;
				}
				if(!flag) break;
			}
			if(flag) break;
		}
		printf("Case #%d:", cs+1);
		REP(i,N) printf(" %.7lf %.7lf", x[i], y[i]);
		printf("\n");
	}
	return 0;
}
