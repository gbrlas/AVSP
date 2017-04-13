#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>

using namespace std;

#define INF (INT_MAX)
#define REP(i,n) for(int i = 0; i < n; i ++)
#define FOR(i,s,n) for(int i = s; i < n; i ++)
#define pb push_back
#define X first
#define Y second
#define llu unsigned long long
typedef  pair<llu,llu> ipair;
#define GI ({int _; scanf("%d", &_); _;})

void solve() {
  static int kase = 0; ++kase;
  
  llu n, A, B, C, D, x0, y0, M;
  cin >> n >> A >> B >> C >> D >> x0 >> y0 >> M;
  vector<ipair> points;
  //points.pb(make_pair(x0, y0));
  unsigned long int x = x0, y = y0;
  
  llu count[3][3];
  REP(i, 3) REP(j, 3) count[i][j] = 0;
  
  count[x0%3][y0%3]++;
  
  FOR(i, 1, n) {
    x = ((A%M * x%M)%M + B%M) % M;
    y = ((C%M * y%M)%M + D%M) % M;
    count[x%3][y%3]++;
  }
  
  llu ans = 0 ;
  
  REP(r1, 3) REP(r2, 3) {
    llu c = count[r1][r2];
    if(c >= 3)
      ans += (c * (c - 1) * (c - 2)) / 6;  
  }
  
  REP(r1, 7) {
    FOR(r2, r1+1, 8) {
      int i1 = r1/3, i2 = r1%3;
      int j1 = r2/3, j2 = r2%3;
      int k1 = (3 - (i1 + j1)%3)%3, k2 = (3 - (i2 + j2)%3)%3;
      
      if(k1 * 3 + k2 > r2)
        ans += count[i1][i2] * count[j1][j2] * count[k1][k2];      
    }
  }
  
  printf("Case #%d: %llu\n", kase, ans);
}

int main() {
  int t = GI;
  while(t--) solve();
  return 0;
}