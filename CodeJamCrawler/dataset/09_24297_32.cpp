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

const int MAXN = 105;

int n, m;
int in[MAXN];
int out[MAXN];
vector<int> a[MAXN];
int b[MAXN][MAXN];
int len[MAXN];
int ans;

bool more( const vector<int> &a, const vector<int> &b )
{
	int i;
	fi( m )
	{
		if ( a[i] <= b[i] )
			return false;
	}
	return true;
}

int main( )
{
	prepare( );
	int i, j, k;
	int t, tn;
	cin >> tn;
	fr( t, tn )
	{
		scanf( "%d %d", &n, &m );
		fi( n ) a[i].clear( );
		fi( n ) fj( m )
		{
			scanf( "%d", &k );
			a[i].pb( k );
		}
		__( b );
		fi( n ) fj( n )
		{
			if ( more( a[i], a[j] ) )
				b[i][j] = 1;
		}
		ans = 0;
		__( in );
		__( out );
		while ( 1 )
		{
			bool ok = true;
			int id = -1;
			int idv = 0;
			fi( n )
			{
				if ( !in[i] )
				{
					int c = 0;
					ok = false;
					for ( j = 0; j < n; ++ j )
						if ( b[j][i] && !out[j] )
							++ c;
					if ( id < 0 || idv > c )
					{
						id = i;
						idv = c;
					}
				}
			}
			if ( ok )
				break;
			in[id] = 1;
			for ( i = 0; i < n; ++ i )
				if ( b[i][id] && !out[i] )
					break;
			if ( i < n )
			{
				out[i] = 1;
			}
			else
				++ ans;
		}
		printf( "Case #%d: %d\n", t + 1, ans );
	}
	return 0;
}