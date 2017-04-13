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

struct T {
  double len;
  ll speed;
  int id;
  int can;
  T(double len = 0, ll speed = 0, int id = 0, int can = 0) : len(len), speed(speed), id(id), can(can) {}
  bool operator< (const T& o) const {
    if (speed != o.speed) return speed < o.speed;
    return id < o.id;
  }
};

double const EPS = 1e-8;

void solve() {
  ll s, r, n;
  double t, x;
  cin >> x >> s >> r >> t >> n;
  set<T> all;
  int id = 0;
  forn(i, n) {
    int st, end, add;
    cin >> st >> end >> add;
    T cur;
    cur.len = end - st;
    cur.speed = s + add;
    cur.id = id++;
    cur.can = 1;
    x -= cur.len;
    all.insert(cur);
  }
  if (x > 0)
    all.insert(T(x, s, id++, 1));

  double ans = 0;
  while (all.size() > 0) { 
    T cur = *all.begin();
    all.erase(all.begin());
    //cout << "#" << cur.len << " " << cur.id << " " << cur.speed << " "<< cur.can << endl;
    if (t < EPS || cur.can == 0) {
      //cout << "done" << endl;
      ans += cur.len / cur.speed;
      continue;
    }
    ll speed = cur.speed;
    double can = 1.0 * (speed + (r - s)) * t;
    if (cur.len <= can + EPS) {
      cur.speed += (r - s);
      t -= cur.len / cur.speed;
      cur.can = 0;
      all.insert(cur);
    }
    else {
      T cur1(can, cur.speed + r - s, id++, 0);
      T cur2(cur.len - can, cur.speed, id++, 1);
      t = 0;
      all.insert(cur1);
      all.insert(cur2);
    }
  }
  cout << fixed << setprecision(12) << ans << endl;
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

