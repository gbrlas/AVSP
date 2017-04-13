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
  void solve(){
    int A, B, res = 0,K;

    scanf("%d %d%d",&A,&B,&K);
    f(i,0,A){
      f(j,0,B){
        if ( (i&j) < K ){
          res++;
        }
      }
    }
    printf("%d\n",res);
  }

int main(){

    int casos;
    scanf("%d",&casos);
    f(k,1,casos+1)
    {
      printf("Case #%d: ",k);
      solve();
    }

    return 0;
  }
