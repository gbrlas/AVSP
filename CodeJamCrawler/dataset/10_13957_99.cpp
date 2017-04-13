#include <iostream>
#include <cstdio>
using namespace std;

main(){
	freopen( "As.in", "r", stdin );
	freopen( "As.out", "w", stdout );
	
	int t, tt = 0;
	int n, k;
	
	scanf ( "%d", &t );
	while( t -- ){
		scanf ( "%d %d", &n, &k );
		if ( ( ( ( 1 << n ) - 1 ) & ( k + 1 ) ) == 0 )
			printf( "Case #%d: ON\n", ++ tt );
		else
			printf( "Case #%d: OFF\n", ++ tt );
	}
	
	return 0;
}
