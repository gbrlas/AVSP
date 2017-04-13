#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cassert>
using namespace std;
typedef long long ll;

#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define FOREQ(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define SZ(v) (int)((v).size())
#define MEMSET(v,h) memset((v),(h),sizeof(v))

void solve();
int main() {
  int test_case; cin >> test_case;
  REP(t, test_case) {
    printf("Case #%d: ", t+1);
    solve();
  }
}
//-------------------------------

ll mof(ll n) {
  if (n<=0) return n;
  REP(i, 60) {
    ll p=1LL<<i;
    if (p-1<=n && n<=2LL*p-2) return i;
  }
}

void solve() {
  ll N, P;
  cin >> N >> P;

  // always win
  {
    ll lo=0, hi=1LL<<N;
    while (hi-lo>1) {
      ll mid = (lo+hi)/2LL;
      ll worstL = mof(mid);
      ll worstrank = 0;
      REP(i, worstL) worstrank += 1LL<<(N-i-1);
      if (worstrank >= P) hi = mid;
      else lo = mid;
    }
    cout << lo;
  }
  //cout<<endl;
  //return;

  cout << " ";
  // possibly win
  {
    ll lo=0, hi=1LL<<N;
    while (hi-lo>1) {
      ll mid = (lo+hi)/2LL;
      ll bestW = mof((1LL<<N)-1-mid);
      ll bestrank = (1LL<<N)-1;
      REP(i, bestW) bestrank -= 1LL<<(N-i-1);
      if (bestrank >= P) hi = mid;
      else lo = mid;
    }
    cout << lo;
  }
  cout << endl;
}
