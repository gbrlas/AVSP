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
#include <NTL/ZZ.h> // the NTL library can be downloaded at http://www.shoup.net/ntl/

NTL_CLIENT

using namespace std;

ZZ t[1005];

int main() {
	int cases;
	ZZ x;

	cin >> cases;
	for( int caseid = 1; caseid <= cases; ++caseid ) {
		int n;
		cin >> n;

		assert( n <= 1000 );
		for( int i = 0; i < n; ++i ) {
			cin >> t[i];
		}

		// sort and remove duplicates:
		sort( t, t+n );
		int m = 1;
		for( int i = 1; i < n; ++i ) {
			if( t[i] != t[m-1] ) {
				t[m++] = t[i];
			}
		}
		n = m;
		assert( n >= 2 );

		x = t[1]-t[0];
		for( int i = 2; i < n; ++i ) {
			x = GCD( x, t[i]-t[i-1] );
		}
		x = (x-(t[0]%x))%x;

		cout << "Case #" << caseid << ": " << x << endl;
	}
	return 0;
}
