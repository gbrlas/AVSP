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
const double EPS = 1e-13;

double solve() {
  int c, d;
  cin >> c >> d;
  vector<pii> all(c);
  forn(i, c)
    cin >> all[i].first >> all[i].second;
  sort(all.begin(), all.end());
  double l = 0, r = 1e30;
  for (int it = 0; it < 100000; it++) {
    double m = (l + r) / 2;
    double edge = -1e100;
    bool ok = 1;
    forn (i, c) {
      double start_pos = max(edge, all[i].first - m);
      double end_pos = start_pos + d * (all[i].second - 1);
      if (end_pos > all[i].first + m + EPS)
        ok = false;
      edge = end_pos + d;
    }
    if (ok)
      r = m;
    else
      l = m;
  }
  return l;
}


int main() {
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);
  //ios_base::sync_with_stdio(0);

  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << fixed << setprecision(12) << solve() << endl;
  }
  return 0;
}

