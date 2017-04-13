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

const double eps = 1e-9;

int b[ 80000 ][26] ;
int last = 0;
bool t [ 80000 ];


void vbor( string s )
{
  int v = 0;
  forn( i , (int)s.size() )
  {
    if ( b [ v ][ s [ i ] - 'a' ] <= 0 )
    {
      last ++;
      b [ v ][ s [ i ] - 'a']= last ;
      v = last;
    } else v = b [ v ][ s [ i ] - 'a' ];
  }
  t [ v ] = true ;
}

int l , d , n ;
string s ;

bool check( int pos )
{
  while ( pos < (int)s.size() )
  {
    if ( s [ pos ] != ')' && s [ pos ] != '(') return true ;
    else pos ++;
  }
}

int calc ( int pos , int v )
{
  cerr << pos << " " << v << endl;
  if ( check(pos) && t [ v ] ) return 1 ; 
  int l = pos ;
  if( s [ l ] == ')' ) l ++;
  int ans = 0;
  int r = l ;

  if ( s [ l ] == '(' ) 
  {
    l ++;
    while ( s [ r ] != ')' ) r ++;
    r --;
  }
  for ( int i = l ; i <= r ; i ++ )
  {
    if ( b [ v ] [ s [ i ] - 'a' ] > 0 ) ans += calc ( r + 1 , b [ v ] [ s [ i ] - 'a' ] );
  }
  return ans ;
}

int main()
{
  freopen("a.in" ,"r" , stdin );
  freopen ("a.out", "w", stdout );
  freopen ("log" , "w" , stderr );
  scanf ("%d%d%d\n", &l,  &d , &n );
  memset ( b , 0 , sizeof ( b ) ) ;
  memset ( t , 0 , sizeof ( t )) ;
  forn ( i , d )
  {
     getline ( cin , s );
     scanf ("\n" );
     vbor( s);
  }
  forn ( i , last )
  {
    cerr << i << " " << t [ i ]<< endl;
    forn ( j , 26 )
      cerr << b [ i ] [ j ] <<" " ;
    cerr << endl;
  }

  forn ( i , n )
  {
    getline ( cin , s );
    scanf ("\n" );
    cerr << s << endl;
    cout << "Case #" << i + 1 << ": " << calc (0, 0 ) << endl;
  }      
}
