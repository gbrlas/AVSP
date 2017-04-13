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

int px ,  py ,  tx, ty  ;  
int nowt ; 
int n ; 
int main () { 
     freopen( "A.in","r" , stdin) ; 
     freopen( "A.out", "w", stdout) ; 

    int T ; 
    scanf ("%d", &T) ;  
    
    for( int Cas= 1 ;Cas <= T ; ++Cas ) { 
         
        tx= 0 , ty = 0 , px = 1 , py =1  ;
        nowt =0 ; 
        scanf ("%d", &n) ;  
       
        for( int i= 0 ;i < n  ; ++i) {
             char s[10] ; 
             int to ; 
             scanf ("%s%d", s, &to) ; 
             if( s[0] =='O' ) {  
                 
                 if( nowt >= tx + abs( to - px ) ) { 
                     ++nowt ;  
                     tx = nowt  ; 
                     px = to ; 
                 } 
                 else { 
                      nowt = tx + abs( to - px )  ; 
                      ++nowt ;  
                      tx = nowt ;   
                      px = to ;  
                 }    
             } 
             else { 
                  if( nowt >= ty + abs( to  - py ) ) {
                      ++nowt ; 
                      ty = nowt ; 
                      py = to ;  
                  } 
                  else {
                       nowt = ty  + abs( to - py ) ;  
                       ++nowt ; 
                       ty = nowt ; 
                       py = to ;  
                  } 
             } 
            // cout << nowt <<endl; 
       } 
       cout << "Case #"<<Cas <<": "<< nowt  <<endl; 
   } 
   return 0 ;
}

                      
                 
        

         
        

    
    
