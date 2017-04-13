#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <utility>

// GMP library available from http://gmplib.org/.
#include <gmpxx.h>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define auto(l, r) typeof(r) l = (r)
#define fordec(i, a, b) for (int i = (a), _b = (b); i != _b; --i)
#define foreach(i, c) for (auto(i, (c).begin()); i != (c).end(); ++i)
#define forinc(i, a, b) for (int i = (a), _b = (b); i != _b; ++i)
#define rep(i, n) forinc(i, 0, n)

typedef long long ll;

int solve(int p, vector<int>& m, vector<vector<int> >& price) {
  vector<int> cost[p + 1];
  
  rep(j, p + 1) {
    cost[j].resize(1 << p);
    rep(i, 1 << p)
      cost[j][i] = (p - m[i] <= j ? 0 : 1000001);
  }

  rep(l, p) {
    rep(i, p - l) {
      rep(j, 1 << (p - l - 1)) {
        cost[i][j] = min(cost[i][2*j] + cost[i][2*j+1],
		         cost[i+1][2*j] + cost[i+1][2*j+1] + price[l][j]);
      }
    }
  }

  return cost[0][0];
}


int main() {
  int t;
  cin >> t;
  rep(i, t) {
    cout << "Case #" << i + 1 << ": ";
    int p;
    cin >> p;
    vector<int> m(1 << p);
    rep(j, 1 << p)
      cin >> m[j];
    vector<vector<int> > price;
    rep(j, p) {
      vector<int> q(1 << (p - j - 1));
      rep(k, 1 << (p - j - 1))
	cin >> q[k];
      price.push_back(q);
    }
    cout << solve(p, m, price) << endl;
  }
}
