#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define IO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

int sz[1000010];

int main() { IO
  int tests;
  
  cin >> tests;
  for (int tt = 1; tt <= tests; ++tt) {
    cout << "Case #" << tt << ": ";
    
    int aa, n, cnt, r = INT_MAX;
    memset(sz, 0, sizeof(sz));
    
    cin >> aa >> n;
    for (int i = 0; i < n; ++i) {
      cin >> sz[i];
    }
    sort(sz, sz + n);
    
    if (aa == 1) {
      cout << n << endl;
      continue;
    }
    
    for (int j = 0; j < (1 << n); ++j) {
      int a = aa, cnt = 0;
      
      for (int i = 0; i < n; ++i) {
          // deleted
        if (!(j & (1 << i))) {
          ++cnt;
          continue;
        }
          // choosed
        if (a > sz[i]) {
          a += sz[i];
          continue;
        }
        if (a <= sz[i]) {
          int add = 0;
          while (a <= sz[i]) {
            a += a - 1;
            ++add;
          }
          a += sz[i];
          cnt += add;
        }
      }
      r = min(r, cnt);
    }
    cout << r << endl;
  }
  return 0;
}
