#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define PROBLEM "A"
int main() {
  freopen(PROBLEM".in", "r", stdin);
  freopen(PROBLEM".out", "w", stdout);
  int N;
  cin >> N;
  for(int test = 1; test <= N; test++) {
    int t;
    string ans = "";
    cin >> t;
    int a[21], c=0;
    while(t) {
      a[c++] = t % 10;
      t/=10;
    }
    reverse(a, a + c);
    bool f = next_permutation(a, a+c);
    if(!f) {
      a[c++] = 0;
      sort(a, a + c);
      int j = 1;
      while(!a[0]) {
        swap(a[0], a[j]);
        j++;
      }
    }
      for(int i = 0; i < c; i++) {
        ans += (a[i] + '0');
      }
    cout << "Case #" << test << ": " << ans << endl;
  }
  return 0;
}
