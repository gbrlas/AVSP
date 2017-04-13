#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <list>
#include <deque>
#include <algorithm>

using namespace std;

class Solution
{
	static const int MAXB = 1012;
	int W, H, B;
	int X0[ MAXB ], Y0[ MAXB ], X1[ MAXB ], Y1[ MAXB ];
	int Result;

public:
	void Read()
	{
		int i;
		scanf( "%d%d%d", &W, &H, &B );
		for( i = 0; i < B; ++i )
		{
			scanf( "%d%d%d%d", &X0[ i ], &Y0[ i ], &X1[ i ], &Y1[ i ] );
			++X1[ i ];
			++Y1[ i ];
		}
	}

	static const int INF = 1000000000;

	void Work()
	{
		int i, j;

		int N = B + 2;
		vector< vector< int > > M( B + 2, vector< int >( B + 2, -1 ) );

		for( i = 0; i < B; ++i )
		{
			for( j = i + 1; j < B; ++j )
			{
				int mx = INF, my = INF;
				if( X0[ j ] >= X1[ i ] )
					mx = min( mx, X0[ j ] - X1[ i ] );
				if( X0[ i ] >= X1[ j ] )
					mx = min( mx, X0[ i ] - X1[ j ] );
				if( Y0[ j ] >= Y1[ i ] )
					my = min( my, Y0[ j ] - Y1[ i ] );
				if( Y0[ i ] >= Y1[ j ] )
					my = min( my, Y0[ i ] - Y1[ j ] );
				if (mx == INF)
					mx = -1;
				if (my == INF)
					my = -1;
				M[ i ][ j ] = M[ j ][ i ] = max( mx, my );
			}

			M[ B ][ i ] = M[ i ][ B ] = X0[ i ];
			M[ i ][ B + 1 ] = M[ B + 1 ][ i ] = W - X1[ i ];
		}
		M[ B ][ B + 1 ] = W;
		M[ B + 1 ][ B ] = W;

		vector< int > Weight( N, -1 );
		vector< char > U( N, false );

		Weight[ B ] = 0;

		while( true )
		{
			int min = -1;
			for( i = 0; i < N; ++i )
			{
				if( !U[ i ] && Weight[ i ] != -1 )
					if( min == -1 || Weight[ min ] > Weight[ i ] )
						min = i;
			}
			if( min == -1 )
				break;
			U[ min ] = true;
			if( min == B + 1 )
				break;
			for( i = 0; i < N; ++i )
			{
				if( U[ i ] )
					continue;
				if( M[ min ][ i ] == -1 )
					continue;
				if( Weight[ i ] == -1 || Weight[ i ] > Weight[ min ] + M[ min ][ i ] )
					Weight[ i ] = Weight[ min ] + M[ min ][ i ];
			}
		}

		Result = Weight[ B + 1 ];
	}
	
	void Write( int t )
	{
		printf( "Case #%d: %d\n", t, Result );
	}
};

vector< Solution > solution;

int main()
{
	int i, t;
	scanf( "%d", &t );
	solution.resize( t );
	for( i = 0; i < t; ++i )
		solution[ i ].Read();
#pragma omp parallel for schedule(dynamic, 1)
	for( i = 0; i < t; ++i )
		solution[ i ].Work();
	for( i = 0; i < t; ++i )
		solution[ i ].Write( i + 1 );
	return 0;
}
