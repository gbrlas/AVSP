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



double sumx[ 500+10][ 500+10] ;  
double sumy[ 500+10][ 500+10 ]; 
double sumw[ 500+10][ 500+10] ; 
double mat[ 500+10][500+10 ] ;
int n , m , d ; 
char s[ 500+10][500+10]  ; 

int cal ( int  x , int y, int k ) { 

     if( x + k -1 > n || y + k -1  > m )  return  -1 ;  

     int  tx = x + k -1 ,  ty = y + k - 1;  
     //cout << tx <<" " <<ty <<endl; 
     double  gx =   sumx[ tx ][ ty ]   +  sumx[ x-1][ y-1]  - sumx[ x - 1][ ty] - sumx[ tx][ y - 1]
     - tx * mat[ tx ][ ty] -tx * mat[ tx ][ y]  - x *  mat[ x][ ty] - x* mat[ x][ y] ;     
     double  gy =   sumy[ tx ][ ty ]   +  sumy[ x-1][ y-1]  - sumy[ x - 1][ ty] - sumy[ tx][ y - 1]
     - ty* mat[ tx ][ ty] -y * mat[ tx ][ y]  - ty *  mat[ x][ ty] - y* mat[ x][ y] ;   
     double cx = x +  ( tx - x) /2.0 ; 
     double cy = y + ( ty - y ) / 2.0; 
     
     double gw = sumw[ tx][ ty] + sumw[ x-1][y-1] - sumw[ x- 1][ ty] - sumw[tx][ y - 1]  
     -mat[tx][ty] - mat[x][y] - mat[ tx][y]- mat[ x][ ty] ; 
     
     if(   fabs( gx -  gw * cx ) <1e-9 &&  fabs( gy - gw* cy ) < 1e-9 )  return k ; 
     else return -1; 
}
int main () { 
    
     freopen("BI.txt" , "r", stdin) ; 
    freopen("BO.txt",  "w", stdout ) ;  
    int T ;    
    scanf ("%d", &T) ; 
    for( int Cas = 1 ; Cas <= T ; ++Cas ) { 
          
          cin>> n >> m >> d ;  
          
          for( int  i = 1; i <= n ; ++i) { 
               scanf ("%s", s[i] + 1 ) ; 
          }  

          for( int i= 0 ;i <= m; ++i) sumx[0][i]= 0, sumy[0][i]= 0, sumw[ 0][i] = 0 ; 
          for( int i = 1 ; i <= n ; ++i) { 
               double tmp =  0 ; 
               double tmp1 = 0 ; 
               double tmp2 = 0 ; 
               mat[i][0]= 0 ;
               sumw[ i ][ 0 ] =0 ; 
               sumx[ i ][ 0 ] = 0 ; 
               sumy[ i ][ 0 ] = 0 ; 


               for( int j=1; j <= m ; ++j) { 
                    
                    mat[ i ][j] = d + s[i][j] -'0';  
                    tmp += mat[i][j] ;  
                    tmp1 += mat[i][j] * i ; 
                    tmp2 += mat[i][j] * j ; 
                    sumw[ i ][ j ] = sumw[ i -1 ][ j ] +  tmp ;     
                    sumx[ i ][ j ] = sumx[ i -1 ][ j ] +  tmp1  ; 
                    sumy[ i ][ j]  = sumy[ i -1 ][ j ] + tmp2 ;  
               }   
            
          }   

          int ans =  -1; 
          for( int i = 1 ; i <= n ; ++i) { 

               for( int j = 1 ; j <= m  ; ++j ) { 
                    
                    for( int k =  3 ;  k <= min( n , m ) ; ++k) { 

                         ans = max( ans , cal( i , j , k ) ) ; 
                    } 
               } 
           }

           cout <<"Case #"<<Cas<< ": ";  
           if( ans == -1 ) puts("IMPOSSIBLE"); 
           else cout << ans <<endl ;  
      } 
      return 0 ; 
}

              
                    
    
    
    
