#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int father[2100];
int MAP[3100][3100];
int ROW[3100], COL[3100];
map < int, int > row, col;
map < int, int > :: iterator it;
int xb[2100], xe[2100], yb[2100], ye[2100];
int Xb[2100], Xe[2100], Yb[2100], Ye[2100];

int find( int v ){
	if ( father[v] == v )
		return v;
	father[v] = find( father[v] );
	return father[v];
}

main(){
	int t, R, n, m, s, i, j, k, result, tt = 0;
	
	scanf ( "%d", &t );
	while( t -- ){
		scanf ( "%d", &R );
		row.clear();
		col.clear();
		for ( i = 0; i < R; i ++ ){
			scanf ( "%d %d %d %d", xb + i, yb + i, xe + i, ye + i );
			row[ xb[i] ] = 1;
			row[ xe[i] ] = 1;
			row[ xe[i] + 1 ] = 1;
			col[ yb[i] ] = 1;
			col[ ye[i] ] = 1;
			col[ ye[i] + 1 ] = 1;
		}
		s = 0;
		for ( it = row.begin(); it != row.end(); it ++ ){
			ROW[s] = it -> first;
			it -> second = s ++;
		}
		s = 0;
		for ( it = col.begin(); it != col.end(); it ++ ){
			COL[s] = it -> first;
			it -> second = s ++;
		}
		n = row.size();
		m = col.size();
		for ( i = 0; i < n; i ++ )	cout << ROW[i] << " ";	cout << endl;
		for ( i = 0; i < m; i ++ )	cout << COL[i] << " ";	cout << endl;
		memset ( MAP, -1, sizeof ( MAP ) );
		for ( i = 0; i < R; i ++ ){
			xb[i] = row[ xb[i] ];
			xe[i] = row[ xe[i] ];
			yb[i] = col[ yb[i] ];
			ye[i] = col[ ye[i] ];
			for ( j = xb[i]; j <= xe[i]; j ++ )
				for ( k = yb[i]; k <= ye[i]; k ++ )
					MAP[j][k] = i;
			father[i] = i;
		}
		cout << "MAP1" << endl;	for ( i = 0; i < n; i ++, cout << endl )	for ( j = 0; j < m; j ++ )	cout << MAP[i][j] << " ";
		for ( i = 1; i < n; i ++ )
			for ( j = 1; j < m; j ++ )
				if ( MAP[ i - 1 ][j] != -1 && MAP[i][ j - 1 ] != -1 ){
					MAP[i][j] = min( MAP[ i - 1 ][j], MAP[i][ j - 1 ] );
					father[ max( MAP[ i - 1 ][j], MAP[i][ j - 1 ] ) ] = MAP[i][j];
				}
		cout << "MAP2" << endl;	for ( i = 0; i < n; i ++, cout << endl )	for ( j = 0; j < m; j ++ )	cout << MAP[i][j] << " ";
		for ( i = 0; i < R; i ++ )
			if ( father[i] != i )
				find( i );
		for ( i = 0; i < R; i ++ )
			Xb[i] = Yb[i] = 1000000;
		for ( i = 0; i < R; i ++ )
			Xe[i] = Ye[i] = 0;
		for ( i = 0; i < n; i ++ )
			for ( j = 0; j < m; j ++ )
				if ( MAP[i][j] != -1 ){
					MAP[i][j] = father[ MAP[i][j] ];
					Xb[ MAP[i][j] ] = min( Xb[ MAP[i][j] ], i );
					Xe[ MAP[i][j] ] = max( Xe[ MAP[i][j] ], i );
					Yb[ MAP[i][j] ] = min( Yb[ MAP[i][j] ], j );
					Ye[ MAP[i][j] ] = max( Ye[ MAP[i][j] ], j );
				}
		for ( i = 0; i < R; i ++ )	cout << Xb[i] << " " << Xe[i] << " --- " << Yb[i] << " " << Ye[i] << endl;
		result = 0;
		for ( i = 0; i < R; i ++ )
			if ( Xb[i] <= Xe[i] && Yb[i] <= Ye[i] )
				result = max( result, max( ROW[ Xe[i] ] - ROW[ Xb[i] ] + 1, COL[ Ye[i] ] - COL[ Yb[i] ] + 1 ) );
		printf( "Case #%d: %d\n", ++ tt, result );
	}
	
	return 0;
}
