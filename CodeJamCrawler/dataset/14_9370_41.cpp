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

  long long W, H;
  long long a[109][509];
 
bool go(int x, int y, int napr) {
  if (a[x][y] == 1) 
    return false;
  a[x][y] = 1;
  if (y == H - 1)
    return true;
  if (napr == 0) {
    if (x > 0 && go(x-1, y, 1))
      return true;
    if (go(x, y+1, 0))
      return true;
    if (x+1 < W && go(x+1, y, 3))
      return true;
    if (y > 0 && go(x, y-1, 2))
      return true;
  }
  if (napr == 1) {
    if (y > 0 && go(x, y-1, 2))
      return true;
    if (x > 0 && go(x-1, y, 1))
      return true;
    if (go(x, y+1, 0))
      return true;
    if (x+1 < W && go(x+1, y, 3))
      return true;
  }
  if (napr == 2) {
    if (x+1 < W && go(x+1, y, 3))
      return true;
    if (y > 0 && go(x, y-1, 2))
      return true;
    if (x > 0 && go(x-1, y, 1))
      return true;
    if (go(x, y+1, 0))
      return true;
  }
  if (napr == 3) {
    if (go(x, y+1, 0))
      return true;
    if (x+1 < W && go(x+1, y, 3))
      return true;
    if (y > 0 && go(x, y-1, 2))
      return true;
    if (x > 0 && go(x-1, y, 1))
      return true;
  }
  return false;
}


int main() {
  freopen("input", "r", stdin);
  freopen("output", "w", stdout);
  std::ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) { 
    cin >> W >> H;
    for (int x = 0; x <= W; x++) {
      for (int y = 0; y <= H; y++) {
        a[x][y] = 0;
      }
    }
    int B;
    cin >> B;
    for (int i = 0; i < B; ++i) {
      int x0, y0, x1, y1;
      cin >> x0 >> y0 >> x1 >> y1;
      for (int x = x0; x <= x1; x++) {
        for (int y = y0; y <= y1; y++) {
          a[x][y] = 1;
        }
      }
    }
    int res = 0;
    for (int i = 0; i < W; ++i) {
      if (go(i, 0, 0))
        res++;
    }
    cout << "Case #" << t << ": ";
    cout << res << "\n";
  }
}
