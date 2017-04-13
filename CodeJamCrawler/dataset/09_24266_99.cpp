#pragma comment( linker, "/stack:128000000" )
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>

void prepare( )
{
	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
}

#include <cmath>
#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <sstream>
#include <iostream>
#include <deque>

using namespace std;

#define fo(a,b,c) for(a =(b);a<(c);++a)
#define fr(a,b) fo(a,0,(b))
#define fi(a) fr(i,(a))
#define fj(a) fr(j,(a))
#define fk(a) fr(k,(a))
#define all(a) (a).begin(),(a).end()
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a).size()
#define _(a,b) memset((a),(b),sizeof(a))
#define __(a) _((a),0)

typedef long long lint;

const string w = "welcome to code jam";
const int MOD = 10000;
const int MAXN = 505;

int n, m;
int d[MAXN][25];

int solve( const string &s )
{
	__( d );
	d[0][0] = 1;
	int i, j;
	int n = sz( s );
	int m = sz( w );
	fi( n ) fj( m + 1 )
	{
		if ( j < m && s[i] == w[j] )
			d[i + 1][j + 1] = ( d[i + 1][j + 1] + d[i][j] ) % MOD;
		d[i + 1][j] = ( d[i + 1][j] + d[i][j] ) % MOD;
	}
	return d[n][m];
}

int main( )
{
	prepare( );
	int i, j, k;
	int t, tn;
	{
		string s;
		getline( cin, s );
		stringstream ss( s );
		ss >> tn;
	}
	fr( t, tn )
	{
		string s;
		getline( cin, s );
		printf( "Case #%d: %04d\n", t + 1, solve( s ) );
	}
	return 0;
}