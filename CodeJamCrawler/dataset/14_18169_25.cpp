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
#define N 4

int x[20][20];
int y[20][20];
int main(){
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    int T;
    int ant,desp;
    int cases = 1;
    int ans,wer;
    cin>>T;
    while(T--){
      cin>>ant;
      ans = 0;
      FOR(i,N)
         FOR(j,N)
            cin>>x[i][j];
      cin>>desp;
      FOR(i,N)
         FOR(j,N)
            cin>>y[i][j];
      FOR(i,N)
         FOR(j,N)
         //cout<<x[ant-1][i]<<" "<<y[desp-1][j]<<endl;
         
         if(x[ant-1][i]==y[desp-1][j])
            ans++,wer=x[ant-1][i];
      if(ans>1)
         printf("Case #%d: Bad magician!\n");
      if(ans==1)
         printf("Case #%d: %d",cases,wer);
      if(ans<1)
         printf("Case #%d: Volunteer cheated!");
         
    }
    system("pause");
    return 0;

    }
