#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

main(){
	int t, i, j, tt = 0;
	int dp[550][25];
	char mod[25];
	char readin[550];
	
	freopen( "input.in", "r", stdin );
	freopen( "output.out", "w", stdout );
	
	scanf ( "%d", &t );
	gets( readin );
	strcpy( mod, "welcome to code jam" );
	while( t -- ){
		gets( readin );
		memset ( dp, 0, sizeof ( dp ) );
		dp[0][0] = 1;
		for ( i = 0; readin[i]; i ++ ){
			for ( j = 0; mod[j]; j ++ ){
				if ( readin[i] == mod[j] )
					dp[ i + 1 ][ j + 1 ] = ( dp[ i + 1 ][ j + 1 ] + dp[i][j] ) % 10000;
				dp[ i + 1 ][j] = ( dp[ i + 1 ][j] + dp[i][j] ) % 10000;
			}
			dp[ i + 1 ][j] = ( dp[ i + 1 ][j] + dp[i][j] ) % 10000;
		}
		printf( "Case #%d: %04d\n", ++tt, dp[i][j] );
	}
	
	return 0;
}
