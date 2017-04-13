#pragma comment( linker, "/stack:256000000" )
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <cmath>
#include <cassert>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <ctime>
#include <sstream>
#include <iostream>
#include <deque>
#include <complex>

using namespace std;

void prepare( )
{
	freopen( "input.txt", "r", stdin );
//#ifndef _DEBUG
	freopen( "output.txt", "w", stdout );
//#endif
}

#define fo(a,b,c) for( a = (b); a < (c); ++ a )
#define fr(a,b) fo(a,0,(b))
#define fi(n) fr(i,(n))
#define fj(n) fr(j,(n))
#define fk(n) fr(k,(n))
#define mp make_pair
#define pb push_back
#define all(a) (a).begin( ), (a).end( )
#define _(a, b) memset( (a), (b), sizeof( a ) )
#define __(a) memset( (a), 0, sizeof( a ) )
#define sz(a) (int)(a).size( )

typedef long long lint;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair <int, int> PII;

const int MAXN = 105;
const int MAXK = 5;
const int MAXD = 11;
const int MOD = 10009;

int n, m, n2;
vector<string> f;
vector<VI > cnt;
int d[MAXD][1 << MAXK];
int sd[MAXD];

int main( )
{
	prepare( );
	int i, j, k;
	int t, tn;
	cin >> tn;
	for ( t = 1; t <= tn; ++ t )
	{
		printf( "Case #%d:", t );
		string s;
		cin >> s >> m;
		fi( sz( s ) )
			if ( s[i] == '+' )
				s[i] = ' ';
		f.clear( );
		stringstream ss( s );
		while ( ss >> s )
			f.pb( s );
		scanf( "%d", &n );
		cnt = vector<VI>( n, VI( 26, 0 ) );
		fi( n )
		{
			cin >> s;
			fj( sz( s ) )
			{
				++ cnt[i][s[j] - 'a'];
			}
		}
		__( sd );
		int ms, nn, mm, wher;
		fi( sz( f ) )
		{
			_( d, -1 );
			nn = sz( f[i] );
			n2 = 1 << sz( f[i] );
			fj( n2 )
				d[0][j] = 0;
			d[0][0] = 1;
			fk( m + 1 )
			{
				fj( n )
				{
					fr( wher, n2 )
					{
						if ( d[k][wher] < 0 )
							continue;
						if ( k < m )
						{
							for( ms = wher; ;ms = ( ms - 1 ) & wher )
							{
								int res = 1;
								int nm = wher ^ ms;
								fr( mm, nn )
								{
									if ( nm & ( 1 << mm ) )
									{
										res *= cnt[j][f[i][mm] - 'a'];
									}
								}
								res %= MOD;
								( res *= d[k][ms] ) %= MOD;
								if ( d[k + 1][wher] < 0 )
									d[k + 1][wher] = 0;
								( d[k + 1][wher] += res ) %= MOD;
								if ( ms == 0 )
									break;
							}
						}
					}
				}
			}
			fj( m + 1 )
			{
				if ( d[j][n2 - 1] >= 0 )
					( sd[j] += d[j][n2 - 1] ) %= MOD;
			}
		}
		fi( m )
		{
			printf( " %d", sd[i + 1] );
		}
		printf( "\n" );
	}
	return 0;
}