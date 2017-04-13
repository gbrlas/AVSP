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

const int INF = 1000000000;
const int MAXN = 55;

struct S
{
	int y, x, c, t;
	S( ) { y = x = c = t = 0; }
	S( int _y, int _x, int _c, int _t ) { y = _y; x = _x; c = _c; t = _t; }
};

bool operator<( const S &a, const S &b )
{
	if ( a.y != b.y )
		return a.y < b.y;
	if ( a.x != b.x )
		return a.x < b.x;
	if ( a.c != b.c )
		return a.c < b.c;
	return a.t < b.t;
}

int n, m;
int w, h;
int f;
char s[MAXN][MAXN];
int d[MAXN][MAXN][MAXN][2];
set<pair<int, S> > q;

bool in( const int &y, const int &x )
{
	return y >= 0 && x >= 0 && x < w && y < h;
}

void add( int y, int x, int c, int t, int nd )
{
	S a = S( y, x, c, t );
	if ( d[a.y][a.x][a.c][a.t] > nd )
	{
		q.erase( mp( d[a.y][a.x][a.c][a.t], a ) ); 
		d[a.y][a.x][a.c][a.t] = nd; 
		q.insert( mp( d[a.y][a.x][a.c][a.t], a ) ); 
	}
}

int main( )
{
	prepare( );
	int i, j, k;
	int t, tn;
	cin >> tn;
	fr( t, tn )
	{
		scanf( "%d %d %d", &h, &w, &f );
		fi( h )
		{
			scanf( "%s", s[i] );
		}
		_( d, 127 );
		q.clear( );
		add( 0, 0, 0, 0, 0 );
		while ( !q.empty( ) )
		{
			S c = q.begin( )->second;
			q.erase( q.begin( ) );
			//left right
			int cd = d[c.y][c.x][c.c][c.t];
			add( c.y, c.x, 0, 1 - c.t, cd );
			int dx = 0, dd;
			fr( dd, 2 )
			{
				if ( dd )
					dx = -1;
				else
					dx = 1;
				if ( in( c.y, c.x + dx ) && ( s[c.y][c.x + dx] == '.' || dd == c.t && c.c ) )
				{
					for ( i = c.y + 1; i < h; ++ i )
					{
						if ( s[i][c.x + dx] != '.' )
							break;
					}
					if ( i - c.y < f + 2 )
					{
						if ( i == c.y )
						{
							if ( dd == c.t )
							{
								add( i - 1, c.x + dx, max( 0, c.c - 1 ), dd, cd );
							}
							else
								add( i - 1, c.x + dx, 0, dd, cd );
						}
						else
						{
							add( i - 1, c.x + dx, 0, dd, cd );
						}
					}
				}
				k = 0;
				for ( j = 1; j < w; ++ j )
				{
					if ( in( c.y, c.x + j * dx ) && ( s[c.y][c.x + j * dx] == '.' || dd == c.t && j <= c.c ) )
					{
						if ( in( c.y + 1, c.x + j * dx ) && s[c.y + 1][c.x + j * dx] == '#' )
						{
							k = j;
							if ( in( c.y + 2, c.x + j * dx ) && s[c.y + 2][c.x + j * dx] == '.' )
							{
								if ( j > 1 )
									add( c.y + 1, c.x + dx, j - 1, dd, cd + j );
								break;
							}
							for ( i = 1; i <= j; ++ i )
							{
								add( c.y + 1, c.x + dx * i, j - i, dd, cd + j );
								add( c.y + 1, c.x + dx * i, i - 1, 1 - dd, cd + j );
							}
						}
						else
							break;
					}
					else
						break;
				}
				if ( in( c.y, c.x + dx ) && ( s[c.y][c.x + dx] == '.' || dd == c.t && c.c ) )
				{
					if ( in( c.y + 1, c.x + dx ) && s[c.y + 1][c.x + dx] == '#' )
					{
						for ( i = c.y + 2; i < h; ++ i )
						{
							if ( s[i][c.x + dx] != '.' )
								break;
						}
						if ( i - c.y < f + 2 )
						{
							add( i - 1, c.x + dx, 0, dd, cd + 1 );
						}
					}
				}
			}
		}
		int ans = INF;
		fi( w ) fj( w ) fk( 2 )
		{
			if ( d[h - 1][i][j][k] < INF )
				ans = min( ans, d[h - 1][i][j][k] );
		}
		printf( "Case #%d: ", t + 1 );
		if ( ans < INF )
			printf( "Yes %d\n", ans );
		else
			printf( "No\n" );
	}
	return 0;
}