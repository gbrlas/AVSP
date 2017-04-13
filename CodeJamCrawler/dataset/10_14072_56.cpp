#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

int value[2002000];

priority_queue< int > heap;

main(){
	int t, tt = 0;
	int c, P, V;
	int i, result;
	
	freopen( "Cs.in", "r", stdin );
	freopen( "Cs.out", "w", stdout );
	
	scanf ( "%d", &t );
	while( t -- ){
		scanf ( "%d", &c );
		while ( heap.size() )
			heap.pop();
		memset ( value, 0, sizeof ( value ) );
		for ( i = 0; i < c; i ++ ){
			scanf ( "%d %d", &P, &V );
			P += 1001000;
			value[P] = V;
			if ( V > 1 )
				heap.push( P );
		}
		result = 0;
		while( heap.size() ){
			P = heap.top();
			heap.pop();
			value[P] --;
			value[P] --;
			if ( value[P] > 1 )
				heap.push( P );
			if ( value[ P - 1 ] == 1 )
				heap.push( P - 1 );
			if ( value[ P + 1 ] == 1 )
				heap.push( P + 1 );
			value[ P - 1 ] ++;
			value[ P + 1 ] ++;
			result ++;
		}
		printf( "Case #%d: %d\n", ++ tt, result );
	}
	
	return 0;
}
