#pragma comment(linker, "/STACK:256000000")
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

  long long k, n, m, p;
  string s1, s2; 
  int M, R, C, P;
  long long a[1000009];
  vector<vector<int> > matr;
 

int main() {
  freopen("input", "r", stdin);
  freopen("output", "w", stdout);
  std::ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) { 
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int res1 = 0, res2 = 0, res = 0;
    for (int i = 0; i < n; ++i) {
      res1 = 0;
      res2 = 0;
      for (int j = 0; j < i; ++j) {
        if (a[j] > a[i]) {
          res1++;
        }
      }
      for (int j = i + 1; j < n; ++j) {
        if (a[j] > a[i]) {
          res2++;
        }
      }
      res += min(res1, res2);
    }
    cout << "Case #" << t << ": ";
    cout << res << "\n";
  }
}
