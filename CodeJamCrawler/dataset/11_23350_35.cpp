#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std ; 

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define SZ(x) (int)x.size()
#define LEN(x) (int)x.length() 

typedef long long int64 ; 
typedef pair<int,int> PII ; 


vector<double> oor ; 
int n , d; 

bool chk ( double  now ){ 
     double l= oor[0] - now ;
     for( int i= 1; i <SZ( oor ) ; ++i){ 

          if( oor[i] - ( l + d ) < 0 ){ 
              if( fabs( l + d  - oor[i] ) >  now ) return false; 
              else l = l + d ; 
          } 
          else { 
                l = max(  l + d ,  oor[ i] - now ) ;  
          } 
     }
     return true; 
}
int main (){ 

    int T ;
    freopen("BI.txt","r" ,stdin);
    freopen("BO.txt","w", stdout); 
    scanf ("%d", &T) ;
    for( int Cas = 1; Cas <= T ; ++Cas) { 
         
         scanf ("%d%d", &n, &d) ; 
         oor.clear() ; 

         for( int i=0 ;i <n ; ++i){ 
              double x ;
              int cc ;
              cin >> x >>cc ;
              for( int j= 0; j <cc; ++j) oor.PB( x ); 
         }

         sort( oor.begin() , oor.end() ) ; 
         
         double l=0, r = 1000000000000000.;
         int cnt =0 ; 
         while( fabs( l -r ) > 1e-9){
                ++cnt ;
                double m = ( l + r ) / 2 ; 
                if( chk( m ) )  r = m ;
                else l= m ;
                if( cnt >100000000) break; 
         }
         cout <<"Case #"<<Cas <<": ";
         printf ("%.10lf\n", l ) ; 
    } 
    return 0; 
}
                           
                             
                             
         
