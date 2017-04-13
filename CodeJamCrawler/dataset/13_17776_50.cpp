

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
char mapa[4][4];
bool checkWin(char c)
{
    if(((mapa[0][0]==c||mapa[0][0]=='T')&&(mapa[0][1]==c||mapa[0][1]=='T')&&(mapa[0][2]==c||mapa[0][2]=='T') && (mapa[0][3]==c||mapa[0][3]=='T'))||
    ((mapa[1][0]==c||mapa[1][0]=='T')&&(mapa[1][1]==c||mapa[1][1]=='T')&&(mapa[1][2]==c||mapa[1][2]=='T') && (mapa[1][3]==c||mapa[1][3]=='T'))||
    ((mapa[2][0]==c||mapa[2][0]=='T')&&(mapa[2][1]==c||mapa[2][1]=='T')&&(mapa[2][2]==c||mapa[2][2]=='T') && (mapa[2][3]==c||mapa[2][3]=='T'))||
    ((mapa[3][0]==c||mapa[3][0]=='T')&&(mapa[3][1]==c||mapa[3][1]=='T')&&(mapa[3][2]==c||mapa[3][2]=='T') && (mapa[3][3]==c||mapa[3][3]=='T'))||
    ((mapa[0][0]==c||mapa[0][0]=='T')&&(mapa[1][0]==c||mapa[1][0]=='T')&&(mapa[2][0]==c||mapa[2][0]=='T') && (mapa[3][0]==c||mapa[3][0]=='T'))||
    ((mapa[0][1]==c||mapa[0][1]=='T')&&(mapa[1][1]==c||mapa[1][1]=='T')&&(mapa[2][1]==c||mapa[2][1]=='T') && (mapa[3][1]==c||mapa[3][1]=='T'))||
    ((mapa[0][2]==c||mapa[0][2]=='T')&&(mapa[1][2]==c||mapa[1][2]=='T')&&(mapa[2][2]==c||mapa[2][2]=='T') && (mapa[3][2]==c||mapa[3][2]=='T'))||
    ((mapa[0][3]==c||mapa[0][3]=='T')&&(mapa[1][3]==c||mapa[1][3]=='T')&&(mapa[2][3]==c||mapa[2][3]=='T') && (mapa[3][3]==c||mapa[3][3]=='T'))||
    ((mapa[0][0]==c||mapa[0][0]=='T')&&(mapa[1][1]==c||mapa[1][1]=='T')&&(mapa[2][2]==c||mapa[2][2]=='T') && (mapa[3][3]==c||mapa[3][3]=='T'))||
    ((mapa[3][0]==c||mapa[3][0]=='T')&&(mapa[2][1]==c||mapa[2][1]=='T')&&(mapa[1][2]==c||mapa[1][2]=='T') && (mapa[0][3]==c||mapa[0][3]=='T')))
    return true;
    return false;
}
int main(){
   freopen("A-large.in","r",stdin);
   freopen("outA-large.out","w",stdout);
   int T;
   int cases=1;
   cin>>T;

     while(T--){
      FOR(i,4)
         FOR(j,4)
            cin>>mapa[i][j];

        bool flag=false;
        if(checkWin('X'))cout<<"Case #"<<cases++<<": "<<"X won"<<endl;
        else
        if(checkWin('O'))cout<<"Case #"<<cases++<<": "<<"O won"<<endl;
            else{
            FOR(i,4)
               FOR(j,4)
                  if(mapa[i][j]=='.') {
                     flag = true;
                     j=i=4;

                  }
                  if(flag) cout<<"Case #"<<cases++<<": "<<"Game has not completed"<<endl;
            else
            cout<<"Case #"<<cases++<<": "<<"Draw"<<endl;
            }



   }
   //system("pause");
   return 0;

   }
