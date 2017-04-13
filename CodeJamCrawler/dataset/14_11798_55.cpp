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
ll memo[32][3][3][3];
int val[4][40];

int flag(int fa,int limit,int valor){
  //igual
  if(fa == 1){
    if(limit == 1 ){
      if(limit > valor) return 0;
      else return 1;
    }
    else{
      if(limit == valor ) return 1;
      else return 2;
    }
  }
  //menor
  else {
    return 0;
  }
  return 2;
}
ll go(int pos,int fA,int fB,int fK){
  if(pos<0){
    if(fA == 0 && fB == 0 & fK == 0)
      return 1;
    return 0;
  }

  if(memo[pos][fA][fB][fK]!=-1)return memo[pos][fA][fB][fK];
  ll res = 0;
  f(bitA,0,2)f(bitB,0,2){
    int nu = (bitA&bitB);
    int fa = flag(fA,val[0][pos],bitA);
    int fb = flag(fB,val[1][pos],bitB);
    int fk = flag(fK,val[2][pos],nu);
    if(fa>1 || fb>1 || fk>1)continue;
    res+=go(pos-1,fa,fb,fk); 
  }
  return memo[pos][fA][fB][fK]=res;
} 
void pasa(int num,int index){
  for(int i=30;i>=0;i--){
    if(num&(1<<i))val[index][i] = 1; 
  }
}
void pr(int index){
  for(int i = 30;i>=0;i--){
    cout<<val[index][i];
  }
  cout<<endl;
}
void solve(){
  int A,B,K;
  cin>>A>>B>>K;
  clr(val,0);
  pasa(A,0);
  pasa(B,1);
  pasa(K,2);
  clr(memo,-1);
  ll res = go(30,1,1,1);
  cout<<res<<endl;
}
int main(){

    int casos;
    cin>>casos;
    f(k,1,casos+1)
    {
      cout<<"Case #"<<k<<": ";
      solve();
    }
    return 0;
  }
