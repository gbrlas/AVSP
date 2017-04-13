#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std ; 

#define PB push_back
#define MP make_pair
#define SZ(x) (int)x.size()
#define LEN(x) (int)x.length()
#define F first
#define S second

typedef long long int64 ; 
typedef pair<int,int>  PII ; 

int64 n ,pd, pg ; 
int main ()  { 
     freopen("AA.in","r", stdin); 
     freopen("AA.out","w", stdout) ; 

      int T ; 
      scanf ("%d", &T) ;    
      for( int Cas= 1 ;Cas <= T ; ++Cas ) { 
           
          scanf ("%lld%lld%lld", &n, &pd, &pg ) ;  
          
          int64 x = -1  ,y =-1 ; 
          for( int64 i= 0; i <=  min( 100LL, n ); ++i) { 
              
               for( int64 j= max( 1LL,  i); j <= min( n, 10000LL);  ++j){ 

                    if( 100LL*  i  %j ==0 &&  100LL*  i  / j == pd ) {  
                          x= i, y = j ; 
                          break; 
                    } 
               }
               if( x !=-1 ) break;  
          } 

          //cout << x <<" "<<y <<endl; 
          cout <<"Case #"<<Cas<<": " ; 
          if( x == -1 ) { 
              puts("Broken"); 
              continue ; 
          }  

          int64 xx=-1, yy=-1; 

                    for( int64 i= x; i <=  100LL; ++i) { 
                         
               for( int64 j= 10000LL; j >= max(1LL, x ) ;  --j){ 
                    if( j -i  < y -x ) break ;
                    if( 100LL*  i  %j ==0 &&  100LL*  i  / j == pg ) {  
                          xx= i, yy = j ; 
                          break; 
                    } 
               }
               if( xx !=-1 ) break;  
          } 
           //cout << xx <<" "<< yy <<endl; 
                    if( xx == -1 ) { 
              puts("Broken"); 
              continue ; 
          }  

          puts("Possible") ; 
      }
      return 0; 
}
          
      
    
    
