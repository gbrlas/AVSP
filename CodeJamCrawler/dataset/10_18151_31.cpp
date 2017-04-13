#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
#include <string>
#include <deque>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <cmath>

using namespace std;

typedef long long LL;

int p;
int p2;
int maxmiss[5000];
LL cost[5000];
LL dp[1024][11];
const LL INF = (LL)1<<50;

LL rec( int index, int missed, int level ) {
	if( level == p ) {
		if( missed > maxmiss[index-(1<<(level))+1] ) return INF;
		return 0;
	}
	LL& res = dp[index][missed];
	if( res != -1 ) return res;
	res = INF;

	// miss it:
	res = min( res, rec( index*2+1, missed+1, level+1 ) + rec( index*2+2, missed+1, level+1 ) );
	// don't miss it:
	res = min( res, cost[index] + rec( index*2+1, missed, level+1 ) + rec( index*2+2, missed, level+1 ) );
	//cout << index << ' ' << missed << ' ' << level << ' ' << res << endl;
	//cout << cost[index] << endl;
	return res;
}

int main() {
	int cases;

	cin >> cases;
	for( int caseid = 1; caseid <= cases; ++caseid ) {
		cin >> p;
		p2 = 1<<p;
		for( int i = 0; i < p2; ++i ) {
			cin >> maxmiss[i];
		}

		//
		for( int a = 0, b = p2-1; a < b; ++a, --b ) {
			swap( maxmiss[a], maxmiss[b] );
		}

		for( int i = p2-2; i >= 0; --i ) {
			cin >> cost[i];
		}
		memset( dp, -1, sizeof(dp) );

		cout << "Case #" << caseid << ": " << rec( 0, 0, 0 ) << endl;
	}
	return 0;
}
