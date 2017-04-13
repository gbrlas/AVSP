#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n, m;
int grid[110][110];
int record[110][110];
char code[10500];
char output[110][110];

int dfs( int, int );

main(){
	int tt = 0;
	int t, i, j;
	char start;
	
	freopen( "input.in", "r", stdin );
	freopen( "output.out", "w", stdout );
	
	scanf ( "%d", &t );
	while( t -- ){
		scanf ( "%d %d", &n, &m );
		for ( i = 0; i < n; i ++ )
			for ( j = 0; j < m; j ++ )
				scanf ( "%d", &grid[i][j] );
		memset ( record, -1, sizeof ( record ) );
		memset ( code, -1, sizeof ( code ) );
		start = 'a';
		for ( i = 0; i < n; i ++ )
			for ( j = 0; j < m; j ++ ){
				if ( record[i][j] == -1 )
					record[i][j] = dfs( i, j );
				if ( code[ record[i][j] ] == -1 )
					code[ record[i][j] ] = start ++;
				output[i][j] = code[ record[i][j] ];
			}
		printf( "Case #%d:\n", ++ tt );
		for ( i = 0; i < n; i ++ )
			for ( j = 0; j < m; j ++ )
				if ( j == m - 1 )
					printf( "%c\n", output[i][j] );
				else
					printf( "%c ", output[i][j] );
	}
	
	return 0;
}

int alti( int x, int y ){
	if ( x < 0 || x >= n || y < 0 || y >= m )
		return 100000;
	
	return grid[x][y];
}

int v, N, W, E, S, minimum;

int dfs( int x, int y ){
	if ( x < 0 || x >= n || y < 0 || y >= m )
		return 100000;
	
	v = alti( x, y );
	N = alti( x - 1, y );
	W = alti( x, y - 1 );
	E = alti( x, y + 1 );
	S = alti( x + 1, y );
	minimum = min( min( N, S ), min( W, E ) );
	if ( minimum >= v )
		return x * m + y;
	
	if ( N == minimum ){
		if ( record[ x - 1 ][y] == -1 )
			record[ x - 1 ][y] = dfs( x - 1, y );
		return record[ x - 1 ][y];
	}
	
	if ( W == minimum ){
		if ( record[x][ y - 1 ] == -1 )
			record[x][ y - 1 ] = dfs( x, y - 1 );
		return record[x][ y - 1 ];
	}
	
	if ( E == minimum ){
		if ( record[x][ y + 1 ] == -1 )
			record[x][ y + 1 ] = dfs( x, y + 1 );
		return record[x][ y + 1 ];
	}
	
	if ( S == minimum ){
		if ( record[ x + 1 ][y] == -1 )
			record[ x + 1 ][y] = dfs( x + 1, y );
		return record[ x + 1 ][y];
	}
	
	return -1;
}
