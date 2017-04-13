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
		double C,F,X;
		bool first = true;
		// no farm
		cin >> C >> F >> X;
		double lastFarmTime = 0;
		double speed = 2.0;
		double totalTime = lastFarmTime + (X / speed);
		double lastTime = 0;;
		do {
			// printf("%.2lf, %.2lf, %.2lf", totalTime,
			lastTime = totalTime;
			lastFarmTime += C / speed;
			speed += F;
			totalTime = lastFarmTime + (X/speed);
		} while (lastTime > totalTime);
		printf("Case #%d: %.7lf\n", t, lastTime);
	}
	return 0;
}
