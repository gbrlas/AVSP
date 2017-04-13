#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

bool judge( int, int );

main(){
	freopen( "Cs.in", "r", stdin );
	freopen( "Cs.out", "w", stdout );
	int t, ab, ae, bb, be, a, b, tt = 0;
	int ret;
	
	scanf ( "%d", &t );
	while( t -- ){
		scanf ( "%d %d %d %d", &ab, &ae, &bb, &be );
		ret = 0;
		for ( a = ab; a <= ae; a ++ )
			for ( b = bb; b <= be; b ++ )
				if ( judge( a, b ) )
					ret ++;
		printf( "Case #%d: %d\n", ++ tt, ret );
	}
	
	return 0;
}

bool judge( int a, int b ){
	if ( a < b )
		return judge( b, a );
	if ( a >= b * 2 )
		return true;
	if ( b == 0 )
		return true;
	if ( judge( b, a - b ) )
		return false;
	return true;
}
