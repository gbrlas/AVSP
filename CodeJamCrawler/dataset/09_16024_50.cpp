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
#define SZ(X) (int)X.size()
typedef long long ll;

int main() {
  freopen(PROBLEM".in", "r", stdin);
  freopen(PROBLEM".out", "w", stdout);
  int N;
  cin >> N;
  for(int test = 1; test <= N; test++) {
    string x;
    cin >> x;
    ll cw = 0;
    map<char,ll> w;
    w[x[0]] = 1;
    for(int i = 1; i < x.length(); i++) {
      if(w.find(x[i]) == w.end()) {
        w[x[i]] = cw;
        if(cw == 0) cw += 2; else cw++;
      }
    }
    ll base = (ll)w.size();
    if(base < 2) base = 2;
    ll ans=0,p = 1;
    for(int i = x.length()-1;i>=0;i--,p*=base) {
      ans += w[x[i]] * p;
    }
    cout << "Case #" << test << ": " << ans << endl;
  }
  return 0;
}
