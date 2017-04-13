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

int solve() {
  int n;
  cin >> n;
  vi p1, p2;
  vector<pii> all;
  forn(i, n) {
    char ch; int x;
    cin >> ch >> x;
    if (ch == 'O')
      p1.push_back(x), all.push_back(pii(0, x));
    else
      p2.push_back(x), all.push_back(pii(1, x));
  }

  int c1 = 1, c2 = 1;
  int i1 = 0, i2 = 0, i = 0;
  int steps = 0;
  for ( ; i < all.size(); steps++) {
    int first = all[i].first;

    if (i1 < p1.size()) { 
      if(c1 == p1[i1]) {
        if (first == 0)
          i1++, i++;
      }
      else
        c1 += (p1[i1] - c1) / abs(p1[i1] - c1);
    }

    if (i2 < p2.size()) { 
      if(c2 == p2[i2]) {
        if (first == 1)
          i2++, i++;
      }
      else
        c2 += (p2[i2] - c2) / abs(p2[i2] - c2);
    }
  }
  return steps;
}

int main() {
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);
  //ios_base::sync_with_stdio(0);

  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    cout << solve() << endl;
  }

  return 0;
}

