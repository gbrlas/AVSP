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

int v[120][120];
void solve() {
  int N, M;
  cin >> N >> M;
  REP(y, N) REP(x, M) cin >> v[y][x];
  FOREQ(h, 1, 100) {
    // check validity
    int f[120]={0}, g[120]={0};
    REP(y, N) REP(x, M) if (v[y][x]<=h) f[y]++,g[x]++;
    REP(y, N) REP(x, M) if (v[y][x]<=h && (f[y]!=M && g[x]!=N)) {
      cout<<"NO"<<endl;
      return;
    }
  }
  cout<<"YES"<<endl;
}
