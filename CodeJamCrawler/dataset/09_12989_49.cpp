#include <iostream>
#include <cstdio>
using namespace std;

main(){
	freopen( "A.in", "r", stdin );
	freopen( "A.out", "w", stdout );
	
	char map[50][50];
	int t, tt = 0, n, i, j, k;
	int cnt;
	
	scanf ( "%d", &t );
	while( t -- ){
		scanf ( "%d", &n );
		for ( i = 0; i < n; i ++ )
			scanf ( "%s", map[i] );
		
		cnt = 0;
		for ( i = 0; i < n; i ++ ){
			for ( j = i; j < n; j ++ ){
				for ( k = i + 1; k < n; k ++ )
					if ( map[j][k] == '1' )
						break;
				if ( k == n )
					break;
			}
			cnt += j - i;
			for ( ; j > i; j -- )
				for ( k = 0; k < n; k ++ )
					map[j][k] = map[ j - 1 ][k];
		}
		
		printf( "Case #%d: %d\n", ++ tt, cnt );
	}
	
	return 0;
}
