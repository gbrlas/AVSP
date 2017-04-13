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
	static const int MAXN = 10012;
	int N;
	int X;
	int S[ MAXN ];
	int Result;
public:
	void Read()
	{
		int i;
		scanf( "%d%d", &N, &X );
		for( i = 0; i < N; ++i )
		{
			scanf( "%d", &S[ i ] );
		}
	}
	void Work()
	{
		int i;
		multiset< int, greater< int > > s;
		
		Result = 0;

		for( i = 0; i < N; ++i )
			s.insert( S[ i ] );

		while( s.size() > 0 )
		{
			int x = *s.begin();
			s.erase( s.begin() );
			if( s.size() > 0 )
			{
				multiset< int, greater< int > >::iterator sit = s.lower_bound( X - x );
				if( sit != s.end() )
					s.erase( sit );
			}
			++Result;
		}
	}
	void Write( int t )
	{
		printf( "Case #%d: %d\n", t, Result );
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
