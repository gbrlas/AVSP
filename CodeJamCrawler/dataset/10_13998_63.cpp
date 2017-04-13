#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int a[110];
int dp[110][300];

main(){
	freopen( "Bs.in", "r", stdin );
	freopen( "Bs.out", "w", stdout );
	
	int D, I, n, m, i, j, k, t, tt = 0;
	int minimum;
	
	scanf ( "%d", &t );
	while( t -- ){
		scanf ( "%d %d %d %d", &D, &I, &m, &n );
		for ( i = 0; i < n; i ++ )
			scanf ( "%d", a + i );
		memset ( dp, -1, sizeof ( dp ) );
		dp[0][256] = 0;
		for ( i = 0; i < n; i ++ ){
			dp[ i + 1 ][256] = dp[i][256] + D;
			for ( j = 0; j < 256; j ++ )
				dp[ i + 1 ][j] = dp[i][256] + abs( a[i] - j );
			if ( i == 0 )
				continue;
			for ( j = 0; j < 256; j ++ ){
				if ( dp[i][j] == -1 )
					while( true );
				dp[ i + 1 ][j] = min( dp[ i + 1 ][j], dp[i][j] + D );
				for ( k = 0; k < 256; k ++ )
					if ( m == 0 )
						if ( j != k )
							continue;
						else
							dp[ i + 1 ][k] = min( dp[ i + 1 ][k], dp[i][j] + abs( a[i] - k ) );
					else
						if ( j == k )
							dp[ i + 1 ][k] = min( dp[ i + 1 ][k], dp[i][j] + abs( a[i] - k ) );
						else
							dp[ i + 1 ][k] = min( dp[ i + 1 ][k], dp[i][j] + abs( a[i] - k ) + ( ( abs( k - j ) - 1 ) / m ) * I );
			}
		}
		
		minimum = dp[n][256];
		for ( j = 0; j < 256; j ++ )
			minimum = min( minimum, dp[n][j] );
		printf( "Case #%d: %d\n", ++ tt, minimum );
	}
	
	return 0;
}
