#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;

int compare( const void* a, const void* b )
{
		int aa = *(int*)a;
		int bb = *(int*)b;
		return bb - aa;
}

int main(int argc,char *argv[])
{
	FILE* fin = fopen( "a.in", "r" );
	FILE* fout = fopen( "a.out", "w" );

	fscanf( fin, "%d", &N );
	for( int test=1; test<=N; test++ )
	{
		// read text X
		//
		
		int P, K, L;	
		long long x[2000];
		memset( x, 0, sizeof(x) );

		fscanf( fin, "%d %d %d", &P, &K, &L );
		for( int i=1; i<=L; i++ )
				fscanf( fin, "%d", &x[i] );

		qsort( x+1, L, sizeof(x[0]), compare );
		for( int i=1; i<=L; i++ )
				printf( " %d", x[i] );
		printf( "\n" );

		
		int button = 1;
		long long answer = 0;
		int letters[1001];

		int currentLetter = 1;

		fprintf( fout, "Case #%d: ", test );
		printf( "Case #%d: ", test );
		
		if ( P*K < L )
		{
				fprintf( fout, "Impossible" );
				printf( "Impossible" );
		}
		else
		{
			for( int place=1; place<=P; place++ )
			{
				for( int key=1; key<=K; key++ )
				{
					if ( currentLetter <= L )
					{
						answer += (long long)place * x[currentLetter] ;
						currentLetter++;
					}
				}
			}

			fprintf( fout, "%lld", answer );
			printf( "%lld", answer );
		}


		// answer here...

		fprintf( fout, "\n" );
		printf( "\n" );
	}

	fclose( fin );
	fclose( fout );

	return 0;
}
