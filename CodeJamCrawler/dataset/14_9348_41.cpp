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
  int a[1000009];
  vector<vector<int> > matr;
 

int main() {
  freopen("input", "r", stdin);
  freopen("output", "w", stdout);
  std::ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) { 
    cin >> n;
    cin >> p;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a, a + n);
    int res = 0, h = 0;
    for (int i = n-1; i >= h; --i) {
      if (a[i] + a[h] > p) {
        res++;
      } else {
        h++;
        res++;
      }
    }
    cout << "Case #" << t << ": ";
    cout << res << "\n";
  }
}
