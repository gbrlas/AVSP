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

const int N = 1010;
int max_p[N];

void calc() {
  for (int i = 2; i < N; i++) {
    int x = i;
    for (int j = 2; j <= x; j++) {
      int cur = 0;
      while (x % j == 0)
        x /= j, cur++;
      max_p[j] = max(max_p[j], cur);
    }
  }
}

void solve() {
  ll n;
  cin >> n;
  ll m = 0, M = 1;
  for (int i = 2; i <= n; i++)
    if (max_p[i] > 0) {
      m++;
      ll x = i;
      while (x <= n)
        x *= i, M++;
    }
  if (m == 0) m = 1;
  cerr << n << " " << m << " " << M << " " << M - m << endl;
  cout << M - m << endl;
}

int main() {
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);
  //ios_base::sync_with_stdio(0);

  calc();

  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}

