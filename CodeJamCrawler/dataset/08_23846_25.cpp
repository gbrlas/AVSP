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
  points.pb(make_pair(x0, y0));
  unsigned long int x = x0, y = y0;
  
  int count[3][3];
  memset(count, 0, sizeof(count));
  
  FOR(i, 1, n) {
    x = ((A%M * x%M)%M + B%M) % M;
    y = ((C%M * y%M)%M + D%M) % M;
    points.pb(make_pair(x % 3 , y % 3));
    count[x%3][y%3]++;
  }
  
  llu ans = 0 ;
  
  REP(i, n) {
    FOR(j, i+1, n) {
      FOR(k, j+1, n) {
       if((points[i].X + points[j].X + points[k].X)%3 == 0 && (points[i].Y + points[j].Y + points[k].Y)%3 == 0)
        ans++;
      }
    }     
  }
  
  // REP(r1, 3) REP(r2, 3) {
  //       llu c = count[r1][r2];
  //       if(c >= 3)
  //         ans += (c * (c - 1) * (c - 2)) / 6;  
  //     }
  //     
  //     REP(r1, 3) REP(r2, 3) {
  //       REP(x, 3) REP(y, 3) {
  //         ipair rem1 = make_pair(r1, r2); llu c1 = count[r1][r2];
  //         ipair rem2 = make_pair(x, y); llu c2 = count[x][y];
  //         ipair rem3 = make_pair(3 - (r1 + x) %3, 3 - (r2 + y) % 3); llu c3 = count[3 - (r1 + x) %3][ 3 - (r2 + y) % 3];
  //         
  //         if(rem1 == rem2 and rem2 == rem3) {
  //           if(c1 >= 3) ans += c1 * (c2 - 1) * (c3 - 2) / 6;
  //         }
  //         else if(rem1 == rem2) {
  //           if(c1 >= 2) ans += c1 * (c2 - 1) * c3;
  //         }
  //         else if(rem2 == rem3) {
  //           if(c2 >= 2) ans += c1 * c2 * (c3 - 1);
  //         }
  //         else {
  //           if()
  //         }
  //       }
  //     }
  printf("Case #%d: %llu\n", kase, ans);
}

int main() {
  int t = GI;
  while(t--) solve();
  return 0;
}