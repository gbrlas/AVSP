#include <iostream> 
#include <map> 
#include <vector> 
#include <string> 
#include <set> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <queue> 
#include <list> 
#include <limits> 
#include <stack> 
#include <sstream> 
#include <fstream> 
#include <ctime> 
#include <cstdlib> 
#include <complex> 
#include <cctype> 
#include <iomanip> 
#include <functional> 
#include <cstring> 
using namespace std; 
 
typedef long long int64 ; 
typedef unsigned long long uint64 ; 
 
#define two(X) (1<<(X))  
#define twoL(X) (((int64)(1))<<(X)) 
#define PB push_back 
#define SZ(X) ((int)(X.size())) 
#define LEN(X) ((int)(X.length())) 
#define MP(X,Y) make_pair(X,Y)  
#define foreach(c , itr) for(__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); ++itr)

#define INPUT(s) freopen(s,"r",stdin); 
#define OUTPUT(s) freopen(s,"w",stdout);

priority_queue < pair<int,int>   > que ;
int d[10000+100], l[10000+100] ; 
bool used[10000+100] ;   
int dd[10000+100] ; 
int e ; 
int main (){ 
     int  T ;  
     INPUT("A-small-attempt0.in") ; 
     OUTPUT("A-small-attempt0.out") ;
     cin >> T  ;  
     for(int Cas = 1;  Cas <= T ; ++Cas ){  

         int n ;  cin >> n ;   
         for(int i=1; i<= n  ; ++i){  
            scanf ("%d%d",d+i,l+i) ; 
         }    
         while(!que.empty()) que.pop() ; 
         memset(used, 0 , sizeof(used)) ; 
         memset( dd, 0 , sizeof(dd)) ;  
         used[1] =1 ;  
         scanf ("%d",&e) ;  
         que.push( MP( 1, min(l[1] , d[1]) ) ) ;   
         dd[1] = min( l[1], d[1]) ;  
         bool ans = 0 ; 
         while( !que.empty()){    
                 int id = que.top().first,  len = que.top().second ;    
                 if(  d[id] + len >=e ){ 
                     ans = 1 ; 
                     break ; 
                 }
                 que.pop() ;  
                 for(int j=id+1;  j <= n;  ++j){  
                     if( d[ j ] <= d[id] + len   ){   
                         if( dd[ j] >=  min( d[j]-d[id], l[j] ) )  continue ; 
                         que.push(MP( j,  min( d[j] - d[id] , l[j] ) ) ) ; 
                         if( d[ j ] +min ( d[j]-d[id] , l[j] ) >= e ) { 
                             ans =1 ;   
                             dd[j] = max( dd[j] , min(  d[j] - d[id] , l[j] ) ) ; 
                             break; 
                         }
                     }
                 }
                 if( ans ) break ; 
         }  
         cout <<"Case #"<<Cas<<": "<< (ans?"YES":"NO")<<endl ; 
     } 
     return 0; 
}




             
         
