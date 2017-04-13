#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define SIZE( X ) ( ( int ) ( X.size() ) )
#define LENGTH( X ) ( ( int ) ( X.length() ) )
#define MP( X, Y ) make_pair( X, Y )

#define two( X ) ( 1<<( X ) )
#define twoL( X ) ( ( ( long long ) ( 1 ) ) << ( X ) )
#define contain( S, X ) ( ( ( S ) & two( X ) ) != 0 )
#define containL( S, X )  ( ( ( S ) & twoL( X ) ) != 0 )

const double pi = acos( -1.0 );
const double eps = 1e-11;

template < class T > inline T dif( T a, T b ){ if( a > b ){ return a - b ;}else{ return b - a; } };
template < class T > inline T sqare( T x ){ return x * x; }
template < class T > inline T lowbit( T n ) { return ( n ^ ( n - 1 ) ) & n; }
template < class T > inline T countbit( T n ) { return ( n == 0 ) ? 0 : ( 1 + countbit( n & ( n - 1 ) ) ); }
template < class T > inline T gcd( T a, T b )
{ if( a < 0 ){ return gcd( -a, b ); }; if( b < 0 ){ return gcd( a, -b ); } return ( b == 0 ) ? a : gcd( b, a % b ); }
template < class T > inline T lcm( T a, T b )
{ if( a < 0 ){ return lcm( -a, b ); }; if( b < 0 ){ return lcm( a, -b ); } return a * ( b / gcd( a, b ) ); }
template<class T> inline bool isPrimeNumber(T n)
{ if( n <= 1 )return false; for( T i = 2; i * i <= n; i++ )if( n % i == 0 ) return false; return true; } 
double dist( double x1, double y1, double x2, double y2 ){ return sqrt( sqare( x1 - x2 ) + sqare( y1 - y2 ) ); }
double disR( double x1, double y1, double x2, double y2 ){ return sqare( x1 - x2 ) + sqare( y1 - y2 ); }
bool isUpperCase( char c ){ return c >= 'A' && c <= 'Z'; }
bool isLowerCase( char c ){ return c >= 'a' && c <= 'z'; }
bool isLetter( char c ){ return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z'; }
bool isDigit( char c ){ return c >= '0' && c <= '9'; }
template < class T > inline T power( T a, T n ){ T ans = 1; T tmp = a; while( n > 0 ){ if( n & 1 ){ ans *= tmp; }; tmp *= tmp; n = n>>1; } return ans; }

#define N 41

int a[N][N];

char s[N][N];

int num[N], mark[N];

int main(){
    
    freopen( "A-large.in", "r", stdin );
    freopen( "alarge.out.txt", "w", stdout );
    
    int Tc;
    
    scanf( "%d", &Tc );
    
    for( int tc = 1; tc <= Tc; tc++ ){
         
         int n; 
         
         scanf( "%d", &n );
         
         for( int i = 0; i < n; i++ ){
              scanf( "%s", s[i] );
         }
         
         for( int i = 0; i < n; i++ ){
              num[i] = 0;
              for( int j = 0; j < n; j++ ){
                   if( s[i][j] == '1' ){
                       num[i] = j;
                   }
              }
//              mark[i] = true;
         }
         
         int ans = 0;
         
         for( int i = 0; i < n ;i++ ){
              for( int j = i; j < n; j++ ){
                   if( num[j] <= i ){
                       ans += j - i;
                       
                       for( int k = j; k > i; k-- ){
                            num[k] = num[k - 1];
                       }
                       break;
                   }
              }
         }
         
         printf( "Case #%d: %d\n", tc, ans );
    }
    
    return 0;
}

         
         
