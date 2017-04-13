#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <sstream>
 
using namespace std;
 
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define sz size()
#define INF (int)1e9
 
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector< vector <int> > VVI;
typedef pair<int,int> pii;
string convert2string(int i) {
  ostringstream ss;
  ss << i;
  return ss.str();
}
int convert2int(string s) {
  istringstream ss(s);
  int a;
  ss >> a;
  return a;
}
string rotate(string s,int i) {
  string a= s.substr(s.sz-i);
  string b= s.substr(0,s.sz-i);
  return a+b;
}
int main() {
  int T;
 
  freopen("input.in","r",stdin);
  freopen("output.txt","w",stdout);
  cin>>T;
  VI res;

  REP(z,T) {
    int A,B,cnt=0;
    cin>>A>>B;
      map< pii , int > m;
    for(int i=A;i<=B;i++) {
         string s = convert2string(i);
         for(int k=1;k<s.sz;k++) {
            string t = rotate(s,k);
            int j = convert2int(t);
            if(j<=B && j>i) {
                    m[pii(i,j)]++;                    
            }
         }
    }
    res.pb(m.sz);
  }
  
  REP(i,res.sz) cout<<"Case #"<<i+1<<": "<<res[i]<<endl;
//  while(1);
}
