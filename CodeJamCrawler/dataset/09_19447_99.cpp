#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <ctime>

using namespace std;

#define forn(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(a) a.begin() ,a.end()

typedef long long int64;
typedef pair <int , int > pii;
typedef pair <double , double > pdd;
typedef vector<int > vi;


const string gcj = "welcome to code jam";
const double eps = 1e-9;
const int base = 10000;

int t [ 500 ] [ 19 ] ;

int n ;
string s ;

int main()
{
  freopen("c.in" ,"r" , stdin );
  freopen ("c.out", "w", stdout );
  freopen ("log" , "w" , stderr );
  scanf ("%d\n" , &n );
  forn ( g , n )
  {
    getline( cin , s );
    scanf ("\n");
    cerr << s << endl;
    memset ( t , 0 , sizeof ( t ) ) ;
    forn ( i , (int)s.size() )
      forn( k , 19 )
      {
        if ( s [ i ] == gcj [ k ] )
        
        {
          if ( k == 0 ) t [ i ][ k ] = 1 ;
            else 
          forn ( j , i )
            t [ i ] [ k ] = (t [i ] [ k ] + t [ j ] [ k - 1 ]) % base;
        }
      }
    forn ( i , (int)s.size() )
    {
      cerr << s [ i ] << " " ;
      forn ( j , 19 )
        cerr << t [ i ] [ j ] << " " ;
      cerr << endl;
    } 
    int ans = 0;
    forn ( i , (int)s.size() )
      ans = ( ans + t [i ] [ 18 ] ) % base;
    cout << "Case #" << g + 1 << ": ";
    if ( ans <1000 ) cout << "0";
    if ( ans < 100 ) cout << "0" ;
    if ( ans < 10 ) cout << "0";
    cout << ans << endl;
  }
}
