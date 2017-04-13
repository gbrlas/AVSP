// WTCJ.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define size size()
#define all(res) res.begin(),res.end()
using namespace std;

string t = "welcome to code jam";
int cnt = 10000;

void rec( string& s, int i, int k )
{
	if( k == t.size )
	{
		cnt++;
		return;
	}
	if( i == s.size )
		return;
	for( int j = i; j < s.size; ++j )
	{
		if( s[j] == t[k] )
			rec(s,j+1,k+1);
	}
}

void check( string& s )
{
	int k = 0;
	for(int i =0; i < s.size-t.size+1;++i)
	{
		if( s[i] == t[0] )
			rec(s,i+1,1);
	}
}

int main(int argc, char* argv[])
{
	freopen( "C-small.in","rt",stdin);
	freopen( "C-small.out","wt",stdout);
	int N;
	cin>>N;
	string str;
	getline(cin,str);
	for( int i = 0; i < N; ++i )
	{
		string str;
		cnt = 0;
		getline(cin,str);
		if( str.size < t.size )
			cout<< "Case #"<<i+1<<": "<<"0000"<<endl;
		else
		{
			check(str);
			string res;
			res+=(cnt%10)+'0';
			cnt/=10;
			res+=(cnt%10)+'0';
			cnt/=10;
			res+=(cnt%10)+'0';
			cnt/=10;
			res+=(cnt%10)+'0';
			reverse( all(res) );
			cout<< "Case #"<<i+1<<": "<<res<<endl;
		}
	}
	return 0;
}

