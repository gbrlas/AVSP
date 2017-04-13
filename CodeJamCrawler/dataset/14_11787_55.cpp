#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
using namespace std;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).end,(v).begin
#define pb push_back
#define f(i,x,y) for(int i=x;i<y;i++)
#define FOR(it,A) for(typeof A.begin() it = A.begin();it!=A.end();it++)
#define sqr(x) (x)*(x)
#define mp make_pair
#define clr(x,y) memset(x,y,sizeof x)
#define eps 1e-07
#define SGN(x) ((x)<-eps?-1:(x)>eps?1:0)

typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
string pasa(string cad){
  int tam= cad.size();
  string res ="";
  int pos=0;
  while(pos<tam){
    char no = cad[pos];
    res+=no;
    while(pos<tam && no==cad[pos]){
      pos++;
    }
  }
  return res;
}
bool pode(vector <string> v){
  string uni = pasa(v[0]);
  f(i,1,v.size()){
    if(uni != pasa(v[i]))
      return false;
  }
  return true;
}
vector <int> des(string cad){
  vector <int> v;
  int tam= cad.size();
  int pos=0;
  while(pos<tam){
    char no = cad[pos];
    int cont = 0; 
    while(pos<tam && no==cad[pos]){
      pos++;
      cont++;
    }
    v.pb(cont);
  }
  return v;
  
}
void pr(vector <int> v){
  f(i,0,v.size())cout<<" "<<v[i];
  cout<<endl;
}
void solve(){
  int n;
  cin>>n;
  string cad;
  vector <string> v;
  f(i,0,n){
    cin>>cad;
    v.pb(cad);
  }
  bool es = true;
  if(!pode(v))
    es=false;
  if(!es){
    cout<<"Fegla Won"<<endl;
    return;
  }
  vector < vector <int> > todos;
  f(i,0,v.size()){
    todos.pb(des(v[i]));
  }
  int m = todos[0].size();
  int r =0;
  f(j,0,m){
    vector <int> col;
    f(i,0,n){
      col.pb(todos[i][j]);
    }
    sort(all(col));
    int s=0;
    int med = col[n/2];
    f(i,0,n){
     s+=abs(col[i]-med);
    }
    r+=s;
  }
  cout<<r<<endl;
}
int main(){
  int casos;
  cin>>casos;
  f(k,1,casos+1){
    cout<<"Case #"<<k<<": ";
    solve();
  }
  return 0;
}
