#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
	
	freopen ( "C-small-attempt0.in", "r", stdin );
    freopen ( "C-small-attempt0.out", "w", stdout );

	int T;
	scanf ( "%d", &T );
	for ( int t = 1; t <= T; t++ )
	{
		int n;
		scanf ( "%d", &n );
		int a[20];
		for ( int i = 0; i < n; i++ )
			scanf ( "%d", &a[i] );
		int N = 1 << n;
		int ans = 0;
		for ( int i = 1; i < N - 1; i++ )
		{
			int sum1 = 0, sum2 = 0;
			int ans1 = 0, ans2 = 0;
			int j = i, m = N / 2, tm = 0;
			while ( tm < n )
			{
				if ( 0 == j / m ) 
				{
					sum1 ^= a[tm];
					ans1 += a[tm];
				}
				else
				{
					sum2 ^= a[tm];
					ans2 += a[tm];
				}
				j = j % m;
				m /= 2;
				tm++;
			}
			if ( sum1 == sum2 )
			{
				if ( ans < ans1 ) ans = ans1;
				if ( ans < ans2 ) ans = ans2;
			}
		}
		if ( ans != 0)
			printf ( "Case #%d: %d\n", t, ans );
		else printf ( "Case #%d: NO\n", t );
	}
	return 0;
}