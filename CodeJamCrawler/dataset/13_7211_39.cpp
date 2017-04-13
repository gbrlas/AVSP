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

const ll MOD = 1000002013;
ll add(ll a, ll b) { return (a+b)%MOD; }
ll mul(ll a, ll b) { return (a*b)%MOD; }

struct P {
  ll pos,n;
};

void solve() {
  ll N, M; cin >> N >> M;
  map<ll,pair<ll,ll> > sweep;

  ll def=0;
  REP(i, M) {
    ll o,e,p; cin>>o>>e>>p;
    sweep[o].first+=p;
    sweep[e].second+=p;
    // p*(N+1-d+N)*i/2 ?
    ll d = e-o;
    ll v = (N+1-d+N)*d/2 % MOD;
    def = add(def, mul(p, v));
  }

  ll cost=0;
  vector<P> q;
  FORIT(it, sweep) {
    // enter
    ll pos = it->first, e = it->second.first, o = it->second.second;
    if (e) {
      q.push_back((P){pos, e});
    }
    // out
    while (o > 0) {
      ll exc=min(o, q.back().n);
      ll d = pos-q.back().pos;
      ll v = (N+1-d+N)*d/2 % MOD;
      cost = add(cost, mul(exc, v));

      q.back().n -= exc;
      o -= exc;
      if (q.back().n == 0) q.pop_back();
    }
  }

  cout << (def-cost+MOD)%MOD << endl;
}
