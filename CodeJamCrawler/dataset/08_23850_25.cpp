#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>

using namespace std;

#define INF (INT_MAX)
#define REP(i,n) for(int i = 0; i < n; i ++)
#define FOR(i,s,n) for(int i = s; i < n; i ++)
#define pb push_back
#define X first
#define Y second
#define GI ({int _; scanf("%d", &_); _;})

int prime[1000+1];

void fill() {
  memset(prime, 1, sizeof(prime));
  prime[0] = prime[1] = 0;
  
  FOR(i, 2, 1001) {
    if(prime[i])
      for(int j = i*i; j <= 1000; j+= i)
        prime[j] = 0;
  }
  
}

int p;
bool ok(int a, int b) {
  for(int x = p; x <= min(a, b); x++) {
    if(prime[x]) 
      if(a % x == 0 and b % x == 0)
        return true;
  }
  return false;
}

void solve() {
  static int kase = 0; ++kase;
  int ans = 0;
  int Set[1001]; 
  
  REP(i, 1001) Set[i] = i;
  int a, b;
  cin >> a >> b >> p;
  
  set<int> s;
  
  for(int i = a; i <= b; i ++) {
    for(int j = i + 1; j <= b; j ++) {
      if(ok (i, j)) {
        int setj = Set[j];
        for(int k = a; k <= b; k++) 
          if(Set[k] == setj)
            Set[k] = Set[i];
      }
    }
  }
  
  for(int i = a; i <= b; i ++) {
    s.insert(Set[i]);
  }
  printf("Case #%d: %d\n", kase, s.size());
}

int main() {
  int t = GI;fill();
  while(t--) solve();
}