// alienLanguage.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <string>
#define size size()
using namespace std;

bool c( string str, string patern )
{
	vector< string > v;
	for( int i = 0; i < patern.size; ++i )
	{
		if( patern[i]=='(' )
		{
			string s;
			for( int k = i+1; k < patern.size; ++k )
			{
				if( patern[k] == ')' )
				{
					i = k;
					break;
				}
				s += patern[k];
			}
			v.push_back(s);
		}
		else
		{
			string s ;
			s += patern[i];
			v.push_back( s );
		}
	}
	bool flag = 1;
	for( int j = 0; j < str.size; ++j )
	{
		for( int l = 0; l < v[j].size; ++l )
		{
			if( v[j][l] == str[j] )
				break;
			else
				if( l == v[j].size-1 )
					flag = 0;
		}
		if( flag == 0 )
			break;
	}
	return flag;
}

int check( vector< string > words, string patern )
{
	int cnt = 0;
	for( int i = 0; i < words.size; ++i )
	{
		if( c( words[i],patern) == 1 )
			cnt++;
	}
	return cnt;
}

int main(int argc, char argv[])
{
	int L,D,N;
	vector< string > words;
	string patern;
	freopen( "A-small.in","rt",stdin);
	freopen( "A-small.out","wt",stdout);
	cin >> L >> D >> N;
	for( int i = 0; i < D; ++i )
	{
		string str;
		cin >> str;
		words.push_back(str);
	}
	for( int i = 0; i < N; ++i )
	{
		cin >> patern;
		cout << "Case #"<<(i+1)<<": " << check( words, patern )<<endl; 
	}
	return 0;
}

