#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;

char D[50];
int S[50];

long long counter;

int isUgly( long long x )
{
		if ( (x%2) == 0 )
				return 1;
		if ( (x%3) == 0 )
				return 1;
		if ( (x%5) == 0 )
				return 1;
		if ( (x%7) == 0 )
				return 1;
				
		return 0;
}

int prn()
{
		for( int i=0; i<strlen(D); i++ )
		{
				if ( S[i] == 1 )
						printf( "-" );
				if ( S[i] == 2 ) 
						printf( "+" );
				printf( "%c", D[i] );
		}
		return 0;
}

long long evaluate()
{
		int p=0;
		int n = strlen( D );
		
		int result = 0;
		int sign = 1;
		if( S[0] == 1 )
				sign=-1;
	
//		prn();
//		printf( " x " );
		
		long long sum = 0;
		long long temp = 0;
		while( p < n )
		{
				if ( S[p] == 0 ) //no sign
				{
						temp *= 10 ;
						temp += (D[p]-48);
				}
				else if ( S[p] == 1 ) // - 
				{
						sum += sign * temp;
//						printf( " %d", sign*temp );
						sign = -1;
						temp = 0;
						temp += (D[p]-48);
				}
				else if ( S[p] == 2 )
				{
						sum += sign * temp;
//						printf( " %d", sign*temp );
						sign = 1;
						temp = 0;
						temp += (D[p]-48);
				}
				p++;
		}
		sum += sign*temp;
//		printf( " %d", sign*temp );

//		printf( " = %lld\n", sum );
		
		return sum;
}

int find( int p )
{
		if ( p == strlen( D ) )
		{
			long long sum = evaluate();
			if ( isUgly( sum ) )
			{
					counter++;
//					printf( "%lld is ugly\n", sum );
			}
			return 0;
		}
		
		for( int k=0; k<=2; k++ )
		{
				S[p] = k;
				find( p+1 );
				S[p] = 0;
		}
}

int main(int argc,char *argv[])
{
	FILE* fin = fopen( "b.in", "r" );
	FILE* fout = fopen( "b.out", "w" );

	fscanf( fin, "%d", &N );
	for( int test=1; test<=N; test++ )
	{
		// read text X
		fscanf( fin, "%s", D ); 

		counter = 0;
		find( 1 );

		fprintf( fout, "Case #%d: ", test );
		printf( "Case #%d: ", test );

		// answer here...
		fprintf( fout, "%lld", counter );
		printf( "%lld", counter );

		fprintf( fout, "\n" );
		printf( "\n" );
	}

	fclose( fin );
	fclose( fout );

	return 0;
}
