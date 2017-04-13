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

int main() {
	int a[1000];
	int b[1000];
	double f[1001];
	double D[1001];
	double x[1001];

	f[0] = 1.0;
	D[0] = 1.0;
	for( int i = 1; i <= 1000; ++i ) {
		f[i] = f[i-1] * i;
		if(i&1) D[i] = D[i-1] - 1.0/f[i]; else D[i] = D[i-1] + 1.0/f[i];
	}

	int cases;
	scanf( "%d", &cases );
	for( int caseid = 1; caseid <= cases; ++caseid ) {
		printf( "Case #%d: ", caseid );
		int n;
		scanf( "%d", &n );
		for( int i = 0; i < n; ++i ) {
			scanf( "%d", &a[i] );
			b[i] = a[i];
		}
		sort( b, b+n );
		int wrong = 0;
		for( int i = 0; i < n; ++i ) {
			if( a[i] != b[i] ) ++wrong;
		}

		x[0] = x[1] = 0.0;
		for( int i = 2; i <= wrong; ++i ) {
			x[i] = 1.0;
			for( int k = 1; k <= i; ++k ) {
				x[i] += D[i-k]/f[k] * x[i-k];
			}
			x[i] /= (1.0-D[i]);
		}
		printf( "%.20f\n", x[wrong] );
	}
	return 0;
}
