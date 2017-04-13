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

const int dx[] = { 0, -1, 1, 0 };
const int dy[] = { -1, 0, 0, 1 };

const int MAXN = 105;

int n, m;
int h, w;
int a[MAXN][MAXN];
int c[MAXN][MAXN];
char let[MAXN];
int letn;
int cn;

void clear( )
{
	_( c, -1 );
	__( let );
	letn = 0;
	cn = 0;
}

bool in( const int &y, const int &x )
{
	return ( y >= 0 && x >= 0 && y < h && x < w ); 
}

int go( const int &y, const int &x )
{
	if ( c[y][x] >= 0 )
		return c[y][x];
	int i;
	int hh = 100005;
	int id = -1;
	fi( 4 )
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if ( !in( ny, nx ) )
			continue;
		if ( a[y][x] > a[ny][nx] )
		{
			if ( hh > a[ny][nx] )
			{
				hh = a[ny][nx];
				id = i;
			}
		}
	}
	if ( id < 0 )
		return c[y][x] = cn++;
	int ny = y + dy[id];
	int nx = x + dx[id];
	return c[y][x] = go( ny, nx );
}

int main( )
{
	prepare( );
	int i, j, k;
	int t, tn;
	cin >> tn;	
	fr( t, tn )
	{
		clear( );
		printf( "Case #%d:\n", t + 1 );
		scanf( "%d %d", &h, &w );
		fi( h ) fj( w )
		{
			scanf( "%d", &a[i][j] );
		}
		fi( h ) fj( w )
		{
			if ( c[i][j] < 0 )
				go( i, j );
		}
		assert( cn <= 26 );
		fi( h )
		{
			fj( w )
			{
				if ( j )
					printf( " " );
				if ( !let[c[i][j]] )
				{
					let[c[i][j]] = 'a' + letn++;
				}
				printf( "%c", let[c[i][j]] );
			}
			printf( "\n" );
		}
	}
	return 0;
}