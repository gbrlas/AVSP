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
#include <cassert>
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
int cs;
string s[128];
int n;
double soln[128];
double WP[128];
double OWP[128];
double OOWP[128];
int wins[128],loss[128];
int main()
{
	 //freopen( "A.in" , "r" , stdin );
	 freopen( "A-small-attempt0.in" , "r" , stdin );
	 //freopen( "A-large.in" , "r" , stdin );
	 freopen( "A.out" , "w" , stdout );
	 
	int runs;
	s( runs );
	
	while( runs-- )
	{
		printf( "Case #%d:\n" , ++cs );		
		fill( wins , 0 );
		fill( loss , 0 );
		cin >> n;
		for(int i=0;i<n;i++)
		cin >> s[i];
		
		
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		if( s[i][j] != '.' )
		{
			if( s[i][j] == '1' )wins[i]++;
			else loss[i]++;
		}
		
		
		for(int i=0;i<n;i++) WP[i] = (1.0 * wins[i]) / ( wins[i] + loss[i] );
		
		for(int i=0;i<n;i++)
		{
			double sum = 0;
			int c = 0;
			for(int j=0;j<n;j++)
			if( s[i][j] != '.' )
			{
				c++;
				int w,l;
				if( s[i][j] == '1' )
				{
					w = wins[j];
					l = loss[j] - 1;
				}
				else
				{
					w = wins[j] - 1;
					l = loss[j];
				}
				
				sum += (1.0 * w) / (w+l) ;
			}
			OWP[i] = sum / c;
		}
		
		for(int i=0;i<n;i++)
		{
			double sum = 0;
			int c = 0;
			for(int j=0;j<n;j++)
			if( s[i][j] != '.' )
			{
				sum += OWP[j];
				c++;
			}
			OOWP[i] = sum / c;
		}
		for(int i=0;i<n;i++)
		{
		//	printf( "%.6lf %.6lf %.6lf\n" , WP[i] , OWP[i] , OOWP[i] );
		}
		for(int i=0;i<n;i++) soln[i] = 0.25 * WP[i] + 0.5 * OWP[i] + 0.25 * OOWP[i];
		
		for(int i=0;i<n;i++)
		printf( "%.8lf\n" , soln[i] );
	}
}
