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
vector<int> dp;

void check( string& s )
{
	for(int i = 0; i < s.size ;++i)
	{
		switch( s[i] )
		{
		case 'w':dp[0]++;break;
		case 'e':dp[1]+=dp[0],dp[1]%=10000,dp[6]+=dp[5],dp[6]%=10000,dp[14]+=dp[13],dp[14]%=10000;break;
		case 'l':dp[2]+=dp[1],dp[2]%=10000;break;
		case 'c':dp[3]+=dp[2],dp[3]%=10000,dp[11]+=dp[10],dp[11]%=10000;break;
		case 'o':dp[4]+=dp[3],dp[4]%=10000,dp[9]+=dp[8],dp[9]%=10000,dp[12]+=dp[11],dp[12]%=10000;break;
		case 'm':dp[5]+=dp[4],dp[5]%=10000,dp[18]+=dp[17],dp[18]%=10000;break;
		case ' ':dp[7]+=dp[6],dp[7]%=10000,dp[10]+=dp[9],dp[10]%=10000,dp[15]+=dp[14],dp[15]%=10000;break;
		case 't':dp[8]+=dp[7],dp[8]%=10000;break;
		case 'd':;dp[13]+=dp[12],dp[13]%=10000;break;
		case 'j':;dp[16]+=dp[15],dp[16]%=10000;break;
		case 'a':;dp[17]+=dp[16],dp[17]%=10000;break;
		default:;
		}
	}
}

int main(int argc, char* argv[])
{
	freopen( "C-large.in","rt",stdin);
	freopen( "C-large.out","wt",stdout);
	int N;
	cin>>N;
	string str;
	getline(cin,str);
	for( int i = 0; i < N; ++i )
	{
		dp.clear();
		dp.resize(19,0);
		string str;
		getline(cin,str);
		if( str.size < t.size )
			cout<< "Case #"<<i+1<<": "<<"0000"<<endl;
		else
		{
			check(str);
			string res;
			res+=(dp[18]%10)+'0';
			dp[18]/=10;
			res+=(dp[18]%10)+'0';
			dp[18]/=10;
			res+=(dp[18]%10)+'0';
			dp[18]/=10;
			res+=(dp[18]%10)+'0';
			reverse( all(res) );
			cout<< "Case #"<<i+1<<": "<<res<<endl;
		}
	}
	return 0;
}

