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

const int MAXN = 45;

int n, m;
string s[MAXN];
int pos[MAXN];

int main( )
{
	prepare( );
	int i, j, k;
	int t, tn;
	cin >> tn;
	fr( t, tn )
	{
		scanf( "%d", &n );
		fi( n )
		{
			cin >> s[i];
		}
		fi( n )
		{
			for( j = n - 1; j > 0; -- j )
			{
				if ( s[i][j] == '1' )
					break;
			}
			pos[i] = j;
		}
		int ans = 0;
		fi( n )
		{
			if ( pos[i] > i )
			{
				for ( j = i + 1; j < n; ++ j )
				{
					if ( pos[j] <= i )
						break;
				}
				assert( j < n );
				k = j;
				for ( j = k; j > i; -- j )
				{
					swap( pos[j], pos[j - 1] );
					++ ans;
				}
			}
		}
		printf( "Case #%d: %d\n", t + 1, ans );
	}
	return 0;
}