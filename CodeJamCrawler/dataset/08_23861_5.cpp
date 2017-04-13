#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define GI ({int _; scanf("%d", &_); _;})
#define X first
#define Y second
#define pb push_back
#define INF ((long long)INT_MAX)
#define two(n) (1<<(n))
#define REP(i,n) for(int i = 0; i < n; ++i)
#define FOR(i, s, e) for(int i = s; i < e; ++i)

#define LET(it,a) __typeof(a) it(a)
#define EACH(it,cont) for(LET(it, (cont).begin()); it != (cont).end(); ++it)
#define ALL(a) (a).begin(),(a).end()
#define cs c_str()

typedef long long ll;
typedef pair<int,int> ipair;
#define M 101
#define MOD (10007)

bool rock[M][M];
ll dp[M][M];

ll solve(int x, int y) {
  if(x <= 0 or y <= 0) return 0;
  ll &ret = dp[x][y];
  if(ret == -1) {
    ret = 0;
    if(x == 1 and y == 1) return ret = 1;
    if(rock[x][y]) return ret = 0;
    ret += (solve(x-1, y-2))%MOD + (solve(x-2, y-1))%MOD;
    return ret;
  }
  return ret;
}

void solve() {
  int h, w, r;
  
  h = GI, w = GI, r = GI;
  memset(rock, 0, sizeof(rock));
  memset(dp, -1, sizeof(dp));
  
  REP(i, r) {
    int x, y;
    cin >> x >> y;
    rock[x][y] = true;
  }
  
  ll ans = solve(h, w);
  
  static int kase = 0; ++kase;
  printf("Case #%d: %lld\n", kase, ans%MOD);
  
}

int main() {
  int t = GI; while(t--) solve();
  return 0;
}