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

int n, m, L;
vector <string> w;
char p[30][30];

int solve( string s )
{
	__( p );
	int i, j, id = 0;
	for ( i = 0; i < L; ++ i )
	{
		if ( s[id] == '(' )
		{
			++ id;
			while ( s[id] != ')' )
			{
				p[i][s[id] - 'a'] = 1;
				++ id;
			}
		}
		else
		{
			p[i][s[id] - 'a'] = 1;
		}
		++ id;
	}
	int ans = 0;
	fi( n )
	{
		fj( L )
		{
			if ( !p[j][w[i][j] - 'a'] )
				break;
		}
		if ( j == L )
			++ ans;
	}
	return ans;
}

int main( )
{
	prepare( );
	int i, j, k;
	int t, tn;
	string s;
	cin >> L >> n >> tn;
	fi( n )
	{
		cin >> s;
		w.pb( s );
	}
	fr( t, tn )
	{
		cin >> s;
		printf( "Case #%d: %d\n", t + 1, solve( s ) );
	}
	return 0;
}