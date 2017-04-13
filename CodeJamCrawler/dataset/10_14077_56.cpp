#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int b;
int digit[110][110];

int dfs( int left, int m ){
//	cout << "dfs: " << left << " " << m << endl;
	if ( left < 0 )
		return 0;
	if ( left == 0 )
		return 1;
	if ( m <= 0 )
		return 0;
	int ret = 0;
	int i, j;
	int sub;
	int t;
	
	for ( i = min( m, left ); i > 0; i -- ){
		t = i;
		for ( j = 0; t; j ++ )
			if ( digit[j][ t % b ] )
				break;
			else
				t /= b;
		if ( t )
			continue;
		t = i;
		sub = 1;
		for ( j = 0; t; j ++ ){
			digit[j][ t % b ] = 1;
			t /= b;
			sub *= b;
		}
		sub /= b;
		ret += dfs( left - i, ( i / sub ) * sub - 1 );
		t = i;
		for ( j = 0; t; j ++ ){
			digit[j][ t % b ] = 0;
			t /= b;
		}
	}
	return ret;
}

main(){
	int n, t, tt = 0;
	
	freopen( "Ds.in", "r", stdin );
	freopen( "Ds.out", "w", stdout );
	
	scanf ( "%d", &t );
	while( t -- ){
		scanf ( "%d %d", &n, &b );
		memset ( digit, 0, sizeof ( digit ) );
		printf( "Case #%d: %d\n", ++ tt, dfs( n, n ) );
	}
	
	return 0;
}
