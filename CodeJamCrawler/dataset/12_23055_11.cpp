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
int r[1000+10];     

pair < int , int > my[1000+10] ; 
int main (){  
    INPUT("b.in") ;
    OUTPUT("b.out");
    int T; 
    scanf ("%d",&T); 
    for(int Cas = 1 ; Cas <= T ; ++Cas ){  
        int n, w, l ;  
        cin >> n >> w >> l ;  
        for(int i=1; i <= n ; ++i){   

            scanf ("%d", r+i) ;   
            my[i].first = r[i];
            my[i].second =  i  ; 

        }     
        sort( my+1 ,my+1+n) ; 
        reverse( my+1,my+1+n) ;  
        int ww = w, ll =l ;
        if( ww < ll ) swap(ww,ll) ;  
        sort( r+1, r + 1 + n ) ; 
        reverse(r+1, r+1+n) ;  
        pair<double, double > ans [ 1000+10] ;   
        for(int i=1; i <= n ; ++i){  
            ans[i].first =-1.; 
            ans[i].second = -1. ;
        } 
        ans[1].first = 0 , ans[1].second = 0 ;
        int pre = 1 ;  
        int cnt = 1 ;  
        queue<int> que ;  
        for(int i=2; i <= n ; ++i){  
            double x = ans[pre].first + r[pre] + r[i]  , y = ans[pre].second ;  
            if( x <  ww || fabs( x -ww ) <1e-7  )  {    
                ans[i] = MP(x,y) ;
                pre = i  ;  
                ++cnt ;  
            } else{ 
                que.push(i) ; 
            }
        }   
        int x = que.front() ;  
        ans[x] = MP( 1.*ww, 1.*ll )  ;  
        pre = x;  
        while(!que.empty() ){  que.pop() ; } 
        for(int i= 1;  i <= n ; ++i){  
            if(   ans [ i ].first > -0.5 )  continue ;     
            double x = ans[pre].first -r[pre] - r[i],  y = ans[pre].second ;
             
            if( (x > 0 || fabs(x-0.) < 1e-7)  ){  
                ans[i] = MP(x,y );
                pre= i ; 
            }  else{ 
                que.push(i) ;  
            }
        }  
        
        for( int i=1; i <= n ; ++i){  
            if( w < l ) swap ( ans[i].first , ans[i].second) ; 
        }    
        pair<double,double> res[1000+10]; 
        for(int i=1; i <= n ; ++i){ 
            if( ans[i].first < -0.5 ){  
                ans[i].first = rand() % w * 1. ; 
                ans[i].second= rand() % l * 1. ; 
            } 
             res[  my[i].second ] = ans[i ] ; 
        }
        cout <<"Case #"<<Cas <<": " ;  
        for(int i=1 ; i <= n ; ++i){ 
        
            printf ("%.1lf %.1lf%c", res[i].first, res[i].second , i == n?'\n':' ') ;
        }
      }
    return 0 ; 
}

  
           
                
            
          
            

        
