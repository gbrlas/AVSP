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

typedef pair<LL,LL> P;

int main() {
	int cases;
	cin >> cases;
	for( int caseid = 1; caseid <= cases; ++caseid ) {
		cout << "Case #" << caseid << ": ";
		int X, S, R, N;
		double t;
		cin >> X >> S >> R >> t >> N;
		int last = 0;
		vector<P> v;
		for( int i = 1; i <= N; ++i ) {
			int B, E, w;
			cin >> B >> E >> w;
			if( last < B ) {
				v.push_back( P( S, B-last ) );
			}
			v.push_back( P( S+w, E-B ) );
			last = E;
		}
		if( last < X ) {
			v.push_back( P( S, X-last ) );
		}
		sort( v.begin(), v.end() );
		double time_sum = 0.0;
		for( int i = 0; i < (int)v.size(); ++i ) {
			double s = min( t*(v[i].first-S+R), (double)v[i].second );
			double t2 = s/(double)(v[i].first-S+R);
			t -= t2;
			time_sum += t2;
			time_sum += (double)(v[i].second-s)/(double)v[i].first;
		}
		printf( "%.20f\n", time_sum );
	}
	return 0;
}
