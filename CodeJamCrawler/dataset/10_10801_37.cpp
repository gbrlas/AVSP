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

int solve(int k, const vector<string>& grid) {
  rep(i, 2*(k - 1)) {
    forinc(x, -min(i, k - 1), min(i, k - 1)+1) {
      rep(j, 2) {
	int y = (2*j - 1)*(i - abs(x));
	bool done = false;
	int size = k - abs(x);
	forinc(l, 1, size) {
	  forinc(m, -size + l + 1, size - l) {
	    if (grid[k - 1 + m][k - 1 + x + l] != grid[k - 1 + m][k - 1 + x - l]) {
	      done = true;
	      break;
	    }
	  }
	  if (done)
	    break;
	}
	if (done)
	  continue;

	size = k - abs(y);
	forinc(m, 1, size) {
	  forinc(l, -size + m + 1, size - m) {
	    if (grid[k - 1 + y + m][k - 1 + l] != grid[k - 1 + y - m][k - 1 + l]) {
	      done = true;
	      break;
	    }
	  }
	  if (done)
	    break;
	}
	if (!done)
	  return (k + i)*(k + i) - k*k;
      }
    }
  }

  return (3*k - 2)*(3*k - 2) - k*k;
}

int main() {
  int t;
  cin >> t;
  rep(i, t) {
    cout << "Case #" << i + 1 << ": ";
    int k;
    cin >> k;
    cin.get();
    vector<string> grid(2*k-1);
    rep(i, 2*k-1) {
      getline(cin, grid[i]);
    }
    cout << solve(k, grid);
    cout << endl;
  }
}
