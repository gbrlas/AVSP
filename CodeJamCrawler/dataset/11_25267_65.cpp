#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 10007

long Freq[MAX+7];
long N,L,H;

int main( void )
{
	long i,j,Icase,k=0;

	freopen("C.in","r",stdin );
	freopen("C.out","w",stdout );

	scanf("%ld",&Icase );
	while( Icase--){
		scanf("%ld%ld%ld",&N,&L,&H );
		for( i=1;i<=N;i++){
			scanf("%ld",&Freq[i] );
		}

		for( i=L;i<=H;i++){
			for( j=1;j<=N;j++){
				long u = i;
				long v = Freq[j];
				if( u<v ) swap( u,v );
				if( u%v ) break;
			}
			if( j>N ) break;
		}
		

		if( i>H ){
			printf("Case #%ld: NO\n",++k );
		}
		else{
			printf("Case #%ld: %ld\n",++k,i );
		}
	}

	return 0;
}



