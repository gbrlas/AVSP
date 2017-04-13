#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

map< long long, int > app;
int list[2764800];
char grid[20][20];
int vst[12][12];
int nowstep;
int R, C;
int *beg;
int *end;
int cnt;

void push( int );
void pull( int, int );
int floodfill( int, int );

main(){
	freopen( "input.in", "r", stdin );
	freopen( "output.out", "w", stdout );
	
	int t, i, j, p, tt = 0;
	long long status;
	long long final;
	
	scanf ( "%d", &t );
	while( t -- ){
		app.clear();
		scanf ( "%d %d", &R, &C );
		for ( i = 0; i < R; i ++ )
			scanf ( "%s", grid[i] );
		status = 0;
		final = 0;
		cnt = 0;
		for ( i = 0; i < R; i ++ )
			for ( j = 0; j < C; j ++ ){
				if ( grid[i][j] == 'o' || grid[i][j] == 'w' ){
					status = status * 144 + ( i * 12 + j );
					cnt ++;
				}
				if ( grid[i][j] == 'x' || grid[i][j] == 'w' )
					final = final * 144 + ( i * 12 + j );
			}
		for ( i = 0; i < R; i ++ )
			for ( j = 0; j < C; j ++ )
				if ( grid[i][j] == 'o' || grid[i][j] == 'x' || grid[i][j] == 'w' )
					grid[i][j] = '.';
		
		app[ status ] = 1;
		*list = status;
		beg = list;
		end = list + 1;
		while( beg < end ){
			if ( app[final] != 0 )
				break;
			
			status = *beg;
			nowstep = app[status];
			for ( i = 0; i < cnt; i ++ ){
				p = status % 144;
				status /= 144;
				grid[ p / 12 ][ p % 12 ] = 'o';
			}
			status = *beg;
			for ( i = 0; i < cnt; i ++ ){
				p = status % 144;
				status /= 144;
				pull( p / 12, p % 12 );
			}
			status = *beg;
			for ( i = 0; i < cnt; i ++ ){
				p = status % 144;
				status /= 144;
				grid[ p / 12 ][ p % 12 ] = '.';
			}
			beg ++;
		}
		
		printf( "Case #%d: %d\n", ++ tt, app[final] - 1 );
	}
	
	return 0;
}

void pull( int r, int c ){
	if ( !( c == 0 || c == C - 1 ) )
		if ( grid[r][ c - 1 ] == '.' && grid[r][ c + 1 ] == '.' ){
			grid[r][c] = '.';
			grid[r][ c + 1 ] = 'o';
			memset ( vst, 0, sizeof ( vst ) );
			if ( nowstep < 0 ){
				if ( floodfill( r, c + 1 ) == cnt )
					push( ( - nowstep ) + 1 );
			}
			else
				if ( floodfill( r, c + 1 ) == cnt )
					push( nowstep + 1 );
				else
					push( ( - nowstep ) - 1 );
			grid[r][ c + 1 ] = '.';
			grid[r][ c - 1 ] = 'o';
			memset ( vst, 0, sizeof ( vst ) );
			if ( nowstep < 0 ){
				if ( floodfill( r, c - 1 ) == cnt )
					push( ( - nowstep ) + 1 );
			}
			else
				if ( floodfill( r, c - 1 ) == cnt )
					push( nowstep + 1 );
				else
					push( ( - nowstep ) - 1 );
			grid[r][ c - 1 ] = '.';
			grid[r][c] = 'o';
		}
	if ( !( r == 0 || r == R - 1 ) )
		if ( grid[ r - 1 ][c] == '.' && grid[ r + 1 ][c] == '.' ){
			grid[r][c] = '.';
			grid[ r + 1 ][c] = 'o';
			memset ( vst, 0, sizeof ( vst ) );
			if ( nowstep < 0 ){
				if ( floodfill( r + 1, c ) == cnt )
					push( ( - nowstep ) + 1 );
			}
			else
				if ( floodfill( r + 1, c ) == cnt )
					push( nowstep + 1 );
				else
					push( ( - nowstep ) - 1 );
			grid[ r + 1 ][c] = '.';
			grid[ r - 1 ][c] = 'o';
			memset ( vst, 0, sizeof ( vst ) );
			if ( nowstep < 0 ){
				if ( floodfill( r - 1, c ) == cnt )
					push( ( - nowstep ) + 1 );
			}
			else
				if ( floodfill( r - 1, c ) == cnt )
					push( nowstep + 1 );
				else
					push( ( - nowstep ) - 1 );
			grid[ r - 1 ][c] = '.';
			grid[r][c] = 'o';
		}
}

int floodfill( int r, int c ){
	if ( r < 0 || c < 0 || r >= R || c >= C )
		return 0;
	if ( grid[r][c] != 'o' )
		return 0;
	if ( vst[r][c] )
		return 0;
	vst[r][c] = 1;
	
	return 1 + floodfill( r + 1, c ) + floodfill( r - 1, c ) + floodfill( r, c - 1 ) + floodfill( r, c + 1 );
}

void push( int step ){
	int i, j;
	long long status = 0;
	
	for ( i = 0; i < R; i ++ )
		for ( j = 0; j < C; j ++ )
			if ( grid[i][j] == 'o' )
				status = status * 144 + ( i * 12 + j );
	if ( app[status] == 0 ){
		app[status] = step;
		*end = status;
		end ++;
	}
}
