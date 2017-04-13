#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <bitset>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <iterator>

#define FOR(i,n)   for(int i=0;i<n;i++)
#define FORA(a,i,n)   for(int i=a;i<n;i++)
using namespace std;
template<class T> string tostring(T x){
ostringstream sout;
sout<<x;
return sout.str();
}
template< class T > int toint( T s ){
int v;
istringstream sin(tostring(s));
sin>>v;
return v;
}
vector< string > split( string sentence ){
   istringstream iss( sentence );
   vector< string > tokens;
   copy( istream_iterator< string >(iss), istream_iterator< string >(), back_inserter<vector< string > >(tokens));
   return tokens;
}
string conversion(int a, int b){

       string cambio;
       int suma=0;
       int coci = a;
       while(coci>0){
                     cambio += tostring(coci%b);
                     coci = coci/b;
      }
     return string(cambio.rbegin(),cambio.rend());

       }
int GCD( int a , int b ) {
     if ( a%b==0) return b ;
      else
      return GCD( b , a % b) ;
}
double costFarm,sumFarm,goal,answer,ans;
int cases;
bool AreSame(double a, double b) {
   //cout<<"fabs "<<fabs(a - b)<<endl;
    return fabs(a - b) < numeric_limits<double>::epsilon();
}
int main(){
    freopen("small.in","r",stdin);
    freopen("out.out","w",stdout);
    int T;
    cases = 1;
    cin>>T;
    double two = 2.0000000;
    double gainFarm;
    double farm,c1,c2,m;
    double other;
    while(T--){
      
      ans = 0;
      gainFarm = 0;
      farm = 0;
      cin>>costFarm>>sumFarm>>goal;
      bool x = false;
      bool h = false;
      answer = (goal)/(two);
         c1= costFarm/(two+((gainFarm++)*sumFarm))  ;
         c2 = goal/(two+((gainFarm)*sumFarm));
         
      if( answer > c1+c2 )
         x = true,answer = c1+c2;
      
      while( x ){
         other = ( c1+c2+ans );
         //cout<<c1<<" "<<c2<<endl;
         if( other > answer ) break;
         if( !AreSame(other, answer) ){
            answer = other;
            
         }
         
         ans += c1;
         
         c1= costFarm/(2.0+((gainFarm++)*sumFarm))  ;
         
         c2 = goal/(2.0+((gainFarm)*sumFarm));

         
         //cout<<other<<" "<<answer<<endl;
        // system("pause");
         
         
        
      }
      
      printf("Case #%d: %.7f\n",cases++,answer);
    }
    //system("pause");
    return 0;

    }
