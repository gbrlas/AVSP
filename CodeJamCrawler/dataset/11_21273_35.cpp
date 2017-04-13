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

int cs;
int n,a[1024];

int main()
{
	 //freopen( "C.in" , "r" , stdin );
	 freopen( "C-small-attempt2.in" , "r" , stdin );
	 freopen( "C.out" , "w" , stdout );
	 
	int runs;
	s( runs );
	
	while( runs-- )
	{
		s(n);
		for(int i=0;i<n;i++)s( a[i] );
		
		int mx = -1;
		for(int mask=1;mask<(1<<n)-1;mask++)
		{
			int sum1 = 0 , sum2 = 0, fsum = 0;
			for(int i=0;i<n;i++)
			if( mask & (1<<i) )
			sum1 ^= a[i], fsum += a[i];
			else sum2 ^= a[i];
			
			if( sum1 == sum2 )
			{
				//cout << mask << " " << fsum << endl;
				mx = max( mx , fsum );
			}
		}
		printf( "Case #%d: " , ++cs );
		if( mx == -1 )puts( "NO" );
		else printf( "%d\n" , mx ); 
	}
}
