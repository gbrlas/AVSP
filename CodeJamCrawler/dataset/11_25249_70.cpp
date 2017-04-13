#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 7777777

long N;

int main( void )
{
	long i,v,Icase,k=0;

	freopen("C.in","r",stdin );
	freopen("C.out","w",stdout );

	scanf("%ld",&Icase );
	while( Icase--){
		scanf("%ld",&N );
		long NtP = 0;
		long Tot = 0;
		long m = MAX;
		for( i=1;i<=N;i++){
			scanf("%ld",&v);
			NtP = NtP ^ v;
			if( v < m ) m = v;
			Tot += v;
		}

		if( NtP ){
			printf("Case #%ld: NO\n",++k );
		}
		else{
			printf("Case #%ld: %ld\n",++k,Tot - m );
		}
	}

	return 0;
}



