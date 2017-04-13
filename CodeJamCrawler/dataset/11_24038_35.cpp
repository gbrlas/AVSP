#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cassert>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;
#define DB(x) { cerr << #x << ": " << x << " "; }
#define forn(i, n)  for (int i = 0; i < (int)(n); ++i)
#define sqr(x) ((x)*(x))
typedef long double ld;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int,int> pii;
const ld PI = acos(-1.0);

void solve() {
  int n;
  cin >> n;
  vi wins(n), total(n);
  vector<string> s(n);
  forn(i, n) {
    cin >> s[i];
    forn(j, n) {
      if (s[i][j] == '0' || s[i][j] == '1') total[i]++;
      if (s[i][j] == '1') wins[i]++;
    }
  }
  vector<double> wp(n), owp(n), oowp(n);
  forn(i, n) wp[i] = 1.0 * wins[i] / total[i];
  forn(i, n) {
    int cnt = 0;
    forn(j, n) {
      if (s[i][j] != '.') {
        cnt++;
        if (s[i][j] == '1')
          owp[i] += 1.0 * wins[j] / (total[j] - 1);
        else
          owp[i] += 1.0 * (wins[j] - 1) / (total[j] - 1);
      }
    }
    owp[i] /= cnt;
  }
  forn(i, n) {
    int cnt = 0;
    forn(j, n) {
      if (s[i][j] != '.')
        oowp[i] += owp[j], cnt++;
    }
    oowp[i] /= cnt;
  }
  forn(i, n) {
    cout << fixed << setprecision(12) << 0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i] << endl;
  }
}

int main() {
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);
  //ios_base::sync_with_stdio(0);

  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    printf("Case #%d:\n", t);
    solve();
  }
  return 0;
}

