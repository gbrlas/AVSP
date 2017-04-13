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
	vector<string> exists_lines;
	vector<string> mkdir_lines;
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

				int startpos = 0;
				getline( ifs , line1 );
				int e = strtoul( line1.c_str() , NULL , 10 );
				startpos = line1.find( " " , startpos + 1 );
				int m = strtoul( line1.c_str() + startpos , NULL , 10 );

				for( int i = 0 ; i < e ; ++i )
				{
					getline( ifs , line1 );
					problem.exists_lines.push_back( line1 );
				}
				for( int i = 0 ; i < m ; ++i )
				{
					getline( ifs , line1 );
					problem.mkdir_lines.push_back( line1 );
				}
				problemvec.push_back( problem );
			}
			return true;
		}
	}
	return false;
}



int solve( Problem& pb )
{
	//e 
	vector< std::string::iterator > itr;
	int en = pb.exists_lines.size();
	set<string> en_path;
	for( int i = 0 ; i < en ; ++i )
	{
		int pos = 0;
		int line_size = pb.exists_lines[i].size();
		while( pos <= line_size )
		{
			if( pos != 0 && ( pb.exists_lines[i][pos] == '/' || pb.exists_lines[i][pos] == '\0' ) )
			{
				string n( pb.exists_lines[i].c_str() , pos );
				en_path.insert( n );
			}
			++pos;
		}
	}

	int counter = 0;
	int mn = pb.mkdir_lines.size();
	for( int i = 0 ; i < mn ; ++i )
	{
		int pos = 0;
		int line_size = pb.mkdir_lines[i].size();
		while( pos <= line_size )
		{
			if( pos != 0 && ( pb.mkdir_lines[i][pos] == '/' || pb.mkdir_lines[i][pos] == '\0' ) )
			{
				string n( pb.mkdir_lines[i].c_str() , pos );
				if( en_path.find( n ) == en_path.end() )
				{
					// not found
					counter++;
					en_path.insert( n );
				}
			}
			++pos;
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
