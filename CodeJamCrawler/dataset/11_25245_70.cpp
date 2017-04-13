#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

long N;

int main( void )
{
	long i,b,Icase,k=0;
	char Ch;

	freopen("A.in","r",stdin );
	freopen("A.out","w",stdout );

	scanf("%ld",&Icase );
	while( Icase--){
		scanf("%ld",&N );
		//long PosO = 1;
		//long PosB = 1;
		long LstO = 1;
		long LstB = 1;
		long TmO = 0;
		long TmB = 0;
		long t = 0;
		for( i=1;i<=N;i++){
			scanf(" %c%ld",&Ch,&b );
			if( Ch=='O'){
				long d = labs( b-LstO );
				if( t-TmO >= d ) t++;
				else t = TmO + d +1;
				TmO = t;
				LstO = b;
			}
			else if( Ch=='B'){
				long d = labs( b-LstB );
				if( t-TmB >= d ) t++;
				else t = TmB + d +1;
				TmB = t;
				LstB = b;
			}
		}
		long Ans = t;
		printf("Case #%ld: %ld\n",++k,Ans);
	}

	return 0;
}

