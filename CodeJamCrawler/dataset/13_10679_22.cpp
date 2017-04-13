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
int rec[1000010];

int main() { IO
  int tests;
  
  cin >> tests;
  for (int tt = 1; tt <= tests; ++tt) {
    cout << "Case #" << tt << ": ";
    
    int a, n, cnt = 0;
    
    cin >> a >> n;
    for (int i = 0; i < n; ++i) {
      cin >> sz[i];
    }
    sort(sz, sz + n);
    
    if (a == 1) {
      cout << n << endl;
      continue;
    }
    
    for (int i = 0; i < n; ++i) {
      if (a > sz[i]) {
        a += sz[i];
        rec[i] = cnt;
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
        rec[i] = cnt;
      }
    }
    int r = n;
    for (int i = 0; i < n; ++i) {
      r = min(r, n - i  - 1 + rec[i]);
    }
    cout << r << endl;
  }
  return 0;
}
