#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <cmath>

using namespace std ;  

#define F first 
#define S second
#define MP make_pair
#define SZ(x)  (int)x.size()
#define LEN(x) (int)x.length()
#define PB push_back

typedef long long int64 ; 
typedef pair<int,int>  PII ; 
int main () { 
    freopen("C.in","r", stdin) ; 
    freopen("C.out","w", stdout) ; 
    
     int  T  ; 
     scanf ("%d", &T) ;  
    // system("pause") ; 
     for( int Cas = 1 ; Cas <= T ; ++Cas ) { 
          int  n  ; 
          vector<int> adj   ;
          int f  =0 ; 
          int sum = 0 ; 
          scanf ("%d", &n) ; 
          for ( int i=  0;   i < n ; ++i) {
              int u ; scanf ("%d", &u) ;
              adj.PB(  u  ) ;  
              f ^= u  ; 
              sum += u  ; 
           }  
           cout <<"Case #"<<Cas <<": " ; 
           sort( adj.begin() , adj.end() ) ; 
           if( f )   puts("NO"); 
           else { 
                cout << sum - adj[0] <<endl ;
           }  
      }
      return 0; 
}
               
