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
#ifndef _DEBUG
	freopen( "output.txt", "w", stdout );
#endif
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

const int MAXN = 13;
const int INF = 1000000000;

int n, m;
int cn;
char s[MAXN][MAXN];
char f[MAXN][MAXN];
typedef unsigned char uchar;

const int dx[] = { 1, 0, -1, 0, -1, -1, 1, 1, 0 };
const int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1, 0 };

struct C
{
	uchar c[5];
};

bool operator<( const C &a, const C &b )
{
	int i;
	fi( cn )
	{
		if ( a.c[i] != b.c[i] )
			return a.c[i] < b.c[i];
	}
	return false;
}

int w, h;
map<C, int> ids;
vector<C> sts;
vector<int> d;
deque<int> q;

int getId( const C &a )
{
	if ( ids.find( a ) != ids.end( ) )
		return ids[a];
	ids[a] = sz( d );
	sts.pb( a ); 
	d.pb( INF );
	return sz( d ) - 1;
}

void add( const int &id, int nd )
{
	if ( d[id] > nd )
	{
		d[id] = nd;
		q.pb( id );
	}
}

bool dang( const C &a )
{
	int i, j;
	if ( cn == 1 )
		return false;
	fi( cn )
	{
		int md = 100;
		fj( cn ) if ( j != i )
		{
			int d = abs( ( a.c[j] & 15 ) - ( a.c[i] & 15 ) ) +
				abs( ( a.c[j] >> 4 ) - ( a.c[i] >> 4 ) );
			md = min( d, md );
		}
		if ( md > 2 )
			return true;
	}
	return false;
}

int main( )
{
	prepare( );
	int i, j, k;
	int t, tn;
	cin >> tn;
	for ( t = 1; t <= tn; ++ t )
	{
		printf( "Case #%d: ", t );
		scanf( "%d %d", &h, &w );
		cn = 0;
		C st, en;
		sts.clear( );
		ids.clear( );
		d.clear( );
		int ec =0 ;
		q.clear( );
		fi( h )
		{
			scanf( "%s", s[i] );
			fj( w )
			{
				if ( s[i][j] == 'o' )
				{
					s[i][j] = '.';
					st.c[cn] = ( i << 4 ) | j;
					++ cn;
				}
				else
				if ( s[i][j] == 'w' )
				{
					s[i][j] = 'x';
					st.c[cn] = ( i << 4 ) | j;
					++ cn;
				}
				if ( s[i][j] == 'x' )
				{
					s[i][j] = '.';
					en.c[ec] = ( i << 4 ) | j;
					++ ec;
				}
			}
		}
		add( getId( st ), 0 );
		int id;
		bool ok = false;
		int eid = getId( en );
		while ( !q.empty( ) )
		{
			id = q.front( );
			q.pop_front( );
			if ( id == eid )
			{
				ok = true;
				break;
			}
			bool lastdang = false;
			if ( dang( sts[id] ) )
				lastdang = true;
			fi( cn )
			{
				fj( 4 )
				{
					int cx = ( sts[id].c[i] & 15 ) + dx[j];
					int cy = ( sts[id].c[i] >> 4 ) + dy[j];
					int ccx = ( sts[id].c[i] & 15 ) - dx[j];
					int ccy = ( sts[id].c[i] >> 4 ) - dy[j];
					if ( cx < 0 || cy < 0 || cx >= w || cy >= h ||
						s[cy][cx] != '.' )
						continue;
					if ( ccx < 0 || ccy < 0 || ccx >= w || ccy >= h ||
						s[ccy][ccx] != '.' )
						continue;
					fk( cn ) if ( k != i )
					{
						int d = abs( ccx - ( sts[id].c[k] & 15 ) ) +
							abs( ccy - ( sts[id].c[k] >> 4 ) );
						if ( d == 0 )
							break;
					}
					if ( k < cn )
						continue;
					bool curdang = false;
					int md = 3;
					fk( cn ) if ( k != i )
					{
						int d = abs( cx - ( sts[id].c[k] & 15 ) ) +
							abs( cy - ( sts[id].c[k] >> 4 ) );
						md = min( d, md );
					}
					if ( cn > 1 )
					{
						if ( md == 0 || md > 2 )
							continue;
					}
					if ( k == cn )
					{
						C cur = sts[id];
						char pp = ( cy << 4 ) | cx;
						fo( k, i, cn - 1 )
						{
							cur.c[k] = cur.c[k + 1];
						}
						cur.c[cn - 1] = pp;
						k = cn - 1;
						while ( k - 1 >= 0 && cur.c[k - 1] > cur.c[k] )
						{
							swap( cur.c[k - 1], cur.c[k] );
							-- k;
						}
						if ( lastdang && dang( cur ) )
							continue;
						add( getId( cur ), d[id] + 1 );
					}
				}
			}
		}
		if ( ok )
			printf( "%d\n", d[id] );
		else
			printf( "-1\n" );
	}
	return 0;
}