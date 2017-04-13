#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct gezi
{
	char r;
	int p;
};

int main()
{
	
	//freopen ( "in.txt", "r", stdin );
    //freopen ( "out.txt", "w", stdout );
	
	freopen ( "A-large.in", "r", stdin );
    freopen ( "A-large.out", "w", stdout );
	int T;
	scanf ( "%d", &T );
	for ( int t = 1; t <= T; t++ )
	{
		
		int n;
		scanf ( "%d", &n );
		gezi a[105];
		for ( int i = 0; i < n; i++ )
		{
			scanf ( "%s%d", &a[i].r, &a[i].p );
		}
		int ans = 0, tm = 0;
		int dist[999];
		dist['O'] = 1;
		dist['B'] = 1;
		for ( int i = 0; i < n; i++ )
		{
			if ( i == 0)
			{
				ans = a[i].p - dist[a[i].r] + 1;
				tm = a[i].p - dist[a[i].r] + 1;
				dist[a[i].r] = a[i].p;
				continue;
			}
			int oo = abs ( a[i].p - dist[a[i].r] );
			if ( a[i].r == a[i - 1].r )
			{
				ans += oo + 1;
				tm += oo + 1;
			}
			else
			{
				if ( tm >= oo )
				{
					tm = 1;
					ans++;
				}
				else
				{
					ans += oo - tm + 1;
					tm = oo - tm + 1;
				}
			}
			dist[a[i].r] = a[i].p;
		}
		printf ( "Case #%d: %d\n", t, ans );
	}
	return 0;
}
