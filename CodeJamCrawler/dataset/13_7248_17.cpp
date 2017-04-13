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

static const int N=37;
ll B;
ll x[40];
double go(ll y) {
  if (y<0) return 0;
  double best = 0;

  REP(j2, N) REP(j1, j2+2) {
    ll cost = 0;
    ll bet[N];
    MEMSET(bet, 0LL);
    REP(i, N) bet[i] = max(0LL, y-x[i]);
    FOREQ(i, j1, j2) bet[i]++;
    REP(i, N) cost += bet[i];
    if (cost > B) continue;

    ll least = 1LL<<60;
    REP(i, N) least=min(x[i]+bet[i], least);
    ll leastn = 0;
    REP(i, N) if (least==x[i]+bet[i]) leastn++;

    double profit = 0;
    REP(i, N) if (least==x[i]+bet[i]) profit += bet[i];
    profit *= 1.0 * (N-1) / leastn;

    best = max(best, profit - cost);
  }
  return best;
}

void solve() {
  int M; cin >> B >> M;
  MEMSET(x, 0LL);
  REP(i, M) cin >> x[i];
  sort(x, x+N);

  double res = 0;
  // REP(i, N) FOREQ(v, -1, 1) res=max(res, go(x[i]+v));

  // girigiri?
  ll lo=0LL, hi=1LL<<50;
  while (hi-lo>1) {
    ll y =(lo+hi)/2;
    ll c = 0;
    REP(i, N) c += max(0LL, y-x[i]);
    if (c > B) hi = y;
    else lo = y;
  }
  assert(go(hi) == 0);

  // cout<<"#"<<hi<<endl;
  lo = 0LL;
  while (hi-lo>2) {
    ll m1 = (lo*2+hi)/3;
    ll m2 = (lo+hi*2)/3;

    res = max(res, max(go(m1), go(m2)));
    if (go(m1) > go(m2)) hi = m2;
    else lo = m1;
  }
  FOREQ(v, -3, 3) res = max(res, go(lo+v));
  /*
  REP(i, lo) assert(go(i) <= go(i+1));
  FOR(i, lo+1, hi) assert(go(i) >= go(i+1));
  FOREQ(v, 0, 5) cerr<<go(v)<<endl;
  */

  /*
  REP(i, N-1) if (x[i]!=x[i+1]) {
    ll req = (i+1) * (x[i+1]-x[i]-1);
    ll y = 0LL;
    if (tot + req <= B) {
      tot += req;
      y = x[i+1]-1;
    } else {
      ll ok = (B-tot) / (i+1);
    }
    REP(j, i) {
      ll bet[N];
      MEMSET(bet, 0);
      REP(k, j+1) bet[k] = y-x[k];
      FOR(k, j+1, i+1) bet[k] = y+1-x[k];

      ll cost = 0LL;
      REP(k, N) cost += bet[k];
      double profit = 0;
      REP(k, j+1) profit += bet[k];

      ll least = 1LL<<60;
      REP(k, N) least=min(x[k]+bet[k], least);
      ll leastn = 0;
      REP(k, N) if (least==x[k]+bet[k]) leastn++;
      profit *= 1.0 * (N-1) / leastn;

      res = max(res, profit - cost);
    }
  }
  */

  /*
  M = 0;
  int K = 0;
  REP(i, N) {
    if (x[i] == L) K++;
    else if (x[i] > 0LL) M++;
  }

  cerr<<N<<" "<<M<<" "<<K<<endl;

  double res = 0;
  // y < L
  {
    ll y = min(L-1, B/(N-M-K));
    cerr<<y<<endl;
    res = max(res, 1.0*(M+K-1) * y);
  }
  // y == L
  FOREQ(i, 0, K) if (B >= (N-M-K)*L+i) {
    res = max(res, 1.0*(N-M-K) / (N-M-i) * (N-1) * L - (N-M-K)*L - i);
  }

  */
  printf("%.14f\n", res);
}
