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
	static const int MAXN = 12;
	static const int MAXM = 12;
	static const int MAXLEN = 12;
	int N, M;
	char S[ MAXM ][ MAXLEN + 1 ];
	int Result, Count;

public:
	void Read()
	{
		int i;
		scanf( "%d%d", &M, &N );
		for( i = 0; i < M; ++i )
		{
			scanf( "%s", &S[ i ] );
		}
	}

	int SN[ MAXM ];
	
	void Work()
	{
		Result = 0;

		func( 0 );
	}
	
	void func( int k )
	{
		if( k == M )
		{
			int i, j;
			int r = 0;
			for( i = 0; i < N; ++i )
			{
				set< string > x;
				for( j = 0; j < M; ++j )
				{
					if( SN[ j ] != i )
						continue;
					for( k = 0; ; ++k )
					{
						x.insert( string( S[ j ], k ) );
						if( S[ j ][ k ] == '\0' )
							break;
					}
				}
				r += ( int )x.size();
			}
			if( Result < r )
			{
				Result = r;
				Count = 1;
			}
			else if( Result == r )
			{
				++Count;
			}
		}
		else
		{
			for( SN[ k ] = 0; SN[ k ] < N; ++SN[ k ] )
				func( k + 1 );
		}
	}

	void Write( int t )
	{
		printf( "Case #%d: %d %d\n", t, Result, Count );
	}
};

int main()
{
	int i, t;
	scanf( "%d", &t );
	vector< Solution > solution( t );
	for( i = 0; i < t; ++i )
		solution[ i ].Read();
#pragma omp parallel for schedule(dynamic, 1)
	for( i = 0; i < t; ++i )
		solution[ i ].Work();
	for( i = 0; i < t; ++i )
		solution[ i ].Write( i + 1 );
	return 0;
}
