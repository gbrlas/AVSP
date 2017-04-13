// codejam.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include<fstream>
#include<vector>
#include<string>

class NK
{
public:
	unsigned int n;
	unsigned int k;
};

bool read_problem( const _TCHAR *fname , std::vector<NK>& nkvec )
{
	std::fstream ifs;
	ifs.open( fname );
	std::string line;

	if( ifs.is_open() )
	{
		if( getline( ifs , line ) )
		{
			int number = strtoul( line.c_str() , NULL , 10);
			while( getline( ifs , line ) )
			{
				NK nk;
				nk.n = strtoul( line.c_str()  , NULL , 10);
				nk.k = strtoul( line.c_str() + line.find(" ")  , NULL , 10);
				nkvec.push_back( nk );
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

bool is_chain( unsigned int n , unsigned int k )
{
	unsigned int state = 0;
	unsigned int light = 1;
	for( unsigned int i = 0 ; i < k ; ++i )
	{
		state = (state & ~light) | (state ^ light);
		light = state ^ (state + 1);
	}
	unsigned int all_on = ( ( 1 << ( n + 1 ) ) - 1 );
	if( ( all_on  & light ) == all_on )
	{
		return true;
	}
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	if( argc != 2 )
	{
		printf("invalid argment\n");
		return -1;
	}
	std::vector<NK> nkvec;
	if( !read_problem( argv[1] , nkvec ) )
	{
		return -2;
	}

	std::vector<NK>::iterator itr = nkvec.begin();
	unsigned int x = 1;
	while( itr != nkvec.end() )
	{
		bool bchain = is_chain( itr->n , itr->k );
		if( bchain )
		{
			printf("Case #%d: ON\n",x);
		}else
		{
			printf("Case #%d: OFF\n",x);
		}
		++x;
		++itr;
	}

	return 0;
}

