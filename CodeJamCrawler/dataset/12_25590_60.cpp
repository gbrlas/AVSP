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

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
typedef long long ll;
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define mp make_pair
#define go(i,n) for(int i=0;i<n;i++)
#define go3(i,j,n) for(int i=j;i<n;i++)

int n;
int _pow[]={1,10,100,1000,10000,100000,1000000,10000000};

int func(int a){
 int mn=a;
 int t;

 go(i,n){
  t=a%10;
  a/=10;
  a+=_pow[n]*t;
  mn=min(mn,a);
 }
 return mn;
}

map<int,int> memo;

ll solve(int A,int B){
  memo.clear();
  n=0;
  while(_pow[n+1]<=B) n++;
  //printf("n=%d\n",n);
  go3(i,A,B+1){
   memo[func(i)]++;
   //cout<<i<<" "<<func(i)<<endl;
  }
  ll ans=0;
  ll t;

  tr(memo,it)
   {
    t=it->second;
    ans+=t*(t-1) / 2ll;
   }
  return ans;
}

void oku(){

  int T;
  scanf("%d",&T);
  int A,B;

  go(ii,T){
   scanf("%d%d",&A,&B);
   printf("Case #%d: %I64d\n",ii+1,solve(A,B));
  }

}

int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);

oku();

return 0;

}