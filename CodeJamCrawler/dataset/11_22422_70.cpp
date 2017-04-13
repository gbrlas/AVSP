#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int test = 0, tc;
  string res;
  for (cin >> tc; test < tc; ++test) {
    int n, c, x = 0, sum = 0, mn = 10000000;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> c;
      sum += c;
      mn = min(mn, c);
      x ^= c;
    }
    if (x != 0) 
      cout << "Case #" << test + 1 << ": NO" << endl;
    else 
      cout << "Case #" << test + 1 << ": " << sum - mn << endl;

  }
  return 0;
}
