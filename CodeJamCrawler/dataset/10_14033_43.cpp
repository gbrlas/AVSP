#include <iostream>
#include <cstdio>
using namespace std;

int sum;
int n, P;
int p[2048];
int m[2048];
int dp[2048][20];

void find( int v, int add ){
	if ( v >= n ){
		if ( P - add <= m[ v - n ] )
			dp[v][add] = 0;
		else
			dp[v][add] = sum;
//	cout << "find " << v << " " << add << " " << dp[v][add] << endl;
		return;
	}
	if ( dp[ v * 2 ][add] == -1 )
		find( v * 2, add );
	if ( dp[ v * 2 + 1 ][add] == -1 )
		find( v * 2 + 1, add );
	if ( dp[ v * 2 ][ add + 1 ] == -1 )
		find( v * 2, add + 1 );
	if ( dp[ v * 2 + 1 ][ add + 1 ] == -1 )
		find( v * 2 + 1, add + 1 );
	dp[v][add] = min( dp[ v * 2 ][add] + dp[ v * 2 + 1 ][add], dp[ v * 2 ][ add + 1 ] + dp[ v * 2 + 1 ][ add + 1 ] + p[v] );
//	cout << "find " << v << " " << add << " " << dp[v][add] << endl;
}

main(){
	int t, tt = 0;
	int i, N;
	freopen( "Bs.in", "r", stdin );
	freopen( "Bs.out", "w", stdout );
	scanf ( "%d", &t );
	while ( t -- ){
		scanf ( "%d", &P );
		n = ( 1 << P );
		for ( i = 0; i < n; i ++ )
			scanf ( "%d", m + i );
		N = n / 2;
		while( N ){
			for ( i = 0; i < N; i ++ )
				scanf( "%d", p + N + i );
			N /= 2;
		}
		sum = 0;
		for ( i = 1; i < n; i ++ )
			sum = sum + p[i];
		memset ( dp, -1, sizeof ( dp ) );
		find( 1, 0 );
		printf( "Case #%d: %d\n", ++ tt, dp[1][0] );
	}
	
	return 0;
}
