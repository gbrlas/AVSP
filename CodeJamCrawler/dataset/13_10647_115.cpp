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

using namespace std;

int b[128][128];

int main() {
  int tt, m, n;
  
  cin>>tt;
  for(int t = 1; t <= tt; ++t) {
    cin>>n>>m;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
        cin>>b[i][j];
      }
    }
    bool ok = true;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
        int v = b[i][j];
          // vertical
        bool c = true, d = true;
        for(int k = 0; k < n; ++k) {
          if(b[k][j] > v) {
            c = false;
            break;
          }
        }
          // Horizontal
        for(int k = 0; k < m; ++k) {
          if(b[i][k] > v) {
            d = false;
          }
        }
        if(!c && !d) {
          ok = false;
          break;
        }
      }
    }
    string res = ok ? "YES" : "NO";
    cout << "Case #" << t << ": " << res << endl;
  }
  return 0;
}
