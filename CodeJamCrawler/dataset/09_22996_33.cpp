#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int length_of_words  = 0;
	int words_in_laguage = 0;
	int pattern_number = 0;

	vector<string> unique_words;

	string buff;
	scanf("%d %d %d", &length_of_words, &words_in_laguage, &pattern_number );

	char *pch = new char[1024];

	for( int i = 0; i < words_in_laguage; i++ )
	{
		scanf( "%s", pch );
		unique_words.push_back( pch );
	}

	for( int i = 0; i < pattern_number; i++ )
	{
		buff.clear();
		bool match=false;
		int matches=0;
		scanf( "%s", pch );
		buff.append( pch);
		
		//
		for( int j = 0; j < words_in_laguage; j++ )
		{
			match = false;
			int k = 0;
			for( int hop = 0; hop < length_of_words; hop++)
			{
				char c = unique_words[j].at( hop );
				if( buff[k] == '(' )
				{
					while( buff[k] != ')' )
					{
						if( buff[k] == c )
						{
							k = buff.find( ")", k ) + 1;
							match = true;
							break;
						}
						else
							match = false;
						k++;
					}
					if( match != true )
						hop = 2*length_of_words;
				}
				else
				{
					if( buff[k] == c )
					{
						k++;
						match = true;
					}
					else
					{
						hop = 2*length_of_words;
						match = false;
					}
				}
				if( hop == (length_of_words - 1) && match == true )
					matches++;
			}
		}
		printf( "Case #%d: %d\n", i+1, matches );
	}
	return 0;
}

