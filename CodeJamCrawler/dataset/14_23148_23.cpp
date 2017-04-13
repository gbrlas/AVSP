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
	int P, Q, N;
	vector< int > H, G;

	int Result;

	static const int MAX_HIT = 10012;
	vector< vector< int > > Best;

public:
	void Work()
	{
		int i, j, k, h;

		Best.resize( N + 1, vector< int >( MAX_HIT + 1, -1 ) );
		Best[ 0 ][ 1 ] = 0;

		for( k = 0; k < N; ++k )
		{
			for( h = 0; h <= MAX_HIT; ++h )
			{
				if( Best[ k ][ h ] == -1 )
					continue;
				
				{
					// тёлка не стреляет
					int c = ( H[ k ] - 1 ) / Q + 1;
					if( Best[ k + 1 ][ h + c ] == -1 || Best[ k + 1 ][ h + c ] < Best[ k ][ h ] )
						Best[ k + 1 ][ h + c ] = Best[ k ][ h ];
				}

				{
					// стреляет
					for( i = 0; i <= h; ++i )
					{
						int hr = H[ k ] - i * P;
						if( hr > 0 )
						{
							if( ( hr - 1 ) % ( Q + P ) < Q )
								continue;
						}
						if( Best[ k + 1 ][ h - i ] == -1 || Best[ k + 1 ][ h - i ] < Best[ k ][ h ] + G[ k ] )
							Best[ k + 1 ][ h - i ] = Best[ k ][ h ] + G[ k ];
					}

					for( i = 1; H[ k ] - i * Q > 0; ++i )
					{
						int hr = H[ k ] - i * Q;
						if( ( hr - 1 ) % ( Q + P ) < Q )
							continue;
						if( Best[ k + 1 ][ h + i ] == -1 || Best[ k + 1 ][ h + i ] < Best[ k ][ h ] + G[ k ] )
							Best[ k + 1 ][ h + i ] = Best[ k ][ h ] + G[ k ];
					}
				}
			}
		}

		Result = 0;
		for( i = 0; i <= MAX_HIT; ++i )
		{
			if( Best[ N ][ i ] == -1 )
				continue;
			if( Result < Best[ N ][ i ] )
				Result = Best[ N ][ i ];
		}
	}
	
	void Read()
	{
		int i;

		scanf( "%d%d%d", &P, &Q, &N );
		H.resize( N );
		G.resize( N );
		for( i = 0; i < N; ++i )
		{
			scanf( "%d%d", &H[ i ], &G[ i ] );
		}
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
