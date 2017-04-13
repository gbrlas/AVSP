#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int prime[1000100];
int a[100];

main(){
	freopen( "As.in", "r", stdin );
	freopen( "As.out", "w", stdout );
	
	int i, j, n, end, result, P;
	int A, B, d, m, t, tt = 0;
	
	memset ( prime, 0, sizeof ( prime ) );
	for ( i = 2; i < 1000100; i ++ )
		if ( prime[i] == 0 )
			for ( j = 2; i * j < 1000100; j ++ )
				prime[ i * j ] = 1;
	scanf ( "%d", &t );
	while( t -- ){
		scanf ( "%d %d", &d, &n );
		for ( i = 0; i < n; i ++ )
			scanf ( "%d", a + i );
		m = a[0];
		for ( i = 1; i < n; i ++ )
			m = max( m, a[0] );
		if ( n == 1 ){
			printf( "Case #%d: I don't know.\n", ++ tt );
			continue;
		}
		if ( n == 2 ){
			if ( a[0] == a[1] )
				printf( "Case #%d: %d\n", ++ tt, a[0] );
			else
				printf( "Case #%d: I don't know.\n", ++ tt );
			continue;
		}
		end = 1;
		while( d -- )
			end *= 10;
		result = -1;
		for ( P = m + 1; P < end; P ++ )
			if ( prime[P] == 0 )
				for ( A = 0; A < P; A ++ ){
					B = ( ( a[1] - A * a[0] ) % P + P ) % P;
					for ( i = 2; i < n; i ++ )
						if ( ( a[ i - 1 ] * A + B ) % P != a[i] )
							break;
//					if ( i == n )	cout << P << " " << A << " " << B << " " << ( a[ n - 1 ] * A + B ) % P << endl;
					if ( i == n )
						if ( result == -1 )
							result = ( a[ n - 1 ] * A + B ) % P;
						else
							if ( result != ( a[ n - 1 ] * A + B ) % P )
								result = -2;
				}
		if ( result == -1 || result == -2 )
			printf( "Case #%d: I don't know.\n", ++ tt );
		else
			printf( "Case #%d: %d\n", ++ tt, result );
	}
	
	return 0;
}
