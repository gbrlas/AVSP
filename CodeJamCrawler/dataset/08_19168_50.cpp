#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<string> engine;
vector<int> query;
int dp[1001][101];
int S, Q;

int rek( int p, int se ) {
   if( dp[p][se] != -1 ) return dp[p][se];
   if( p == Q ) return 0;

   if( p == Q-1 || query[p+1] != se ) return rek( p+1, se );

   int ret = 1500;    
   for( int i = 0; i < S; ++i ) 
      if( i != query[p+1] ) 
         ret = min( ret, rek( p+1, i ) );

   return dp[p][se] = ret+1;
}

int solve() {
   int ret = 1500;
   for( int i = 0; i < S; ++i )
      if( i != query[0] ) 
         ret = min( ret, rek( 0, i ) );
   return ret;
}

int main() {
   int TP;
   char tmp[150];
   
   scanf( "%d", &TP );

   for( int tp = 0; tp < TP; ++tp ) {
      engine.clear();
      query.clear();
      memset( dp, -1, sizeof dp );

      scanf( "%d\n", &S );
      for( int i = 0; i < S; ++i ) {
         gets( tmp );
         engine.push_back( tmp );
      }

      scanf( "%d\n", &Q );
      for( int i = 0; i < Q; ++i ) {
         gets( tmp );
         query.push_back( find( engine.begin(), engine.end(), string( tmp ) ) - engine.begin() );
      }

      printf( "Case #%d: %d\n", tp+1, solve() );
   }

   return 0;
}
