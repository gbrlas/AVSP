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
	int cases;
	scanf( "%d", &cases );
	for( int caseid = 1; caseid <= cases; ++caseid ) {
		printf( "Case #%d: ", caseid );
		int n;
		scanf( "%d", &n );
		int wrong = 0;
		for( int i = 0; i < n; ++i ) {
			int a;
			scanf( "%d", &a );
			if( a != i+1 ) ++wrong;
		}
		printf( "%d\n", wrong );
	}
	return 0;
}
