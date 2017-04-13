#include <stdio.h>
#define FOR(i,a,b) for(i=(a);i<=(b);i++)
#define REP(i,n) FOR(i,0,n-1)

int main() {
	int t, R,k, N, i, G[10], p,c, I, tot,s;
	scanf( "%d", &t );
	REP( I,t ) {
		s = 0;
		scanf( "%d%d%d", &R, &k, &N );
		REP( i,N ) {
			scanf( "%d", &G[i] );
			s += G[i];
		}
		if( s > k ) {
			p = tot=0;
			while( R-- ) {
				c = 0;
				do{
					c += G[p];
					p++; if( p >= N ) p = p%N;
				}while( G[p]+c <= k );
				tot += c;
			}
		}
		else {
			tot = s*R;
		}
		printf( "Case #%d: %d\n", I+1, tot );
	}
	return 0;
}
