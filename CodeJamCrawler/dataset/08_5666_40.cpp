#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;

int main(int argc,char *argv[])
{
	FILE* fin = fopen( "c.in", "r" );
	FILE* fout = fopen( "c.out", "w" );

	fscanf( fin, "%d", &N );
	for( int test=1; test<=N; test++ )
	{
		// read text X

		long long n, m, X, Y, Z;
		long long A[1005];
		long long T[1005];
		long long d[1005];
		
		fscanf( fin, "%lld %lld %lld %lld %lld", &n, &m, &X, &Y, &Z );
		for( int i=0; i<m; i++ )
				fscanf( fin, "%lld", &A[i] );

		for( int i=0; i<n; i++ )
		{
				T[i] = A[ i % m ];
				A[ i%m ] = ( (X * A[ i % m ]) + (Y * (i+1)) ) % Z;
				printf( " %lld", T[i] );
		}
		printf( "\n" );

		d[0] = 1;
		long long sum = 1;
		printf( "1" );
		for( int i=1; i<n; i++ )
		{
				d[i] = 1;
				for( int j=0; j<i; j++ )
						if ( T[j] < T[i] )
								d[i] += (d[j] % 1000000007);
				sum += (d[i] % 1000000007);
				printf( " %lld", d[i] );
		}
		printf( "\n" );
		sum = sum % 1000000007;
		


		fprintf( fout, "Case #%d: ", test );
		printf( "Case #%d: ", test );

		// answer here...
		fprintf( fout, "%lld", sum );
		printf( "%lld", sum );

		fprintf( fout, "\n" );
		printf( "\n" );
	}

	fclose( fin );
	fclose( fout );

	return 0;
}
