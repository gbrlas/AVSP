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
#include <map>
 
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
int a[26];
int main() {
  string s,ss;
  VS res;
   s= "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jvzq";
   ss="our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give upqz";
   map<char,char> m;
  REP(i,s.sz){
    if(s[i]==' ')continue;           
    m[s[i]]=ss[i];
  }
  freopen("inp.in","r",stdin);
  freopen("out.txt","w",stdout);
  int n;
  cin>>n; 
  getchar();
  REP(i,n) {
    string inp;
    string out;
    getline(cin,inp);
    REP(j,inp.sz) {
       if(inp[j]==' '){ out+=' '; continue; }
       out+=m[inp[j]];
    }
    res.pb(out);
  }  
  REP(i,res.sz) cout<<"Case #"<<i+1<<": "<<res[i]<<endl;
  //while(1);
}
