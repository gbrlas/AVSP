#include <stdio.h>
int main() {
	unsigned int t,a,b,i,x=1;
	scanf( "%d", &t );
	for( i=0; i<t; i++ ) {
		scanf( "%u%u", &a, &b );
		x=1,x <<= a;
		//printf( "%d %d",(b & (x-1)), x );
		if( (b & (x-1)) == x-1 ) printf( "Case #%u: ON\n", i+1 );
		else printf( "Case #%u: OFF\n", i+1 );
	}
	return 0;
}
