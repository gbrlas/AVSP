#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;

int k;
char map[55][55];
int add ( string );

main(){
	freopen( "As.in", "r", stdin );
	freopen( "As.out", "w", stdout );
	
	int n, i, j, result, m, t, tt = 0;
	string judge;
	
	scanf ( "%d", &t );
	while( t -- ){
		scanf ( "%d %d", &n, &k );
		for ( i = 0; i < n; i ++ )
			scanf ( "%s", map[i] );
		for ( i = 0; i < n; i ++ ){
			m = n - 1;
			for ( j = n - 1; j >= 0; j -- )
				if ( map[i][j] != '.' )
					if ( j == m )
						m --;
					else{
						map[i][ m -- ] = map[i][j];
						map[i][j] = '.';
					}
		}
		result = 0;
		for ( i = 0; i < n; i ++ ){
			judge = "";
			for ( j = 0; j < n; j ++ )
				judge = judge + map[i][j];
			result |= add( judge );
		}
		for ( i = 0; i < n; i ++ ){
			judge = "";
			for ( j = 0; j < n; j ++ )
				judge = judge + map[j][i];
			result |= add( judge );
		}
		for ( i = 0; i < n; i ++ ){
			judge = "";
			for ( j = 0; j < i; j ++ )
				judge = judge + map[j][ i - j ];
			result |= add( judge );
			judge = "";
			for ( j = 0; j + i < n; j ++ )
				judge = judge + map[j][ i + j ];
			result |= add( judge );
		}
		for ( i = 0; i < n; i ++ ){
			judge = "";
			for ( j = 0; j < i; j ++ )
				judge = judge + map[ n - j - 1 ][j];
			result |= add( judge );
			judge = "";
			for ( j = 0; j + i < n; j ++ )
				judge = judge + map[ i + j ][ n - j - 1 ];
			result |= add( judge );
		}
		if ( result == 3 )
			printf( "Case #%d: Both\n", ++ tt );
		if ( result == 2 )
			printf( "Case #%d: Blue\n", ++ tt );
		if ( result == 1 )
			printf( "Case #%d: Red\n", ++ tt );
		if ( result == 0 )
			printf( "Case #%d: Neither\n", ++ tt );
	}
	
	return 0;
}

int add( string judge ){
	int L = judge.length();
	if ( L < k )
		return 0;
	int B = 0, R = 0;
	int ret = 0;
	int i;
	for ( i = 0; i < L; i ++ ){
		if ( judge[i] == '.' )
			B = R = 0;
		if ( judge[i] == 'R' ){
			R ++;
			B = 0;
			if ( R == k )
				ret |= 1;
		}
		if ( judge[i] == 'B' ){
			B ++;
			R = 0;
			if ( B == k )
				ret |= 2;
		}
	}
	
	return ret;
}
