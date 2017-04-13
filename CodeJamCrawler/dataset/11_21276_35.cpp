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
int n;
int C,D;
double arr[128];
double a[128];

bool ok( double mov )
{
	for(int i=0;i<n;i++) a[i] = arr[i];
	
	a[0] -= mov;
	
	for(int i=1;i<n;i++)
	{
		if( a[i-1] + mov <= a[i] - mov && ( a[i] - mov - a[i-1] - mov ) >= D )
			a[i] -= mov;
		else if( fabs ( ( a[i-1] + D ) - a[i] ) <= mov )
		{
			a[i] = a[i-1] + D;
		}
		else
		{
			if( a[i] - mov >= a[i-1] ) a[i] -= mov;
			else if( a[i] + mov >= a[i-1] ) a[i] += mov;
		}
	}
	bool ok = 1;
	for(int i=1;i<n;i++) ok &= a[i] - a[i-1] >= D;
	return ok;
}

int main()
{
	 //freopen( "B.in" , "r" , stdin );
	 freopen( "B-small-attempt0.in" , "r" , stdin );
	 //freopen( "B-large.in" , "r" , stdin );
	 freopen( "B.out" , "w" , stdout );
	 
	int runs;
	s( runs );
	
	while( runs-- )
	{
		n = 0;
		cin >> C >> D;
		for(int i=0;i<C;i++)
		{
			int p,v;
			cin >> p >> v;
			while( v-- )
			arr[n++] = p;
		}
		double low = 0, high = 4e3;
		
		while( fabs(low-high) > 1e-7 )
		{
			double mid = ( low + high ) / 2.0;
			if( ok(mid) )high = mid;
			else low = mid;
		}
		//for(int i=0;i<n;i++) cout << a[i] << " " ; cout << endl;
		//cout << ok( 1.5 ) << endl;
		//for(int i=0;i<n;i++) cout << a[i] << " " ; cout << endl;
		double ans = low;
		printf( "Case #%d: %.8lf\n" , ++cs , ans );		
	}
}
