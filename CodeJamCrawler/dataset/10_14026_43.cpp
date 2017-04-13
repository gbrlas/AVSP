#include <iostream>
#include <cstdio>
using namespace std;

int a[110][110];

main(){
	freopen( "Al.in", "r", stdin );
	freopen( "Al.out", "w", stdout );
	
	int result, col, row, t, tt = 0;
	int i, j, k;
	int n;
	
	scanf ( "%d", &t );
	while( t -- ){
		scanf ( "%d", &n );
		memset ( a, -1, sizeof ( a ) );
		for ( i = 0; i < n; i ++ )
			for ( j = 0; j <= i; j ++ )
				scanf ( "%d", &a[i][ n - 1 - i + j * 2 ] );
		for ( i = n - 2; i >= 0; i -- )
			for ( j = 0; j <= i; j ++ )
				scanf ( "%d", &a[ n - i + n - 2 ][ n - 1 - i + j * 2 ] );
		
		col = n + n - 1;
		for ( i = 0; i < n * 2 - 1; i ++ ){
			for ( j = 0; i - j - 1 >= 0 && i + j + 1 <= n + n - 2; j ++ ){
				for ( k = 0; k < n * 2 - 1; k ++ )
					if ( a[ i - j - 1 ][k] != a[ i + j + 1 ][k] && a[ i - j - 1 ][k] != -1 && a[ i + j + 1 ][k] != -1 )
						break;
				if ( k != n * 2 - 1 )
					break;
			}
			if ( i - j - 1 >= 0 && i + j + 1 <= n + n - 2 )
				continue;
			col = min ( col, n + abs( n - i - 1 ) );
		}
		row = n + n - 1;
		for ( i = 0; i < n * 2 - 1; i ++ ){
			for ( j = 0; i - j - 1 >= 0 && i + j + 1 <= n + n - 2; j ++ ){
				for ( k = 0; k < n * 2 - 1; k ++ )
					if ( a[k][ i - j - 1 ] != a[k][ i + j + 1 ] && a[k][ i - j - 1 ] != -1 && a[k][ i + j + 1 ] != -1 )
						break;
				if ( k != n * 2 - 1 )
					break;
			}
			if ( i - j - 1 >= 0 && i + j + 1 <= n + n - 2 )
				continue;
			row = min ( row, n + abs( n - i - 1 ) );
		} 
//		cout << col << " " << row << endl;
		result = row + col - n;
		result = result * result - n * n;
		printf( "Case #%d: %d\n", ++ tt, result );
	}
	
	return 0;
}
