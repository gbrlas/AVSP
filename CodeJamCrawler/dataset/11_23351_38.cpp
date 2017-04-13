#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
using namespace std ;  

#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ(x) (int)x.size()
#define LEN(x) (int)x.length()
typedef long long int64  ; 
typedef pair<int,int> PII ;  

int  x, s, r, t , n ;    
const int maxn = 1000000+100 ; 
int data[ maxn ]; 
int main () { 
    
     freopen("AI.txt" , "r", stdin) ; 
    freopen("AO.txt",  "w", stdout ) ;  
    int T ;    
    scanf ("%d", &T) ; 
    for( int Cas = 1 ; Cas <= T ; ++Cas ) { 
         
         scanf ("%d%d%d%d%d", &x, &s, &r, &t, &n) ; 
         
         fill( data, data + x + 1, 0 ); 
         for( int i = 1 ; i <= n ; ++i) { 
              int  u , v ; 
              cin >> u >> v ; 
              int sp ; 
              cin>> sp ; 
              for( int j =  u ;  j <  v ; ++j) { 
                   
                       data[   j ] = sp ;  
              } 
          } 
          sort( data , data + x   ) ;   
          double ans = 0 ;
          double tt =  t ; 
          for( int i =  0;  i <  x; ++i) { 
                
                if(  fabs( tt ) > 1e-9 )  { 

                     if(  tt * ( r  + data[ i ] )  > 1.0 ) { 

                          tt -=  1.0/ ( r + data[ i ] ) ; 
                          ans +=   1.0/ ( r + data[ i ] ) ;  
                     } 
                     else { 
                          
                          double tmp =  tt * ( r + data[i] ) ;  
                          
                          ans += tt ; 
                          tt =  0 ;
                          ans +=  ( 1. - tmp ) / ( s + data[i] ) ; 
                     } 
                 } 
                 else ans +=  1. / ( s + data[i] ) ; 
          }
          cout << "Case #"<<Cas <<": "; 
          printf ("%.10lf\n", ans ) ; 
     }
     return 0; 
}
               
    
    
    
