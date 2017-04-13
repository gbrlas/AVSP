#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std ; 

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define SZ(x) (int)x.size()
#define LEN(x) (int)x.length() 

typedef long long int64 ; 
typedef pair<int,int> PII ; 


double w1[ 100 +10] ;
double w2[ 100+ 10] ; 
double w3[ 100 + 10] ;

int N ;
char mat[ 100 +10][ 100 +10]; 
int main () { 
   
         freopen("AI.txt", "r", stdin);
          freopen("AO.txt","w" , stdout ); 
         
         int T ; 
         scanf ("%d", &T ) ;   
         for( int Cas =1 ; Cas <= T ; ++Cas ) { 

              scanf ("%d", &N) ;
              for( int i=0; i < N; ++i) scanf("%s" , mat[ i ] ) ; 

              for( int i= 0; i < N ; ++i){ 
                   
                   int mu =0 , zi = 0; 
                   for( int j= 0 ;j < N ; ++j) {
                        zi +=  mat[i][j] =='1'; 
                        mu +=  mat[i][j] !='.'; 
                   } 
                   w1[ i ]= 1.0 *zi / mu ; 
              }  

              for( int i= 0; i < N ; ++i) { 
                   
                   w2[i] = 0 ;
                   int cnt =0 ;
                   for( int j =0; j< N; ++j){ 
                        if( i == j ) continue ;  
                        if( mat[ i ][ j ] =='.' ) continue ;  
                        ++cnt ; 
                        int zi =0, mu = 0;
                        for( int k=0;k < N; ++k) {  
                             if( k ==i ) continue ;
                             zi += mat[ j][ k] =='1'; 
                             mu += mat[j][k] !='.'; 
                        }
                        w2[i] += 1.0 * zi / mu ; 
                   }   
                   w2[ i ]  /= cnt ; 
             } 

             for( int i =0 ; i < N; ++i){ 

                  w3[i ] =0 ;
                  int cnt =0 ;
                  for( int j=0 ;j <N; ++j) {
                       if( i == j|| mat[ i ][j] =='.' ) continue  ;
                       ++cnt ;
                       w3[ i ] += w2[ j ]; 
                   }
                   w3[ i] /= cnt ; 
             }

             cout <<"Case #"<<Cas <<": "<<endl ;
             for( int i=0; i < N; ++i) {
                  printf ("%.10lf\n",   0.25 * w1[ i] + 0.5* w2[i] +  0.25 * w3[i] ) ; 
             } 
    }
    return 0;
}                                                         
                            
                             
                             
         
