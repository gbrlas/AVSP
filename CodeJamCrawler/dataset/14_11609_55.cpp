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
	int TC;
	cin >> TC;
	int tmp;
	for (int t=1; t<=TC; t++) {
		int row;
		cin >> row;
		int first[4];
		for (int i=0; i<4; i++) {
			for (int j=0; j<4; j++) {
				if (i==row-1) {
					cin >> first[j];
				} else {
					cin >> tmp;
				}
			}
		}
		int second[4];
		cin >> row;
		for (int i=0; i<4; i++) {
			for (int j=0; j<4; j++) {
				if (i==row-1) {
					cin >> second[j];
				}else {
					cin >> tmp;
				}
			}
		}
		// for (int i=0; i<4; i++) {
			// cout << first[i] << " " << second[i] << endl;
		// }
		sort(first, first+4);
		sort(second, second+4);
		vector<int> v(10);
		vector<int>::iterator it = set_intersection(first, first+4, second, second+4, v.begin());
		if (it - v.begin() == 1) {
			printf("Case #%d: %d\n", t, v[0]);
		} else if (it - v.begin() > 1){
			printf("Case #%d: Bad magician!\n", t);
		} else {
			printf("Case #%d: Volunteer cheated!\n", t);
		}
	}
	return 0;
}
