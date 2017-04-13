// codejam_1A.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include<fstream>
#include<vector>
#include<string>
#include<set>
using namespace std;

typedef struct
{
	int n;
	int r[1000];
	int l[1000];
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
			
			for( int t = 0 ; t < number ; ++t )
			{
				Problem problem;
				getline( ifs , line1 );
				problem.n = strtoul( line1.c_str() , NULL , 10);

				for( int i = 0 ; i < problem.n ; ++i )
				{
					getline( ifs , line1 );
					int startpos = 0;
					problem.r[i] = strtoul( line1.c_str() , NULL , 10 );
					startpos = line1.find( " " , startpos + 1 );
					problem.l[i] = strtoul( line1.c_str() + startpos , NULL , 10 );
				}
				problemvec.push_back( problem );
			}
			return true;
		}
	}
	return false;
}

bool is_cross( int a1 , int a2 , int b1 , int b2 )
{
	if( a1 < b1 )
	{
		if( a2 > b2 ) return true;
	}else
	{
		if( b2 > a2 ) return true;
	}
	return false;
}

int solve( Problem& pb )
{
	int counter = 0;
	for( int i = 0 ; i < pb.n ; ++i )
	{
		for( int j = i ; j < pb.n ; ++j )
		{
			if( is_cross(pb.r[i],pb.l[i] , pb.r[j],pb.l[j]) )
			{
				counter++;
			}
		}
	}
	return counter;
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
		int s = solve( *itr );
		printf("Case #%d: %d\n",x,s);
		++x;
		++itr;
	}

	return 0;
}
