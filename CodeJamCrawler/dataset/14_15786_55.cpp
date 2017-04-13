#include<cstdio>
#include<cstring>
double calc[ 1000000 ];

int main()
{
	int t;
	double cost, add, goal;
	scanf( "%d", &t );

	for( int n = 1; n <= t; ++n )
	{
		scanf( "%lf %lf %lf", &cost, &add, &goal );
		memset( calc, 0, sizeof( calc ) );
		int size = 2;
		for( *calc = goal/2, calc[ 1 ] = cost/2 + goal / ( 2+add ); calc[ size-1 ] < calc[ size-2 ]; ++size )
		{
			for( int i = 0; i < size; ++i )
				calc[ size ] += cost / ( 2 + add*i );
			calc[ size ] += goal / ( 2 + add*size );
		}
		printf( "Case #%d: %.7f\n", n, calc[ size-2 ] );
	}
}
