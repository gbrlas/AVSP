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
#define FILL(a,v)   memset(a,v,sizeof(a))
#define FOR(i,a,b)  for(int i=(a); i<=(b); ++i)
#define REP(i,n)    for(int i=0; i<(n); ++i)
/* Prewritten code ends */

const int maxG = 10;
int best[3*maxG+1][2];
inline void updateMax(int sum, int surprising, int mx) {
	if(best[sum][surprising] < mx)
		best[sum][surprising] = mx;
}
int main() {
	FILL(best, 0xFF);
	FOR(i,0,maxG) FOR(j,i,min(maxG,i+2)) FOR(k,j,min(maxG,i+2))
		updateMax(i+j+k, k-i==2, k);

	FOR(i,2,28) assert(best[i][1] >= best[i][0]);

	int T, N, S, p, res, total;
	cin >> T;
	FOR(cs,1,T) {
		cin >> N >> S >> p;

		res = 0;
		REP(i,N) {
			cin >> total;
			if(best[total][0] >= p) res++;
			else if(best[total][1] >= p && S) S--, res++;
		}
		cout << "Case #" << cs << ": " << res << endl;
	}

	return 0;
}
