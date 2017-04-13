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

double const EPS = 1e-8;
const int N = 555;
int n, m, dd;
int d[N][N];
int sum(int i, int j, int ii, int jj) {
  int cur = 0;
  cur += d[ii][jj];
  if (i > 0) cur -= d[i - 1][jj];
  if (j > 0) cur -= d[ii][j - 1];
  if (i > 0 && j > 0) cur += d[i - 1][j - 1];
  return cur;
}

void solve() {
  cin >> n >> m >> dd;
  vector<string> s(n);
  forn(i, n) cin >> s[i];
  d[0][0] = s[0][0] - '0';
  for (int i = 1; i < n; i++) d[i][0] = d[i - 1][0] + s[i][0] - '0';
  for (int j = 1; j < m; j++) d[0][j] = d[0][j - 1] + s[0][j] - '0';
  for (int i = 1; i < n; i++) for (int j = 1; j < m; j++) d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + s[i][j] - '0';
  int res = 0;
  forn(i, n) forn(j, m) {
    int cur = 1;
    while (i - cur >= 0 && j - cur >= 0 && i + cur < n && j + cur < m) {
      double w1 = 0, w2 = 0;
      for (int ii = i - cur; ii <= i + cur; ii++)
        for (int jj = j - cur; jj <= j + cur; jj++) {
          if (abs(i - ii) == cur && abs(j - jj) == cur)
            continue;
          if (i == ii && j == jj)
            continue;
          w1 += 1.0 * (ii - i) * (s[ii][jj] - '0');
          w2 += 1.0 * (jj - j) * (s[ii][jj] - '0');
        }
      //cerr << i << " " << j << " " << 2 * cur + 1 << " " << w1 << " " << w2 << endl;
      if (fabs(w1) < EPS && fabs(w2) < EPS)
        res = max(res, 2 * cur + 1);
      cur++;
    }
  }
  forn(i, n) forn(j, m) {
    int cur = 1;
    while (i - cur  + 1 >= 0 && j - cur + 1 >= 0 && i + cur < n && j + cur < m) {
      double w1 = 0, w2 = 0;
      for (int ii = i - cur + 1; ii <= i + cur; ii++)
        for (int jj = j - cur + 1; jj <= j + cur; jj++) {
          if ( (ii == i - cur + 1 || ii == i + cur) && (jj == j - cur + 1 || jj == j + cur))
            continue;
          w1 += 1.0 * (ii - i - .5) * (s[ii][jj] - '0');
          w2 += 1.0 * (jj - j - .5) * (s[ii][jj] - '0');
        }
      //cerr << i << " " << j << " " << 2 * cur << " " << w1 << " " << w2 << endl;
      if (fabs(w1) < EPS && fabs(w2) < EPS)
        res = max(res, 2 * cur);
      cur++;
    }
  }
  cerr << "#" << res << "#" << endl;
  if (res >= 3)
    cout << res << endl;
  else
    cout << "IMPOSSIBLE" << endl;
}

int main() {
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);
  //ios_base::sync_with_stdio(0);

  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}

