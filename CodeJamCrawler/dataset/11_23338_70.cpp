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
#include <stack>
using namespace std ;  

#define F first 
#define S second
#define MP make_pair
#define SZ(x)  (int)x.size()
#define LEN(x) (int)x.length()
#define PB push_back

typedef long long int64 ; 
typedef pair<int,int>  PII ; 

map<char ,int> mp ; 
char my[20  ]  = {"QWERASDF" } ;  

int  op [ 10][ 10 ]; 
char cob[ 10 ][ 10] ; 

int get(  char c ) { 
    if(  mp[  c ]  )  return mp[c]; 
    else return -1 ; 
}

void init() { 
     for( int i=   0 ; i <  8 ; ++i) { 
          mp[ my[i] ] = 1 + i ; 
     } 
}

stack<char> ans  ; 

bool  gao1 (int u   ) {   

     stack<char>  tmp = ans ; 
     while( tmp.size() > 0 ) {  
            int t =get (  tmp.top() )  ;  tmp.pop () ;  
            if( t == -1 || u == -1 )  continue  ; 
            if(  op[ t][ u ] ) { 
                 while(ans.size() ) ans.pop() ; 
                 return true ; 
            }  
     } 
     return false  ;
}
     

int main () {

    freopen(  "B.in", "r" , stdin) ; 
    freopen( "B.out", "w", stdout) ;  
    int T ; 
    scanf ("%d", &T) ; 
    
    init() ; 
    for( int Cas = 1 ;  Cas <= T ; ++Cas ) { 
    
         int C , D , N ; 
        
         memset( cob, 0, sizeof( cob ) ) ;
         memset( op , 0 , sizeof( op ) ) ; 
          scanf ("%d",&C) ;   

         for( int i=1 ; i <= C ; ++i) { 
              char ss[10] ;
              scanf ("%s", ss ) ; 
              cob[  get( ss[0] ) ] [  get( ss[1] ) ]  =  ss[2 ]; 
              cob[  get( ss[1] ) ] [ get ( ss[0] ) ]  =  ss[2] ; 
         } 
         scanf ("%d", &D) ;
         
         for( int i=1 ; i <= D; ++i) {
              char ss[10] ;
              scanf ("%s", ss) ;
              op [  get( ss[0] ) ][ get( ss[1] ) ]  =  1 ; 
              op [ get( ss[1] ) ] [ get(ss[0] ) ] = 1 ;
         }  

         scanf ("%d", &N) ; 
         
         string s;
         cin >> s ;  
         for( int i=  0; i < LEN(s ) ; ++i) { 
              if( ans.size() >=1 ) { 
                  
                   int u = get( ans.top() ) ,   v = get(  s[ i ] ) ; 
                   if( u == -1 || v == -1 || !cob[u][v] )  {
                       if(   gao1(v ) )  ;  
                       else ans.push(  s[ i ] ) ;  
                   } 
                   else if( cob[ u ][ v ] ) { 
                       ans.pop() ; 
                       ans.push( cob[ u][ v] ) ; 
                   }    
              }  
              else ans.push( s[i] );  
         } 

         cout <<"Case #"<<Cas <<": " ; 
         vector< char > res ; 
         while( ans.size() ) {
                res.PB( ans.top() ) ; 
                ans.pop(); 
         }

         reverse( res.begin() , res.end() ) ;  
         cout <<"[" ; 
         for( int i= 0 ; i < SZ( res ) ; ++i) {
              cout  << res[ i]  ;
              if(  i  == SZ( res ) - 1 ) {  
                   puts("]"); 
              }
              else { 
                   cout <<", " ; 
              } 
         } 
         if( res.size() == 0 )   puts("]");   
             
    }
    return 0 ; 
}
               
         
