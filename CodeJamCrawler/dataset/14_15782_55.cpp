#include<cstdio>

int main()
{
	int t, row, field[ 4 ][ 4 ], ans;
	scanf( "%d", &t );

	for( int n = 1; n <= t; ++n )
	{
		bool possible[ 17 ] = { false };
		int all = 0;
		scanf( "%d", &row );
		--row;
		for( int i = 0; i < 4; ++i )
			for( int j = 0; j < 4; ++j )
				scanf( "%d", &field[ i ][ j ] );
		for( int i = 0; i < 4; ++i )
			possible[ field[ row ][ i ] ] = true;
		scanf( "%d", &row );
		--row;
		for( int i = 0; i < 4; ++i )
			for( int j = 0; j < 4; ++j )
				scanf( "%d", &field[ i ][ j ] );
		for( int i = 0; i < 4; ++i )
			if( possible[ field[ row ][ i ] ] )
				++all, ans = field[ row ][ i ];
		if( all == 1 )
			printf( "Case #%d: %d\n", n, ans );
		else if( all )
			printf( "Case #%d: Bad magician!\n", n );
		else
			printf( "Case #%d: Volunteer cheated!\n", n );
	}
}
