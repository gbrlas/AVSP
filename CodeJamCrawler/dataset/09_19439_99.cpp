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
const int inf = 10000000;

int a [ 100 ] [ 100 ] ;
pii t [ 100 ] [ 100 ] ;
int tt;
int c [ 100 ] [ 100 ] ;
int h , w ;

pii go ( int ii , int jj )
{
  cerr << ii << " " << jj << endl;
  if ( t [ ii ] [ jj ] != mp ( -1 , -1 ) ) return t [ ii ] [ jj ] ;
  pii tans ;
  int minl= inf; 
  pii tv = mp ( ii - 1, jj );
//  cerr << "lfdh" << tv.x << " " << tv.y << endl;
  if ( tv.x >= 0 ) 
  {
    minl = a [ tv.x ] [ tv.y ] ;
    tans = tv;
  }
//  cerr << minl << endl;
  tv = mp ( ii , jj - 1 );
  if ( tv.y >= 0 && a [ tv.x ] [ tv.y ] < minl )
  {
    minl = a [ tv.x ] [ tv.y ] ;
    tans = tv;
  }
//    cerr << minl << endl;
  tv = mp ( ii , jj + 1 );
  if ( tv.y < w && a [ tv.x ] [ tv.y ] < minl )
  {
    minl = a [ tv.x ] [ tv.y ] ;
    tans = tv;
  }
//    cerr << minl << endl;
  tv = mp ( ii + 1 , jj );
  if ( tv.x < h && a [ tv.x ] [ tv.y ] < minl )
  {
    minl = a [ tv.x ] [ tv.y ] ;
    tans = tv;
  }
//    cerr << minl << endl;
//  cerr << "ans  "<< tans.x << " " << tans.y << endl;
//  cerr << minl << endl;
  if ( minl >= a [ ii ] [ jj ]) 
  {
    t [ ii ] [ jj ] = mp ( ii , jj );
    return mp ( ii , jj );
  } else 
  {
    t [ ii ] [ jj ] = go ( tans.x , tans.y );
    return t [ ii ] [ jj ] ;
  }

}

int main()
{
  freopen("b.in" ,"r" , stdin );
  freopen ("b.out", "w", stdout );
  freopen ("log" , "w" , stderr );
  scanf ("%d" , &tt );
  forn ( g , tt )
  {
    cerr << g << endl;
    scanf ("%d%d" , &h , &w );
    memset ( a , 0 , sizeof ( a ) ) ;
    memset ( t , -1 , sizeof ( t ) ) ;
    forn ( i , h )
      forn ( j , w )
        scanf ("%d", &a [ i ] [ j ] );
    forn ( i , h )
      forn ( j , w )
        if ( t [ i ] [ j ] != mp ( -1 , -1 ) ) continue ; else
        t [ i ] [ j ] = go ( i , j );
    int k = 0;
    memset ( c , -1 , sizeof ( c )) ;
    forn ( i , h )
      forn ( j , w )
        if ( c [ t [i ] [ j ].x ] [ t [ i ] [ j ].y ] == -1 )
        {
          c [ t [ i ] [ j].x ] [ t [ i ] [j] .y ] = k ;
          k ++;
        }
    cout << "Case #" << g + 1 << ":" << endl;

    forn ( i , h )
    {
      forn ( j , w ) 
        cerr <<"(" << t [ i ] [j ].x << " " << t [ i ] [ j ].y << ")" << " ";
      cerr << endl;
    }

    forn ( i , h )
    {
      forn ( j , w )
        printf ("%c " , 'a' + c [ t [ i ] [ j].x ] [ t [ i ] [ j ].y ] );
      printf ("\n" );
    }
  }

}
