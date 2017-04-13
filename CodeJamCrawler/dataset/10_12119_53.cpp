#include <stdio.h>
#include <stdlib.h>

#define MAXN 1010

int main(){

		int t, r, n, g, i, pos, firstin, ncase = 1;
		long long queue[MAXN];
		long long k, this, out;

		scanf("%d", &t );
		while( t-- ){

			scanf("%d %lld %d", &r, &k, &n );

			for( i = 0; i < n; i++ )
				scanf("%lld", &queue[i] );

			out = 0;
			pos = 0;
			while( r-- ){

				this = 0;
				firstin = pos;
				while( (this + queue[pos]) <= k ){
					this += queue[pos++];
					if( pos == n ) pos = 0;
					if( pos == firstin ) break;
				}
				out += this;
			
			}
			
			printf("Case #%d: %lld\n", ncase++, out );
		
		}

		return 0;
}

