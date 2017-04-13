// codejam.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include<fstream>
#include<vector>
#include<string>

typedef struct
{
	unsigned int g[1000];// valid g is [n-1]
	unsigned int r;
	unsigned int k;
	unsigned int n;
}Problem;

bool read_problem( const _TCHAR *fname , std::vector<Problem>& problemvec )
{
	std::fstream ifs;
	ifs.open( fname );
	std::string line1,line2;

	if( ifs.is_open() )
	{
		if( getline( ifs , line1 ) )
		{
			int number = strtoul( line1.c_str() , NULL , 10);
			while( getline( ifs , line1 ) && getline( ifs , line2 ))
			{
				Problem problem;
				// line1
				int startpos=0;
				problem.r = strtoul( line1.c_str() , NULL , 10 );
				startpos = line1.find( " " , startpos + 1 );
				problem.k = strtoul( line1.c_str() + startpos , NULL , 10 );
				startpos = line1.find( " " , startpos + 1 );
				problem.n = strtoul( line1.c_str() + startpos , NULL , 10 );
				// line2
				startpos = 0;
				unsigned int index = 0;
				do
				{
					if( index >= 1000 || index >= problem.n ) return false;
					problem.g[index++] = strtoul( line2.c_str() + startpos , NULL , 10 );
				}while( ( startpos = line2.find( " ", startpos + 1 ) ) != std::string::npos );
				problemvec.push_back( problem );
				--number;
			}
			if( number == 0 )
			{
				return true;
			}
		}
	}
	return false;
}

typedef struct
{
	__int64 next_cost;
	unsigned int next_index;
}Rcm;

__int64 solve( const Problem& pb )
{
	std::vector< Rcm > rcmvec;
	rcmvec.resize( pb.n );

	for( unsigned int i = 0 ; i < pb.n ; ++i )
	{
		Rcm rcm;

		__int64 cost = 0;
		unsigned int j = i;
		
		do{
			j %= pb.n;
			cost+=pb.g[j++];
		}while( ( ( cost + pb.g[ j % pb.n ] ) ) <= pb.k && ( j % pb.n != i ) );

		rcm.next_index = j % pb.n;
		rcm.next_cost = cost;

		rcmvec[i] = rcm;
	}

	__int64 euros = 0;
	unsigned int current_index = 0;

	for( unsigned int i = 0 ; i < pb.r ; ++i )
	{
		euros += rcmvec[current_index].next_cost;
		current_index = rcmvec[ current_index ].next_index;
	}

	return euros;
}

int _tmain(int argc, _TCHAR* argv[])
{
	if( argc != 2 )
	{
		printf("invalid argment\n");
		return -1;
	}
	std::vector<Problem> problemvec;
	if( !read_problem( argv[1] , problemvec ) )
	{
		return -2;
	}

	std::vector<Problem>::iterator itr = problemvec.begin();
	unsigned int x = 1;
	while( itr != problemvec.end() )
	{
		__int64 euros = solve( *itr );
		printf("Case #%d: %lld\n",x,euros);
		++x;
		++itr;
	}

	return 0;
}

