#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <cstring>
#define oo (int)1e9
#define fill( a , v ) memset( a , v , sizeof (a) )
#define bits( x ) __builtin_popcount( x )
#define gcd( a , b ) __gcd( a, b )
#define lcm( a , b ) (a/gcd( a, b ) ) * b
#define s(n)scanf( "%d" , &n )
#define add push_back
const int mxn = 100000 + 10;
typedef unsigned long long ll;
#define pii pair<double,double>
using namespace std;
string s;
int n;
int cs;
char a[26][26];
bool clear[26][26];
int in[26];

int main()
{
	 //freopen( "B.in" , "r" , stdin );
	 //freopen( "B-small-attempt0.in" , "r" , stdin );
	 freopen( "B-large.in" , "r" , stdin );
	 freopen( "B.out" , "w" , stdout );
	 
	int runs;
	
	cin >> runs;
	
	while( runs-- )
	{
		for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
		a[i][j] = clear[i][j] = in[i] = 0;
		cin >> n;
		while( n-- )
		{
			cin >> s;
			a[s[0]-'A'][s[1]-'A'] = a[s[1]-'A'][s[0]-'A'] = s[2];
		}
		
		cin >> n;
		while( n-- )
		{
			cin >> s;
			clear[s[0]-'A'][s[1]-'A'] = clear[s[1]-'A'][s[0]-'A'] = 1;
		}
		cin >> n;
		cin >> s;
		vector<char>list;		
		for(int i=0;i<s.size();i++)
		{
			list.push_back( s[i] );
			in[ s[i] - 'A' ]++;
			if( list.size() > 1 )
			{
				bool b = 1 , cleared = 0;
				
				while( list.size() > 1 )
				{
					char first = list[list.size()-2];
					char second = list[list.size()-1];
					int j = first - 'A';
					int k = second - 'A';
					
					if( a[j][k] )
					{
						in[j]--;
						in[k]--;
						list.pop_back();
						list.pop_back();
						b = 0;
						list.push_back( a[j][k] );
						in[ a[j][k] - 'A' ]++;
					}				
					else break;
				}
				
				b = 1;
				if( list.size() > 1 )				
				for(int j=0;j<26 && b;j++)
				if( in[j] )
				for(int k=0;k<26 && b ;k++)
				if( in[k] && clear[j][k] )
				{
					b = 0;
					for(int p=0;p<list.size();p++)
					in[ list[p] - 'A' ]--;
					list.clear();
					cleared = 1;
				}
			}
			//for(int j=0;j<list.size();j++)cout << list[j] << " " << in[list[j]-'A'] << " ";;cout << endl;
		}
		printf( "Case #%d: " , ++cs );
		if( list.size() == 0 )puts( "[]" );
		else
		{
			printf( "[" );
			for(int i=0;i<list.size()-1;i++)
			printf( "%c, " , list[i] );
			printf( "%c]\n" , list[list.size()-1] );
		}
		
	}
}

