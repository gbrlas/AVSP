#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

struct Point{
	double x, y, r;
} c[100];

double calc( int, int, int );

main(){
	freopen( "D.in", "r", stdin );
	freopen( "D.out", "w", stdout );
	
	int t, tt = 0;
	int i, n;
	
	scanf ( "%d", &t );
	while( t -- ){
		scanf ( "%d", &n );
		for ( i = 0; i < n; i ++ )
			scanf ( "%lf %lf %lf", &c[i].x, &c[i].y, &c[i].r );
		if ( n == 1 ){
			printf( "Case #%d: %lf\n", ++ tt, c[0].r );
			continue;
		}
		if ( n == 2 ){
			printf( "Case #%d: %lf\n", ++ tt, max( c[0].r, c[1].r ) );
			continue;
		}
		
		printf( "Case #%d: %lf\n", ++ tt, min( calc( 0, 1, 2 ), min ( calc( 0, 2, 1 ), calc( 1, 2, 0 ) ) ) );
	}
	
	return 0;
}

double sqr( double x ){
	return x * x;
}

double dis( Point a, Point b ){
	return sqrt( sqr( a.x - b.x ) + sqr( a.y - b.y ) );
}

double calc( int a, int b, int d ){
	double R;
	
	R = dis( c[a], c[b] ) + c[a].r + c[b].r;
	R /= 2;
	R = max( R, c[d].r );
	
//	cout << R << endl;
	return R;
}
