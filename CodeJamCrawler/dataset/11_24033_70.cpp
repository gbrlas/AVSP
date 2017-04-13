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

int main() {
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);
  //ios_base::sync_with_stdio(0);

  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    int n;
    cin >> n;
    vi a(n);
    int all = 0;
    forn(i, n) {
      cin >> a[i];
      all ^= a[i];
    }
    if (all != 0) {
      cout << "NO" << endl;
    } else {
      sort(a.begin(), a.end());
      int res = 0;
      for(int i = 1; i < n; i++)
        res += a[i];
      cout << res << endl;
    }
  }
  return 0;
}

