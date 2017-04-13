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
int cont[1000];
int main(){
  int cases;
  cin>>cases;
  f(t,1,cases+1){
  int n,x;
  cin>>n>>x;
  vector <int> v(n);
  clr(cont,0);
  f(i,0,n){
    cin>>v[i];
    cont[v[i]]++;
  }
  int res = 0;
   for(int i=700;i>=1;i--){
      while(cont[i]>0){
        res++;
        cont[i]--;
        int falta = x-i;
        bool tem = false;
        for(int j = falta ; j>=1;j--){
         if(cont[j] >0){
          cont[j]--;
          break;
         }
        }
      }
   }
   cout<<"Case #"<<t<<": ";
   cout<<res<<endl;
  }
  return 0;
}









