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
	double Result;
	int N, P, Q, R, S;

	vector< long long > A;
	vector< long long > B;

public:
	void Work()
	{
		A.reserve( N );
		for( long long i = 0; i < N; ++i )
		{
			A.push_back( ( i * P + Q ) % R + S );
		}

		int i, k;
		B.reserve( N + 1 );
		B.push_back( 0 );
		for( i = 0; i < N; ++i )
		{
			B.push_back( B[ i ] + A[ i ] );
		}

		Result = 0;

		for( k = 1; k <= N; ++k )
		{
			int left = 0, right = k; 
			while( right - left > 1 )
			{
				int middle = ( left + right ) / 2;
				if( B[ middle ] - B[ 0 ] <= B[ k ] - B[ middle ] )
					left = middle;
				else
					right = middle;
			}

			long long m0 = max( B[ N ] - B[ k ], max( B[ k ] - B[ left ], B[ left ] - B[ 0 ] ) );
			long long m1 = max( B[ N ] - B[ k ], max( B[ k ] - B[ right ], B[ right ] - B[ 0 ] ) );
			long long m = min( m0, m1 );
			double result = ( double )( B[ N ] - m ) / ( double )B[ N ];
			if( Result < result )
				Result = result;
		}
	}
	
	void Read()
	{
		scanf( "%d%d%d%d%d", &N, &P, &Q, &R, &S );
	}

	void Write( int t )
	{
		printf( "Case #%d: %.10lf\n", t, Result );
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
