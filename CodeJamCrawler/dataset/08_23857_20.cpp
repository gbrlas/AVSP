#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define GI ({int _; scanf("%d", &_); _;})
#define X first
#define Y second
#define pb push_back
#define INF (INT_MAX)
#define REP(i,n) for(int i = 0; i < n; ++i)
#define FOR(i, s, e) for(int i = s; i < e; ++i)
#define cs c_str()

typedef long long ll;
typedef pair<int,int> ipair;


string encode(string t, vector<int> perm) {
  string ret = t;
  int s = perm.size();
  for(int i = 0; i < t.size(); i ++) 
    ret[i] = t[i / s * s + perm[i%s]];
    
  return ret;
}

int len(string s) {
  string::iterator end = unique(s.begin(), s.end());
  return end - s.begin();
}

void solve() {
  static int kase = 0; ++kase;
  int k = GI; string s;
  vector<int> p;
  REP(i, k) p.pb(i);
  cin >> s;
  
  int ans = INF;
  do {
    string temp = encode(s, p);
    ans = min(ans, len(temp));
  }while(next_permutation(p.begin(), p.end()));
  
  printf("Case #%d: %d\n", kase, ans);
}

int main() {
  int t = GI; while(t--) solve();
  return 0;
}