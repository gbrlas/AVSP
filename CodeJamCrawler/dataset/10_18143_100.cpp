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
const LL MOD = 100003;
LL bin[505][505];
LL mem[505][505];

LL calc( int n, int l ) {
	if( l == 1 ) return 1;
	LL& res = mem[n][l];
	if( res != -1 ) return res;
	res = 0;
	for( int i = 0; i < n-l && l-1-i >= 1; ++i ) {
		res = (res + calc( l, l-1-i ) * bin[n-l-1][i])%MOD;
	}
	return res;
}

int main() {
	int cases;

	memset( mem, -1, sizeof(mem) );
	for( int i = 0; i < 505; ++i ) {
		bin[i][i] = bin[i][0] = 1;
		for( int j = 1; j < i; ++j ) {
			bin[i][j] = (bin[i-1][j-1]+bin[i-1][j])%MOD;
		}
	}

	cin >> cases;
	for( int caseid = 1; caseid <= cases; ++caseid ) {
		int n;
		cin >> n;
		LL sum = 0;
		for( int i = 1; i < n; ++i ) {
			sum = (sum + calc( n, i))%MOD;
		}
		cout << "Case #" << caseid << ": " << sum << endl;
	}
	return 0;
}
