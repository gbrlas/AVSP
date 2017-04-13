#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define GINTN(A) (fscanf(stdin,"%ld\n",&(A)))
#define GINT(A) long A; fscanf(stdin,"%ld",&(A));if(debug)printf("%d ",A);
#define GINTA(A) fscanf(stdin,"%ld",&(A))
#define GBIG(A) (fscanf(stdin,"%lld",&(A)))
#define GSTR(A) (gets(A))
#define ARRAY(T,V,N) T* V = ((T*)malloc(sizeof(T)*N))

typedef long long BIG;

int main( int argc, char* argv[] )
	{
	bool debug = false;

	if( argc > 1 ) debug = true;

	long tests; GINTN(tests);

	for( int t = 0; t < tests; t++ )
		{
		int res = 0;

		GINT(A);
		GINT(B);

		for( int a = A; a <= B; a++ ) for( int b = a+1; b <= B; b++ )
			{
			static char za[20], zb[20];

			sprintf( za, "%d%d", a, a );
			sprintf( zb, "%d", b );

			if( strstr( za, zb ) )
				res++;
			}

		printf( "Case #%d: %d\n", t+1, res );

		if( debug ) printf( "\t****\n\n" );
		}

	return 0;
	}
