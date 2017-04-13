// codejam_1A.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include<fstream>
#include<vector>
#include<string>

typedef struct
{
	int n;
	int k;
	int board[50][50];
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
				problem.n = strtoul( line1.c_str() , NULL , 10 );
				startpos = line1.find( " " , startpos + 1 );
				problem.k = strtoul( line1.c_str() + startpos , NULL , 10 );

				for( int i = 0 ; i < problem.n ; ++i )
				{
					getline( ifs , line1 );
					for( int j = 0 ; j < problem.n ; ++j )
					{
						if( *(line1.c_str()+j) == '.' )
						{
							problem.board[i][j] = 0;
						}else if(  *(line1.c_str()+j) == 'R' )
						{
							problem.board[i][j] = 1;
						}else if(  *(line1.c_str()+j) == 'B' )
						{
							problem.board[i][j] = 2;
						}else
						{
							//invalid
						}
					}
				}
				problemvec.push_back( problem );
			}
			return true;
		}
	}
	return false;
}

bool check( int turn , int n , int i , int j , int board[50][50] , int i_p , int j_p , int k )
{
	for( int s = 0 ; s < k ; ++s )
	{
		if( i >= n || j >= n || i < 0 || j < 0 ) return false;
		if( board[i][j] != turn )
		{
			return false;
		}
		i+=i_p;
		j+=j_p;
	}
	return true;
}

__int64 solve( Problem& pb )
{

	int pos;
	for( int i = 0 ; i < pb.n; ++i )
	{
		pos = pb.n - 1;
		for( int j = pb.n - 1 ; j >= 0 ; --j )
		{
			if( pb.board[i][j] != 0 )
			{
				if( pos != j )
				{
					pb.board[i][pos] = pb.board[i][j];
					pb.board[i][j] = 0;
					
				}
				--pos;
			}
		}
	}
	bool rb[2];
	rb[0] = false;rb[1]=false;
	for( int i = 0 ; i < pb.n; ++i )
	{
		for( int j = 0 ; j < pb.n ; ++j )
		{
			if( pb.board[i][j] != 0 )
			{
				if( check( pb.board[i][j] , pb.n , i , j , pb.board , 1 , 0 , pb.k ) ) rb[pb.board[i][j]-1] = true;
				if( rb[0] && rb[1] ) return 2;
				if( check( pb.board[i][j] , pb.n , i , j , pb.board , 0 , 1 , pb.k ) ) rb[pb.board[i][j]-1] = true;
				if( rb[0] && rb[1] ) return 2;
				if( check( pb.board[i][j] , pb.n , i , j , pb.board , -1 , 1 , pb.k ) ) rb[pb.board[i][j]-1] = true;
				if( rb[0] && rb[1] ) return 2;
				if( check( pb.board[i][j] , pb.n , i , j , pb.board , 1 , 1 , pb.k ) ) rb[pb.board[i][j]-1] = true;
				if( rb[0] && rb[1] ) return 2;
			}
		}
	}
	if( rb[0] && !rb[1] ) return 3;
	if( !rb[0] && rb[1] ) return 4;
	return 1;
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
		__int64 s = solve( *itr );
		switch(s){
			case 1:
				printf("Case #%d: Neither\n",x);
			break;
			case 2:
				printf("Case #%d: Both\n",x);
			break;
			case 3:
				printf("Case #%d: Red\n",x);
			break;
			case 4:
				printf("Case #%d: Blue\n",x);
			break;
		}
		++x;
		++itr;
	}

	return 0;
}
