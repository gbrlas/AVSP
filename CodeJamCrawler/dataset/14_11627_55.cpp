#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;
#define debug 0
#define DEBUG(x) if (debug) {x;}
#define DEBUGTAB(tab,x) if (debug) {printf("%2c",' '); x;}

#define eps 10e-9
#define construct2d_array(R,C) new int* [R]; \
	for (int _i = 0; _i < R; _i++) \
		data[_i] = new int[C];
#define FOR(A, N) for(int A = 0; A < N; A++)
#define FORX(A, X, N) for(int A = X; A < N; A++)
#define FORN(A, N) for(int A = 1; A <= N; A++)
#define FORXN(A,X,N) for(int A = X; A <= N; A++)
#define RESET(D,R,C,V) FOR(_i,R) FOR(_j,C) D[_i][_j] = V
#define TREE_SIZE(N) ((int) (2*pow(2.0, floor((log((double) N) / log (2.0) ) + 1))))

typedef pair<int,int> pii;

int main() {
	int tc;
	cin >> tc;
	for (int t=1; t<=tc; t++) {
		int n;
		cin >> n;
		vector<double> p1(n), p2(n);
		for (int i=0; i<n; i++) {
			cin >> p1[i];
		}
		for (int i=0; i<n; i++) {
			cin >> p2[i];
		}
		sort(p1.begin(), p1.end());
		sort(p2.begin(), p2.end());
		int deceit = 0;
		int jf=0;
		for (int i=0; (i<n) && (jf<n); i++) {
			if (p1[i] > p2[jf]) {
				jf++;
				deceit++;
			}
		}
		int war = 0;
		jf = 0;
		for (int i=0; (i<n) && (jf<n); i++) {
			if (p2[i] > p1[jf]) {
				jf++;
				war++;
			}
		}
		war = n-war;
		printf ("Case #%d: %d %d\n", t, deceit, war);
	}
	return 0;
}
