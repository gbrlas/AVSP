#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;


vector< pair<int, int> > ta, tb;
int na, nb, t, sola, solb;

int moguce( int sa, int sb ) {
   vector<int> ka( na+1 );
   vector<int> kb( nb+1 );

   ka[0] = sa;
   kb[0] = sb;
   int posa, posb;
   posa = posb = 0;
   
   for( int i = 0; i < na+nb; ++i ) 
      if( ta[posa].first < tb[posb].first ) {
         if( !ka[posa] ) return 0;
         for( int j = 0; j < nb; ++j ) 
            if( ta[posa].second + t <= tb[j].first ) {
               kb[j]++;
               break;
            }
         ka[posa+1] += ka[posa]-1;
         posa++;
      }
      else {
         if( !kb[posb] ) return 0;
         for( int j = 0; j < na; ++j ) 
            if( tb[posb].second + t <= ta[j].first ) {
               ka[j]++;
               break;
            }
         kb[posb+1] += kb[posb]-1;
         posb++;
      }

   return 1;
}

void solve() {
   sola = 100000;
   solb = 100000;

   ta.push_back( make_pair( 10000, 10000 ) );
   tb.push_back( make_pair( 10000, 10000 ) );

   for( int i = 0; i <= na; ++i ) 
      for( int j = 0; j <= nb; ++j ) 
         if( moguce( i, j ) && i+j < sola+solb ) {
            sola = i;
            solb = j;
         }
}

int main() {
   int TP;
   
   scanf( "%d", &TP );
   for( int itp = 0; itp < TP; ++itp ) {       
      ta.clear();
      tb.clear();
      scanf( "%d%d%d", &t, &na, &nb );
      
      for( int i = 0; i < na; ++i ) {
         int shh, smm, ehh, emm;
         scanf( "%d:%d %d:%d", &shh, &smm, &ehh, &emm );
         ta.push_back( make_pair( shh*60 + smm, ehh*60 + emm ) );
      }

      for( int i = 0; i < nb; ++i ) {
         int shh, smm, ehh, emm;
         scanf( "%d:%d %d:%d", &shh, &smm, &ehh, &emm );
         tb.push_back( make_pair( shh*60 + smm, ehh*60 + emm ) );
      }
      
      sort( ta.begin(), ta.end() );
      sort( tb.begin(), tb.end() );
      solve();
      printf( "Case #%d: %d %d\n", itp+1, sola, solb );
      
   }
   
   return 0;
}
